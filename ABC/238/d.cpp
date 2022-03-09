#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

/*
aとsの大きさに注意して
((s-2a)&a) ==0を満たすならOK

*/

int main(){
    int t;
    cin>>t;

    rep(i,t){
        long long a,s;
        cin>>a>>s;
        if(s<2*a){
            cout<<"No"<<endl;
        }else if(((s-2*a)&a)==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}
/*


*/
