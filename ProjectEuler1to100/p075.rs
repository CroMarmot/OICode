use std::thread;
use std::sync::mpsc;
use std::collections::HashMap;

const N:usize = 1_500_000;

fn gcd(v1:usize,v2:usize) -> usize{
    return if v2 == 0 {v1} else{gcd(v2,v1%v2)}
}

fn f(n:usize) -> HashMap<usize,usize>{
    let mut m = n+1;
    let mut ret = HashMap::new();
    while 2*m*(m+n) <= N{
        if gcd(m*m-n*n,2*m*n) == 1 {
            println!("{},{},{} => {}",m*m-n*n,2*m*n,m*m+n*n,2*m*(m+n));
            let l = 2*m*(m+n);
            let mut kl = l;
            while kl <= N{
                ret.insert(kl, match ret.get(&kl) {
                    Some(oldcnt) => oldcnt+1,
                    None => 1
                });
                kl+=l;
            }
        }
        m+=1;
    }
    return ret;
}


fn main() {
    let (tx, rx) = mpsc::channel();
    let maxn = 1000; // N+1
    thread::spawn(move || {
        for i in 1..maxn{
            let tx_clone = mpsc::Sender::clone(&tx) ; // <--------------
            thread::spawn(move || {
                tx_clone.send( f(i) ).unwrap();
            });
        }
    });
    let mut hash_res = HashMap::new();
    for _i in 1..maxn {
        let rxr = rx.recv().unwrap();
        for (k,v) in rxr{
            hash_res.insert(k,match hash_res.get(&k){
                Some(oldv) => oldv+v,
                None => v
            });
        }
    }
    let mut ans = 0;
    for (_k,v) in hash_res{
        if v == 1{
            ans += 1;
        }
    }
    println!("ans:{}",ans);
}


/*
sum: 8890
sum: 18034
sum: 27312
sum: 36418
sum: 45592
sum: 54426
sum: 63332
sum: 72690
sum: 81804
sum: 90680
sum: 99974
sum: 109436
sum: 118632
sum: 127950
sum: 137108
sum: 146004
sum: 155244
sum: 164198
sum: 173224
sum: 182266
sum: 191706
sum: 200268
sum: 210078
sum: 218628
sum: 227616
sum: 236602
sum: 245728
sum: 254644
 * */
