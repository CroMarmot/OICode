#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=a;i<n;i++)
const double pi = acos(-1.0);

// bit 翻转
int rev(int x, int len) {
  int ans = 0;
  while(len -- ){
    ans <<= 1;
    ans |= x & 1;
    x >>= 1;
  }
  return ans;
}

int getlog2(int n){
  return 31 - __builtin_clz(n);
}

void FFT(vector<complex<double> > &A, int flag = 1/* 1:FFT,-1:IFFT */) {
  int n = A.size();
  if(n == 1) return ;
  assert((n & (n-1)) == 0); // 2 的幂次
  int lgn = getlog2(n);
  // 相当于 上面 多次递归每个位置放到的最终位置, 直接计算位置, 而神奇的是刚好 位置 = 原位置的按照长度lgn的bit翻转
  rep(i, 0, n) {
    int j = rev(i, lgn);
    if (j > i) swap(A[i], A[j]);
  }
  // 逻辑和递归里一样了, 区别是 这里不像递归里下标连续, 需要计算下标, 好在还是顺序的
  rep(pwr, 0, lgn){
    int m = 1 << pwr;
    complex<double> Wm(cos(pi / m), -sin(pi / m) * flag);
    for (int k = 0; k < n; k += (m<<1)) {
      complex<double> W(1, 0);
      rep(j, 0, m) {
        auto U = A[k + j];
        auto T = W * A[k + j + m];
        A[k + j] = U + T;
        A[k + j + m] = U - T;
        W *= Wm;
      }
    }
  }
  // 内置 / N
  if(flag == -1) rep(i,0,n) A[i] /= n;
}

void IFFT(vector<complex<double> > &A) { FFT(A,-1);}

int main(){
  // 123*456 = 56088
  const int SIZE = 8; // 一定要是2的幂次
  auto a = vector<complex<double> >{3,2,1,0,0,0,0,0};
  auto b = vector<complex<double> >{6,5,4,0,0,0,0,0};
  FFT(a);
  FFT(b);
  auto c = vector<complex<double> >(SIZE,0);
  rep(i,0,SIZE) c[i] = a[i] * b[i];
  IFFT(c);
  // print
  rep(i,0,SIZE) printf("(%.3lf,%.3lf)", c[i].real(), c[i].imag());
  printf("\n");
  rep(i,0,SIZE-1) { // 进位
    c[i+1] += int(c[i].real() / 10);
    c[i] -= int(c[i].real() / 10) * 10;
  }
  rep(i,0,SIZE) printf("(%d)", int(c[i].real()));
  printf("\n");
  return 0;
}
