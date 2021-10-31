//#include "structDef.hpp"


void step4(long long menuNum){
    vector<OrderDish>DishToServe;
    //テーブルごとの注文料金の合計
    vector<long long > ChargeOfTable(10010,0);
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

        string case1="received";
        string case2="ready";
        string case3="check";
        if(sameString(case1,order)){
            //received orderがきたとき
            string str;
            cin>>str;
            long long tableNumber,dishNumber;
            cin>>tableNumber>>dishNumber;
            DishToServe.push_back(OrderDish(tableNumber,dishNumber));
            //テーブルごとの料金を追加
            ChargeOfTable[tableNumber]+=menu[dishNumber].price;
        }else if(sameString(case2,order)){
            long long tableNumber,dishNumber;
            cin>>tableNumber>>dishNumber;
            //待機リストから削除
            for(int i=0;i<DishToServe.size();i++){
                if(DishToServe[i].dishNumber==dishNumber){
                    DishToServe.erase(DishToServe.begin()+i);
                    break;
                }
            }
        }else if(sameString(case3,order)){
            long long tableNumber;
            cin>>tableNumber;
            bool allServed=true;
            //待機リストにまだ運ぶべき料理がないか確認
            for(int i=0;i<DishToServe.size();i++){
                if(DishToServe[i].tableNumber==tableNumber){
                    allServed=false;
                    break;
                }
            }
            if(allServed){  
                printf("%d\n",ChargeOfTable[tableNumber]);
                ChargeOfTable[tableNumber]=0;
            }else{
                printf("please wait\n");
            }
        }
    }
}
