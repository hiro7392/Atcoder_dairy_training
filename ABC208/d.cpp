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



int main(){
    int n,m;
    cin>>n>>m;

    long long dist[410][410][410];
    rep(i,400)rep(k,400)rep(t,400)dist[i][k][t]=INF;
    
    long long ans=0;

    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        rep(k,n){
            dist[a][b][0]=c;
        }
        ans+=0;
    }

    //dist[s][t][k]:=都市sからk以下の都市を巡って都市tへ移動する最短経路

    //k以下の番号について回る


        //経由する頂点
        for(int j=1;j<n;j++){
            //始点
            rep(s,n){
                //終点
                rep(t,n){
                    if(s==t || j==t ||j==s)continue;

                    dist[s][t][k=min(dist[s][t][k-1],dist[s][t])]
                }
            }
        }
    
    rep(k,n){
        rep(s,n){
            rep(t,n){
                if(s==t)continue;
                if(dist[s][t][k]==INF)continue;
                ans+=dist[s][t][k];
                printf("(s,t,k)=(%d,%d,%d)=%lld \n",s+1,t+1,k+1,dist[s][t][k]);
            }
        }
    }
    cout<<ans<<endl;
}
/*
3 2
1 2 3
2 3 2

25


3 0

0

5 20
1 2 6
1 3 10
1 4 4
1 5 1
2 1 5
2 3 9
2 4 8
2 5 6
3 1 5
3 2 1
3 4 7
3 5 9
4 1 4
4 2 6
4 3 4
4 5 8
5 1 2
5 2 5
5 3 6
5 4 5

517

*/
