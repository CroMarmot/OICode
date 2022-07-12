const N:usize = 1_000_000;

fn prime(p:&mut [usize]) {
    for i in 2..N+1 {
        if p[i] != 0 {
            continue ;
        }
        if i*i > N {
            return ;
        }
        for j in i..N+1 {
            if j*i > N {
                break;
            }
            p[j*i] = i;
        }
    }
}

fn phi_n(p:&[usize], v:usize) -> usize {
    let mut ps = Vec::new();
    let mut vv = v;
    while p[vv] != 0 {
        let pr = p[vv];
        ps.push(pr);
        while vv % pr == 0 {
            vv/=pr;
        }
    }
    if vv != 1 {
        ps.push(vv);
    }
    let mut cnt = v as i32;
    for i in 1..(1<<ps.len()) {
        let mut mulres = 1;
        let mut bitcnt = 1;
        for j in 0..ps.len() {
            if i & (1<<j) != 0 {
                mulres *= ps[j];
                bitcnt *= -1;
            }
        }
        cnt += bitcnt*((v/mulres)as i32);
    }
    return cnt as usize;
}

fn main() {
    let mut arr = vec![0 as usize; N+10];
    prime(&mut arr);
    println!("finish prime");
    let mut ans = 0;
    for i in 2..N+1 {
        let ret = phi_n(&arr, i);
        ans += ret as i64;
    }
    println!("{}",ans);
}

