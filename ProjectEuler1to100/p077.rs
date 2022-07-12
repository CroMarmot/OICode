const N:usize = 1_000_000;
use std::cmp;


// dp[n][x] + (n-x <= x?) + sum(dp[n-x][1 -> min(x,n-x-1)])


fn main() {
    let mut prime = vec![0;N+1];
    prime[1] = 1;
    for i in 2..N+1{
        if prime[i] != 0 {
            continue;
        }
        for j in i..N+1{
            if (j as i64)*(i as i64) > (N as i64) {
                break;
            }
            prime[i*j] = 1;
        }
    }
        println!("?");
    let mut dp = Vec::new();
    for _i in 0..2{
        dp.push(Vec::new());
    }
    let mut i = 2;
    loop {
        dp.push(Vec::new());
        dp[i].push(0);
        let mut cnt = 0;
        for j in 1..i {
            dp[i].push(0);
            if prime[j] == 1 {
                continue;
            }
            if j >= i-j && prime[i-j] == 0{
                dp[i][j] += 1;
            }
            for k in 1..cmp::min(j+1,i-j){
                dp[i][j] += dp[i-j][k];
            }
            cnt += dp[i][j];
        }
        println!("{} => {}",i,cnt);
        if cnt > 5000 {
            println!("ans:{}",i);
            return ;
        }
        i+=1;
    }

}

