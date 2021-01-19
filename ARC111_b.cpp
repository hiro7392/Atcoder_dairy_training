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
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> size;
    UnionFind(int N) : par(N),size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
            size[i]=1;
        }
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
        size[ry]+=size[rx];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int getSize(int x){
        return size[x];
    }
};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

vector<bool>reached;
vector<vector<int>>edge;
bool check_tree_dfs(int now,int before){
    reached[now]=true;
    for(auto nx:edge[now]){
        if(nx==before)continue;
        else if(reached[nx])return false;
        if(!check_tree_dfs(nx,now))return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    reached.resize(400010);
    edge.resize(400010);
    UnionFind uf(400010);
    set<int>tree;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        a--,b--;
        tree.emplace(a);
        tree.emplace(b);
        //if(a==b)continue;
        edge[a].push_back(b);
        edge[b].push_back(a);
        uf.unite(a,b);
        

    }
    int ans=0;
    for(auto num:tree){
        int start=uf.root(num);
        if(reached[start])continue;

        if(!check_tree_dfs(start,-1)){
            ans+=uf.getSize(start);
        }
        else{
            ans+=uf.getSize(start)-1;
        }
    }
    cout<<ans<<endl;
}
/*


*/
