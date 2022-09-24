#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0
 
bool cmp(pair<long long,int>p1,pair<long long,int>p2){
    return p1.first<p2.first;
}

int main(){
     int x,y,z;
     cin>>x>>y>>z;
     // 同じ側にある場合
     if(x*y>=0 && abs(y)>abs(x)){
         cout<<abs(x)<<endl;
     }else if(x*y>=0 && abs(y)<=abs(x)){
        if(abs(z)>abs(y)){
            cout<<"-1"<<endl;
        }else if(z*y>0){
            cout<<abs(x)<<endl;
        }else{
            cout<<abs(z)*2+abs(x)<<endl;
        }
     }else if(x*y<0){
        // 逆側にある場合
        cout<<abs(x)<<endl;
     }else{
        cout<<"-1"<<endl;
     }
}
/*


*/
