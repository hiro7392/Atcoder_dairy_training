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

long long getSum(vector<vector<int>>& blocks,int ha,int ka,
vector<long long>& xSum,vector<long long>& ySum){
    return xSum[ha]+ySum[ka]-blocks[ha][ka];
}


int main(){
    
    int h,w;
    cin>>h>>w;

    //int blocks[h+1][w+1];
    vector<vector<int>>blocks(h,vector<int>(w));
    vector<long long>xSum(h,0);
    vector<long long>ySum(w,0);
    for(int i=0;i<h;i++){
        for(int k=0;k<w;k++){
            cin>>blocks[i][k];
            xSum[i]+=blocks[i][k];
        }
    }
    for(int i=0;i<h;i++){
        for(int k=0;k<w;k++){
            ySum[k]+=blocks[i][k];
        }
    }

    vector<vector<int>>ans(h,vector<int>(w));
    

    for(int i=0;i<h;i++){
        for(int k=0;k<w;k++){
            ans[i][k]=getSum(blocks,i,k,xSum,ySum);
            cout<<ans[i][k]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
/*
5

*/
