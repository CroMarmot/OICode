// https://oeis.org/A000041

fn main() {
    let mut ans = Vec::new();
    let modnum:i32 = 1_000_000; // 注意usize范围很小 大坑
    ans.push(1);
    let mut i = 1;
    loop{
        let mut ansi:i32 = 0;

        let mut s:i32 = 1;
        let mut sres = ( s*(3*s-1)/2 ) as usize;
        while sres <= i{
            ansi += ((s%2)*2-1) * ans[i - sres];
            ansi %= modnum;
            s+=1;
            sres = ( s*(3*s-1)/2 ) as usize;
        }

        s = 1;
        sres = (s*(3*s+1)/2) as usize;
        while sres <= i{
            ansi += ((s%2)*2-1) * ans[i - sres];
            ansi %= modnum;
            s+=1;
            sres = (s*(3*s+1)/2) as usize;
        }
        ansi+=modnum;
        ansi%=modnum;

        ans.push(ansi);
        println!("{}=>{}",i,ansi);
        if ansi == 0 {
            println!("ans :{}",i);
            return ;
        }
        i+=1;
    }
}

