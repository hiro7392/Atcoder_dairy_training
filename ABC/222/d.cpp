#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

const long long MOD=998244353;
int main(){
    
    long long n;
    cin>>n;

    long long dp[3010][3010]={};

    long long a[n],b[n];
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];

    for(int i=a[0];i<=b[0];i++)dp[i][0]=1;
    rep2(i,n-1){

        long long sum=0;
        rep(k,b[i]+1){
            sum+=dp[k][i-1];
            sum%=MOD;
            if(k<a[i])continue;
            else{
                dp[k][i]=sum;
            }
        }
    }
    long long ans=0;
    rep(i,b[n-1]+1){
        ans+=dp[i][n-1];
        ans%=MOD;
    }
    // rep(i,n){
    //     rep(k,b[i]+1){
    //         cout<<dp[k][i]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<endl;
}
/*
978222082

978222082

*/
