#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

//各料理の情報
struct Dish{
    Dish(){}
    Dish(long long s,long long p) :stock(s),price(p){}
    public:
    long long stock;
    long long price;
};
//注文情報
struct OrderDish{
    OrderDish(){};
    OrderDish(long long t,long long d):tableNumber(t),dishNumber(d){}

    public:
    long long tableNumber;
    long long dishNumber;
};
//メニューが入る配列
//menu[メニュー番号]
vector<Dish> menu(1000010);

//同じ文字列か判定
bool sameString(string a,string b){
    if(a.size()!=b.size())return false;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
