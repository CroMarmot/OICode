
fn main() {
    let mut days = 1;
    let mut years = 1900;
    let months = [31,28,31,30,31,30,31,31,30,31,30,31];
    let mut sundays=0;
    while years < 2001 {
        for i in 0..12{
            days += months[i];
            if i==1 && years%4==0 { // 1901->2000 只用mod4即可
                days+=1;
            }
            if days%7==0 && years>=1901 {
                sundays+=1;
            }
        }
        years+=1;
    }
    println!("{} ",sundays);
}
