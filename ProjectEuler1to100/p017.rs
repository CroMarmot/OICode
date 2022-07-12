
fn main() {
    let mut arr:[usize;100] = [0;100];
    arr[1] = "one".len();
    arr[2] = "two".len();
    arr[3] = "three".len();
    arr[4] = "four".len();
    arr[5] = "five".len();
    arr[6] = "six".len();
    arr[7] = "seven".len();
    arr[8] = "eight".len();
    arr[9] = "nine".len();
    arr[10] = "ten".len();
    arr[11] = "eleven".len();
    arr[12] = "twelve".len();
    arr[13] = "thirteen".len();
    arr[14] = "fourteen".len();
    arr[15] = "fifteen".len();
    arr[16] = "sixteen".len();
    arr[17] = "seventeen".len();
    arr[18] = "eighteen".len();
    arr[19] = "nineteen".len();
    arr[20] = "twenty".len();
    arr[30] = "thirty".len();
    arr[40] = "forty".len();
    arr[50] = "fifty".len();
    arr[60] = "sixty".len();
    arr[70] = "seventy".len();
    arr[80] = "eighty".len();
    arr[90] = "ninety".len();
    let mut ans = 0;
    // arr[1]+"thousand".len(); // one thousand
    for i in 1..1000{
        if i >= 100{
            ans+=arr[i/100]+"hundred".len(); // x hundred
            if i%100 != 0{
                ans+="and".len();// 'and'
            }
        }
        let v = i %100;
        if v <= 20{
            ans += arr[v];
        }else{
            ans += arr[(v/10)*10]+arr[v%10];
        }
    }
    ans += arr[1]+"thousand".len(); // one thousand
    println!("{} ",ans);
}
