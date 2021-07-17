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
#define debug 0
long long A[1010][1010];
long long X[1010][1010];  
long long dp[1010][1010];
long long ans=INF;

void solve(long long h,long long w,long long c){

    rep(i,h)rep(k,w)dp[i][k]=INF;
    
    //すでに1つ目の駅を建てていて、(j,i)にいる時は次の3つの場合
    //1.(j,i)に降りて、(j,i)で駅をたてた
    //2. (j-1,i)からコストCを払って移動
    //3  (j,i-1)からコストCを払って移動
    for(int i=0;i<h;i++){
        for(int k=0;k<w;k++){

            dp[i][k]=min(A[i][k],dp[i][k]);

            if(i>0)dp[i][k]=min(dp[i][k],dp[i-1][k]+c);
            if(k>0)dp[i][k]=min(dp[i][k],dp[i][k-1]+c);
        }
    }


    //X[i][j]:=(j,i)から飛び立つ時の最小費用

     

    rep(i,h)rep(k,w)X[i][k]=INF;
    
    
    for(int i=0;i<h;i++){
        for(int k=0;k<w;k++){
            if(i>0)X[i][k]=min(X[i][k],dp[i-1][k]+A[i][k]+c);
            if(k>0)X[i][k]=min(X[i][k],dp[i][k-1]+A[i][k]+c);
        }
    }
    for(int i=0;i<h;i++){
        for(int k=0;k<w;k++){
            ans=min(ans,X[i][k]);
        }
    }
}
int main(){
    
    long long h,w,c;
    cin>>h>>w>>c;

    

    rep(i,h)rep(k,w)cin>>A[i][k];
    //dp[i][k]:=すでに駅を建てていて、(j,i)にいる時の最小費用
    
    solve(h,w,c);

    //左右変換した再度dpを回す
    rep(i,h){
        rep(j,(w+1)/2){
            swap(A[i][j],A[i][w-1-j]);
        }
    }
    solve(h,w,c);

    cout<<ans<<endl;


}
/*
3 4 2
1 7 7 9
9 6 3 7
7 8 6 4

10

3 3 1000000000
1000000 1000000 1
1000000 1000000 1000000
1 1000000 1000000

1001000001

*/
