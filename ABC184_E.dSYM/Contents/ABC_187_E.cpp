#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;
#define debug 0
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

bool cmp(pair<long long,int>x,pair<long long,int>y){
    return x.first>y.first;
}
vector<pair<int,int>>edge;
//各頂点からの行き先
vector<vector<int>> v;
//pair<long long,long long>c[200010];
pair<long long,long long>z[200010];
vector<int>depth;
vector<long long>dp;
//深さを求めるDFS
void DepthDFS(int a,int d){
    depth[a]=d;
    for(int next:v[a]){
        if(depth[next]==-1){
            DepthDFS(next,d+1);
        }
    }
}

void ImosDFS(int a,long long now){
    now+=dp[a];
    dp[a]=now;
    for(int next:v[a]){
        if(depth[next]>depth[a]){
            ImosDFS(next,now);
        }
    }
}
int main(){
    int n;
    cin>>n;

    v.resize(n);
    edge.resize(n);
    depth.resize(n,-1);
    dp.resize(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        edge[i]=make_pair(a,b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DepthDFS(0,0);
    

    int q;
    cin>>q;

    rep(i,q){
        long long t,e,x;
        cin>>t>>e>>x;
        e--;
        //va:=通る方,vb:=通らない方
        int va,vb;
        if(t==1){
            va=edge[e].first;
            vb=edge[e].second;
        }
        //左から右
        else{
            va=edge[e].second;
            vb=edge[e].first;
        }
        //通る方が深い位置にある時
        if(depth[va]<depth[vb]){    
            //根にたす
            dp[0]+=x;
            //子孫から引く
            dp[vb]-=x;
        }
        else{
            dp[va]+=x;
        }
    }
    ImosDFS(0,0);
    
    rep(i,n)cout<<dp[i]<<endl;
    
}
/*
5
1 2
2 3
2 4
4 5
4
1 1 1
1 4 10
2 1 100
2 2 1000

output
11
110
1110
110
100

input
7
2 1
2 3
4 2
4 5
6 1
3 7
7
2 2 1
1 3 2
2 2 4
1 6 8
1 3 16
2 4 32
2 1 64

output
72
8
13
26
58
72
5

input
11
2 1
1 3
3 4
5 2
1 6
1 7
5 8
3 9
3 10
11 4
10
2 6 688
1 10 856
1 8 680
1 8 182
2 2 452
2 4 183
2 6 518
1 3 612
2 6 339
2 3 206

output
1657
1657
2109
1703
1474
1657
3202
1474
1247
2109
2559



*/
