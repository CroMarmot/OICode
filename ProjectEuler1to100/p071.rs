const N:i64 = 1_000_000;

fn gcd(a:i64,b:i64) -> i64{
    if b==0 {a}else{gcd(b,a%b)}
}

fn main() {
    let mut near = (2,5);
    for i in 9..N+1 {
        let mut fz = 3*i/7;
        while gcd(fz,i) != 1 {
            fz -= 1;
        }
        if fz*near.1 > i*near.0 {
            near= (fz,i);
        }
    }
    println!("{}/{}",near.0,near.1);
}

