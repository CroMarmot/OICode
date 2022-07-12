const N:usize = 100;
use std::cmp;


// dp[n][x] + (n-x <= x?) + sum(dp[n-x][1 -> min(x,n-x-1)])


fn main() {
    let mut dp = [[0; N+1]; N+1];
    for i in 2..N+1{
        for j in 1..i {
            if j >= i-j {
                dp[i][j] += 1;
            }
            for k in 1..cmp::min(j+1,i-j){
                dp[i][j] += dp[i-j][k];
            }
        }
    }

    let mut ans = 0;
    for i in 1..N {
        ans += dp[N][i];
    }
    println!("ans:{}",ans);
}

