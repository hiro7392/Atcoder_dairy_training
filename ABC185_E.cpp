#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

long long GCD(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    else return GCD(b, a % b);
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//dp[i][k]:=Aが先頭i文字だけでBが先頭k文字だけみた時の答え
long long dp[1010][1010];

#define debug 0
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long>a(n+1);
    vector<long long>b(m+1);
    rep2(i,n)cin>>a[i];
    rep2(i,m)cin>>b[i];

    rep2(i,n)rep2(k,m)dp[i][k]=INF;

    rep(i,n+1)dp[i][0]=i;
    rep(k,m+1)dp[0][k]=k;

    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            
            dp[i][k]=min(dp[i-1][k]+1,dp[i][k]);

            dp[i][k]=min(dp[i][k-1]+1,dp[i][k]);
            int tmp=1;
            if(a[i]==b[k])tmp=0;
            
            //int tmp=(a[i]!=b[k]);
            dp[i][k]=min(dp[i-1][k-1]+tmp,dp[i][k]);
        }
    }
#if debug
    rep2(i,m){
        rep2(k,n){
            cout<<dp[k][i]<<" ";
        }
        cout<<endl;
    }
#endif
    cout<<dp[n][m]<<endl;

    
}
/*


*/
