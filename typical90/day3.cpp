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

vector<vector<int> >edge(100010);

pair<int,int> dfs(int now,int before,int dist){

    int ret=dist;
    int node=now;
    for(auto nx:edge[now]){
        if(nx==before)continue;
        else{
            auto tmp=dfs(nx,now,dist+1);
            if(ret<tmp.first){
                ret=tmp.first;
                node=tmp.second;
            }
            //ret=max(ret,dfs(nx,now,dist+1).first);
        }
    }
    return make_pair(ret,node);
}

int main(){
    int n;
    cin>>n;
    int a,b;

    rep(i,n-1){
        cin>>a>>b;
        a--,b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int start=0;
    
    int next=dfs(start,-1,0).second;
#if debug
    cout<<"next "<<next<<endl;
#endif
    cout<<dfs(next,-1,0).first+1<<endl;


    return 0;
}
/*
5
1 2
2 3
3 4
3 5

*/
