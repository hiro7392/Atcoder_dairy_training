
#pragma once
//#include "structDef.hpp"

void step3(long long menuNum){

    vector<OrderDish>DishToServe;
    //メニュー情報を入力
    for(int i=0;i<menuNum;i++){
        long long dishNumber,stock,price;
        cin>>dishNumber>>stock>>price;
        menu[dishNumber]=Dish(stock,price);
    }
    
    //入力が終わるまで
    while(!cin.eof()){
        string order="pe";
        cin>>order;
        if(order[0]=='p')break;
        
        
        if(order[0]=='r'){
            //received orderがきたとき
            string str;
            cin>>str;
            long long tableNumber,dishNumber;
            cin>>tableNumber>>dishNumber;
            DishToServe.push_back(OrderDish(tableNumber,dishNumber));
        }else if(order[0]=='c'){
            //complete 料理番号がきたとき
            long long dishNum;
            cin>>dishNum;
            for(int i=0;i<DishToServe.size();i++){
                if(DishToServe[i].dishNumber==dishNum){
                    printf("ready %d %d\n",DishToServe[i].tableNumber,dishNum);
                    DishToServe.erase(DishToServe.begin()+i);
                    break;
                }
            }
        }
    }
    return;
}
