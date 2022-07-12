#include<vector>
using namespace std;
// define your struct and compare methods
struct MyStruct{
  bool operator < (const MyStruct& o) const{
    return true;
  }
  bool operator == (const MyStruct& o) const{
    return true;
  }
  bool operator > (const MyStruct& o) const{
    return true;
  }
};

template<typename T>
int binarySearch(vector<T> &array,T value){
  int l = 0, r = array.size () - 1;
  while ( l <= r ){
    int mid = ( l + r )/2;
    T midval = array[mid];
    if ( midval == value )
      return mid;
    else if ( midval > value )
      r = mid - 1;
    else if ( midval < value )
      l = mid + 1;
  }
  return -1;
}
