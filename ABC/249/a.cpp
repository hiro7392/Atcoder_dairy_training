#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

int main(){
    int a,b,c,d,e,f,x;
    cin>>a>>b>>c>>d>>e>>f>>x;
    int time=0;
    int taka=0,aoki=0;
    int takaCycle=a+c;
    int aokiCycle=d+f;
    int takaSpeed[takaCycle],aokiSpeed[aokiCycle];
    rep(i,takaCycle){
        if(i<a)takaSpeed[i]=b;
        else{
            takaSpeed[i]=0;
        }
    }

    rep(i,aokiCycle){
        if(i<d)aokiSpeed[i]=e;
        else{
            aokiSpeed[i]=0;
        }
    }

    while(time<x){

        taka+=takaSpeed[time%takaCycle];
        aoki+=aokiSpeed[time%aokiCycle];

        time++;
    }   
    if(taka>aoki){
        cout<<"Takahashi"<<endl;
    }else if(aoki>taka){
        cout<<"Aoki"<<endl;
    }else{
        cout<<"Draw"<<endl;
    }

    return 0;
}
/*


*/
