
//#include "structDef.hpp"


void step1(long long menuNum){
    for(int i=0;i<menuNum;i++){
        long long dishNumber,stock,price;
        cin>>dishNumber>>stock>>price;
        menu[dishNumber]=Dish(stock,price);
    }
    while(!cin.eof()){
        string order="waitOrder";
        cin>>order;
        if(order[0]=='w')break;
        //if(order==waitOrder"")break;
        long long tableNumber,dishNumber,orderNums;
        cin>>tableNumber>>dishNumber>>orderNums;

        //在庫数が注文すう未満の場合
        if(orderNums>menu[dishNumber].stock){
            printf("sold out %d\n",tableNumber);
        }else{
            for(int i=0;i<orderNums;i++)printf("received order %d %d\n",tableNumber,dishNumber);
            menu[dishNumber].stock-=orderNums;
        }
    }
    return;
}