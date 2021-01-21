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


//最小全域木(最小でなくてもいい)を求める
// 素集合データ構造
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};



 //<<始点,終点>,辺番号>
vector<int>color;                   //各ノードの色
vector<vector<pair<int,int>>>tree;//最小全域tree[i]:=<行き先,辺番号>
vector<pair<pair<int,int>,int>>edge; //<<始点,終点>,辺番号>


void dfs(int now,int n){
    set<int>key;
    if(color[now]==-1){
        for(auto nx:tree[now]){
            
                key.emplace(nx.second);
            
        }
        rep(i,n){
            if(key.find(i)==key.end()){
                color[now]=i;
                break;
            }
        }
    }
    for(auto nx:tree[now]){
        if(color[nx.first]!=-1)continue;

        else{
            //printf("checked!\n");
            //親の番号が辺の番号と違う時
            if(color[now]!=nx.second){
                color[nx.first]=nx.second;
            }
            //親の番号が辺と同じ時 あとで決める
            dfs(nx.first,n);
        }
    }
    return;
}

int main(){
    
    int n, m;
    cin>>n>>m;
    
    color.resize(n,-1);
    tree.resize(n);
    rep(i,m){
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--,c--;
        edge.push_back(make_pair(make_pair(u,v),c));
    }
    //printf("pppp\n");
    UnionFind uf(n);
    int cnt=0;
    
    for(int k=0;k<m;k++){
        auto nx=edge[k];
        int a=nx.first.first;
        int b=nx.first.second;
        int c=nx.second;
        //cout<<"edge :"<<a<<" "<<b<<endl;
        if(uf.same(a,b)){
            continue;
        }
        else{
            uf.unite(a,b);
            tree[a].push_back(make_pair(b,c));
            tree[b].push_back(make_pair(a,c));
            cnt++;
            //cout<<"edge :"<<a<<" "<<b<<endl;
            //if(cnt==n-1)break;
        }
    }
    
    

    dfs(0,n);


    rep(i,n)cout<<color[i]+1<<endl;
}
/*
3 4
1 2 1
2 3 2
3 1 3
1 3 1


1
2
1

*/
