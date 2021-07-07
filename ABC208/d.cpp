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

    long long dist[410][410]={};
    rep(i,n){
        rep(k,n){
        if(i==k)continue;
        dist[i][k]=INF;
        }
    }

    
    long long ans=0;

    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        dist[a][b]=c;
        //ans+=c;
    }

    //dist[s][t]:=都市sからk以下の都市を巡って都市tへ移動する最短経路

    //k以下の番号について回りながらその時の最短距離を追加していく
        
        
        //経由する頂点
        for(int k=0;k<n;k++){
            //始点
            long long nxt[410][410]={};
            rep(s,n){
                //終点
                rep(t,n){
                    // s->tの最短パスはk+1を使うかどうかで判断できる

                    //(i)k+1を使わない場合
                    //f(s,t,k+1)=f(s,t,k)

                    //(ii)k+1を使う場合
                    //f(s,t,k+1)=f(s,k+1,k)+f(k+1,t,k)
                    dist[s][t]=min(dist[s][t],dist[s][k]+dist[k][t]);
                    if(dist[s][t]<INF)ans+=dist[s][t];
                    
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



5 6
1 3 2
3 2 5
2 1 4
2 5 2
5 3 1
5 4 4


212
*/
