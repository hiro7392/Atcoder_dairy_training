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

*/
int main(){
    
    int n;
    cin>>n;
    string s;
    cin>>s;

    string want="atcoder";
    long long sum[n][7]={};
    rep(i,n){
        if(s[i]==want[0]){
            sum[i][0]=1;
        }
    }
    rep2(i,n-1){
        rep(k,want.size()){
            sum[i][k]+=sum[i-1][k];
            sum[i][k]%=mod;
            if(s[i]==want[k] && k>0){
                sum[i][k]+=sum[i][k-1];
                sum[i][k]%=mod;
            }
        }
    }
#if debug
    rep(k,7){
        rep(i,n){
            cout<<sum[i][k]<<" ";
        }
        cout<<endl;
    }
#endif
    long long ans=0;
    // rep(i,n){
    //     ans+=sum[i][6];
    //     ans%=mod;
    // }
    cout<<sum[n-1][6]<<endl;
    
}
/*


*/
