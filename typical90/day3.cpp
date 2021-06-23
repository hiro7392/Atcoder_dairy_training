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

vector<vector<int>>edge(100010);


int dfs(int st,int now, int dist,int before){
    
    if(now==start)return dist;

    int ret=answer;
    for(auto next:edge[now]){
        if(next==before)continue;

        answer=dfs(st,next,dist+1,now);
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    
    

    vector<long long>vec(1,1000);//(サイズ,要素の中身)

    //初期化
    vector<vector<long long>>dist(n+1,vector<long long>(n+1,INF));

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        //dist[a][b]=dist[b][a]=1;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }




    //ワーシャルフロイドで最短経路を求める
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++){
                if(i==j || k==j)continue;
                dist[i][k]=min(dist[i][k],dist[i][j]+dist[j][k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int k=1;i<=n;k++){
            //cout<<dist[i][k]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
/*
5
1 2
2 3
3 4
3 5

*/
