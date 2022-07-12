use std::collections::HashMap;
const N:usize = 1_000_000;

fn next_value(mut value:usize,fac:&[usize]) -> usize{
    let mut sum = 0;
    while value != 0 {
        sum += fac[value%10];
        value/=10;
    }
    return sum;
}

fn dfs(
    fac:&[usize],
    ans:&mut HashMap<usize,usize>,
    dep:&mut HashMap<usize,usize>,
    value:usize
    ) -> (usize,usize) { // dep, len
    let nv = next_value(value,fac);
    let next_dep = dep.get(&value).unwrap() + 1;
    match dep.get(&nv) {
        Some(rs) => {
            // println!("{} => {}",value,next_dep - rs);
            ans.insert(value,next_dep - rs);
            return (*rs,next_dep - rs);
        },
        None => {
            match ans.get(&nv) {
                Some(res) => {
                    let newres= (*res) + 1;
                    // println!("{} => {}",value,newres);
                    ans.insert(value,newres);
                    return (next_dep,newres);
                },
                None => {
                    dep.insert(nv,next_dep);
                    let mut ret = dfs(fac,ans,dep,nv);
                    if next_dep <= ret.0  {
                        ret.1 += 1;
                    }
                    // println!("{} => {}",value,ret.1);
                    ans.insert(value,ret.1);
                    return ret;
                }
            }
        }
    }
}

fn main() {
    let mut fac = [0;11];
    let mut ans = HashMap::new();
    fac[0] = 1;
    for i in 1..11{
        fac[i] = fac[i-1]*i;
    }
    for i in 1..N+1{
        if ans.contains_key(&i) {
            continue;
        }
        let mut dep = HashMap::new();
        dep.insert(i,0);
        dfs(&fac,&mut ans,&mut dep,i);
    }
    let mut cnt = 0;
    for (k, v) in &ans {
        if *v >= 60 && *k <= N {
            cnt+=1;
            // println!("{}: \"{}\"", k, v);
        }
    }
    println!("{}",cnt);
}

