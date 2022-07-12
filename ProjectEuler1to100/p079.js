/**
 * @class       : p079
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @created     : 星期三 6月 10, 2020 03:07:22 CST
 * @description : p079
 */

let oriarr = [
'319',
'680',
'180',
'690',
'129',
'620',
'762',
'689',
'762',
'318',
'368',
'710',
'720',
'710',
'629',
'168',
'160',
'689',
'716',
'731',
'736',
'729',
'316',
'729',
'729',
'710',
'769',
'290',
'719',
'680',
'318',
'389',
'162',
'289',
'162',
'718',
'729',
'319',
'790',
'680',
'890',
'362',
'319',
'760',
'316',
'729',
'380',
'319',
'728',
'716',
];
let ans = '0'.repeat(oriarr.length*3+1);
console.log(ans)

function f(arr,s='',dep = 0) {
  // console.log(arr,s,dep);
  if(arr.length == 0){
    if( s.length < ans.length ){
      ans = s;
      console.log('ans',ans);
    }
    return s;
  }
  if(s.length > ans.length){
    return ;
  }
  let ret = '';
  for(let i = 0;i<10;i++){
    let newarr = [];
    let find1 = false;
    for(s1 of arr){
      if(s1.startsWith(`${i}`)){
        find1 = true;
        if(s1.length > 1){
          newarr.push(s1.substr(1));
        }
      }else{
        newarr.push(s1);
      }
    }
    if(find1){
      f(newarr,`${s}${i}`,dep + 1);
    }
  }
  return ret;
}


f(oriarr);

/*
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
ans 1231602071020316028090
ans 123160207102031602890
ans 12316020710203162890
ans 1231602071023162890
ans 123160207103162890
ans 12316020713162890
ans 1231602073162890
ans 123160273162890
ans 12316073162890
ans 1231673162890
ans 123173162890
ans 12373162890
ans 1273162890
ans 173162890
ans 73162890
*/
