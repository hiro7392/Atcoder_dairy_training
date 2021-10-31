#pragma once
//#include "structDef.hpp"




struct Kitchin{
    Kitchin(){};
    Kitchin(long long rangeNum):rengeNums(rangeNum){};

    public:
    //注文待ちリスト
    queue<OrderDish> waitQueue;
    //現在のレンジ
    vector<OrderDish>renges;
    long long rengeNums;

};

//注文を順番にレンジで調理
void step2(long long menuNum,long long rengeNum){
    Kitchin kitchin(rengeNum);
    //メニュー情報を入力
    for(int i=0;i<menuNum;i++){
        long long dishNumber,stock,price;
        cin>>dishNumber>>stock>>price;
        menu[dishNumber]=Dish(stock,price);
    }
    
    //入力が終わるまで
    while(!cin.eof()){
        string order="waitOrder";
        cin>>order;
        if(order[0]=='w')break;
        //if(order==waitOrder"")break;
        // long long tableNumber,dishNumber,orderNums;
        // cin>>tableNumber>>dishNumber>>orderNums;
        
        if(order[0]=='r'){
            //received orderがきたとき
            string str;
            cin>>str;
            long long tableNumber,dishNumber;
            cin>>tableNumber>>dishNumber;
            OrderDish orderInfo(tableNumber,dishNumber);

            if(kitchin.renges.size()<kitchin.rengeNums){
                //レンジに空きがある時
                kitchin.renges.push_back(orderInfo);
                printf("%d\n",orderInfo.dishNumber);
            }else{//レンジに空きがないとき
                kitchin.waitQueue.push(orderInfo);
                printf("wait\n");
            }
        }else if(order[0]=='c'){
            //complete 料理番号がきたとき
            long long dishNumber;
            cin>>dishNumber;
            bool findDish=false;
            for(int i=0;i<kitchin.renges.size();i++){
                //該当する料理が調理中のとき
                if(kitchin.renges[i].dishNumber==dishNumber){
                    printf("ok ");
                    //rengeから要素を削除
                    kitchin.renges.erase(kitchin.renges.begin()+i);
                    //注文待ちテーブルから料理をとってくる
                    if(kitchin.waitQueue.size()){
                        OrderDish next=kitchin.waitQueue.front();
                        kitchin.waitQueue.pop();
                        kitchin.renges.push_back(next);
                        printf("%d",next.dishNumber);
                    }
                    printf("\n");
                    findDish=true;
                    break;
                }
            }
            //一致する料理番号がレンジになかった時
            if(!findDish){
                printf("unexpected input\n");
            }

        }
    }
    return;
}
