const N:usize = 5;

fn set_v(ans: &mut[usize],idx: &mut usize, vis: &mut[bool], value: usize) {
    ans[*idx] = value;
    vis[value] = true;
    *idx+=1;
}

fn unset_v(idx: &mut usize, vis: &mut[bool], value: usize) {
    *idx -= 1;
    vis[value] = false;
}

fn dfs(mut ans: &mut[usize],mut idx: &mut usize, mut vis: &mut[bool]) {
    if *idx == 2*N {
        for i in 1..N {
            if ans[0]+ans[1]+ans[3] != ans[i*2]+ans[i*2+1]+ans[(i*2+3)%(2*N)] {
                return ;
            }
        }
        let mut mini = 0;
        for i in 0..N {
            if ans[i*2] < ans[mini*2] {
                mini = i;
            }
        }
        for ii in 0..N {
            let i = (ii+mini)%N;
            print!("{}{}{}",ans[i*2],ans[i*2+1],ans[(i*2+3)%(2*N)]);
        }
        println!("");
        return
    }
    for v in (1 as usize..(2*N+1)).rev() {
        // println!("v={}",v);
        if vis[v] {
            continue;
        }
        if *idx >= 5 && *idx % 2 ==1 {
            if ans[0]+ans[1]+ans[3] != ans[*idx-3]+ans[*idx-2]+v {
                continue;
            }
        }
        set_v(&mut ans,&mut idx,&mut vis, v);
        dfs(&mut ans,&mut idx,&mut vis);
        unset_v(&mut idx,&mut vis, v);
    }
}

fn main() {
    let mut arr =[0 as usize;2*N];
    let mut idx = 0;
    let mut vis =[false;2*N+1];
    set_v(&mut arr,&mut idx,&mut vis, 10);
    dfs(&mut arr,&mut idx,&mut vis);
}

