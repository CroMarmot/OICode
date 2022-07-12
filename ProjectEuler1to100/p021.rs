
fn calc(i:i32) -> i32{
    let mut ret = 0;
    for j in 1..i{
        if i%j == 0 {
            ret+=j
        }
    }
    return ret;
}

fn main() {
    let mut ans = 0;
    for i in 1..10001{
        let op = calc(i);
        if op > 0 && op < i{
            if calc(op) == i{
                println!("{} <-> {}",op,i);
                ans+=op;
                ans+=i;
            }
        }
    }
    println!("{} ",ans );
}
