const N:usize = 10_000_000;

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

fn phi_n(p:&[usize], v:usize) -> (bool,usize) {
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
    // print!("{} :",v);
    // for i in &ps {
    //     print!("{} ",i);
    // }
    // println!("");
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

    let mut orivec = Vec::new();
    let mut cori = v;
    while cori != 0{
        orivec.push(cori%10);
        cori /= 10;
    }
    orivec.sort();

    let mut cntvec = Vec::new();
    let mut ccnt = cnt as usize;
    while ccnt != 0{
        cntvec.push(ccnt%10);
        ccnt /= 10;
    }
    cntvec.sort();

    if orivec.len() != cntvec.len() {
        return (false,0);
    }
    for i in 0..orivec.len() {
        if orivec[i] != cntvec[i] {
            return (false,0);
        }
    }
    println!("{} -> {}",v,cnt);

    return (true,cnt as usize);
}

fn main() {
    let mut arr = vec![0 as usize; N+10];
    prime(&mut arr);
    println!("finish prime");
    let mut ans = (2,1);
    for i in 2..N+1 {
        let ret = phi_n(&arr, i);
        if !ret.0 {
            continue;
        }
        if ret.1*ans.0 > i*ans.1 {
            ans = (i,ret.1)
        }
    }
    println!("{:?}",ans);
    println!("{}",ans.0 as f32/ans.1 as f32);
}

