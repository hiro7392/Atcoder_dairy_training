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
    long long n,x;
    cin>>n>>x;

    bool reachable[11010]={};
    reachable[0]=true;
    rep(i,n){
        long long a,b;
        cin>>a>>b;
        for(int k=x+1;k>-1;k--){
            if(reachable[k]){
                reachable[k+a]=reachable[k+b]=true;
                reachable[k]=false;
            }
        }
    }

    if(reachable[x]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
/*


*/
