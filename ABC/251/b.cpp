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
    long long n,w;
    cin>>n>>w;

    long long a[n+1];
    rep(i,n)cin>>a[i];
    a[n]=0;
    bool good[1000005]={};
    rep(i,n+1){
        for(int k=0;k<=n;k++){
            for(int l=0;l<=n;l++){
                if(w<a[i]+a[k]+a[l] || (i==k || k==l | i==l))continue;

                good[a[i]+a[k]+a[l]]=true;
            }
        }
    }
    rep(i,n+1){
        for(int k=0;k<=n;k++){
                if(w<a[i]+a[k] || (i==k))continue;
                
                good[a[i]+a[k]]=true;
        }
    }
    rep(i,n){
        if(w<a[i] )continue;
        good[a[i]]=true;
    }
    long long ans=0;
    rep2(i,1000000){
        if(good[i])ans++;
    }

    cout<<ans<<endl;
    // for(auto i:tree){
    //     cout<<i<<endl;
    // }
    return 0;

}
/*


*/
