#!/usr/bin/env sh

######################################################################
# @author      : cromarmot (yexiaorain@gmail.com)
# @file        : p22
# @created     : 星期日 2月 02, 2020 16:55:41 CST
#
# @description : 
######################################################################

awk -F, '{\
  for(i=1;i<=NF;i++){\
    print substr($i,2,length($i)-2)\
  }\
}' p042_words.txt | sort | awk 'BEGIN{\
  sum = 0
  for(n=0;n<256;n++)
    ord[sprintf("%c",n)]=n
} {\
  chcnt = 0;
  split($0, chars, "")
  for(i=1;i<=length($0);i++){
    chcnt+=ord[chars[i]]-ord["A"]+1;
  }
  s = 0
  for(i=1;;i++){
    s+=i;
    if(s == chcnt){
      sum++;
    }else if(s > chcnt){
      break;
    }
  }
} END {\
  print sum;
}'
