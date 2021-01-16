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
    //member_class[i][c]:自分と同じグループに属するクラスcの人数
    vector<vector<int>> member_class;
    UnionFind(int N,vector<int>c) : par(N),member_class(N,vector<int>(N,0)){ //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++){
            par[i] = i;
            member_class[i][c[i]]=1;
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
        sum(rx,ry);
        return;
    }
    //xの親がyになるので、
    //xのグループに所属する各クラスの人数をyにたす
    void sum(int x,int y){
        rep(i,par.size()){
            member_class[y][i]+=member_class[x][i];
        }
        return;
    }
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    //すでに同じグループにいるクラスy所属の人の人数を得る
    void getMember(int x,int y){
        printf("%d\n",member_class[root(x)][y]);
        return;
    }
};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

int main(){
    int n,q;
    cin>>n>>q;

    vector<int>c(n);

    rep(i,n){
        int p;
        cin>>p;
        p--;
        c[i]=p;
    }

    UnionFind uf(n,c);
    rep(i,q){

        int t;
        cin>>t;
        if(t==1){
            int a,b;
            cin>>a>>b;
            a--,b--;
            uf.unite(a,b);
        }
        else{
            int x,y;
            cin>>x>>y;
            x--,y--;
            uf.getMember(x,y);
        }



    }
}
/*


*/
