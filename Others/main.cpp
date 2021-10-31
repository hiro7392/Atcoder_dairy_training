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
