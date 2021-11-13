#include "step1.cpp"
#include "step2.cpp"
#include "step3.cpp"
#include "step4.cpp"
#include "structDef.hpp"
;

#define debug 0

int main() {
  int step;
  cin >> step;
  long long menuNum;
  cin >> menuNum;

  // step1 注文を受付
  if (step == 1) {
    step1(menuNum);
  } else if (step == 2) {
    //スタッフに調理する番号を支持する
    long long rengeNum;
    cin >> rengeNum;
    step2(menuNum, rengeNum);

  } else if (step == 3) {
    step3(menuNum);
  } else if (step == 4) {
    step4(menuNum);
  }
}
/*
step1

input

1
2
100 5 700
50 2 300
order 13 100 4
order 12 100 2
order 11 100 1

output
received order 13 100
received order 13 100
received order 13 100
received order 13 100
sold out 12
received order 11 100

step2
input

2
2 2
100 5 700
101 5 300
received order 10 100
complete 101
received order 11 100
received order 12 101
complete 100
complete 101

output

100
unexpected input
100
wait
ok 101
ok

step3

input
3
1
100 5 700
received order 10 100
received order 11 100
complete 100
received order 10 100
complete 100
complete 100

ready 10 100
ready 11 100
ready 10 100

step4
input

4
1
100 5 700
received order 10 100
ready 10 100
check 10
received order 10 100
check 10
ready 10 100
check 10

output

700
please wait
700
*/
