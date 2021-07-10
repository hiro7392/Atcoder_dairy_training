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
struct Edge {
    long long to;
    Edge(long long a){
        to=a;
    }
    
};
using Graph = vector<vector<Edge> >;

/* LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
    query(u,v): u と v の LCA を求める。計算量 O(logn)
    前処理: O(nlogn)時間, O(nlogn)空間
*/
struct LCA {
    vector<vector<int> > parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist;            // root からの距離
    LCA(const Graph &G, int root = 0) { init(G, root); }

    // 初期化
    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e.to != p) dfs(G, e.to, v, d + 1);
        }
    }

    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
    int getDist(int u){
        return dist[u];
    }

    
};
#define debug 0
int main(){
    int n,q;
    cin>>n>>q;

    Graph edge(100010);
    rep(i,n-1){
        long long a,b;
        cin>>a>>b;
        a--,b--;
        Edge A(a);
        Edge B(b);
        edge[a].push_back(B);
        edge[b].push_back(A);
    }
    
    LCA lca(edge);

    rep(i, q){
        int c,d;
        cin>>c>>d;
        c--,d--;
        long long dist;
        int l=lca.query(c,d);
#if debug
        cout<<"(c,d)=("<<c+1<<","<<d+1<<")"<<"dist[c] "<<lca.getDist(c)<<" dist[d] "<<lca.getDist(d)<<" 共通祖先 "<<l<<endl;
#endif
        
            dist=(lca.getDist(c)-lca.getDist(l))+(lca.getDist(d)-lca.getDist(l));
        
#if  debug
    cout<<"dist("<<c+1<<","<<d+1<<")="<<dist<<endl;
#endif
    
        if(dist%2==0){
            cout<<"Town"<<endl;
        }
        else{
            cout<<"Road"<<endl;
        }
        
    }


}
/*

8 4
1 2
2 3
3 4
1 5
5 7
5 8
5 6
2 3
2 5
4 5
4 8



*/
