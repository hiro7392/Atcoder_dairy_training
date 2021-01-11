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
char maze[2010][2010];
//dist[i][k]=sx,syからの最短距離
long long dist[2010][2010];
//solved 2021/01/02
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    int h,w;
    cin>>h>>w;

    int sx,sy,gx,gy;
    vector<vector<pair<int,int>>>teleport(26);
    bool reached[26]={};
    rep2(i,h){
        rep2(k,w){
            
            cin>>maze[i][k];
            dist[i][k]=INF;
            if(maze[i][k]=='S'){
                sx=k;sy=i;
            }
            else if(maze[i][k]=='G'){
                gx=k;gy=i;
            }
            else if(maze[i][k]<='z'&& maze[i][k]>='a'){
                teleport[maze[i][k]-'a'].push_back(make_pair(i,k));
            }
        }
    }
    dist[sy][sx]=0;
    queue<int>q;
    q.push(sy);
    q.push(sx);
    
    while(!q.empty()){
        int nowy=q.front();q.pop();
        int nowx=q.front();q.pop();
        //テレポートできる場合
        if(maze[nowy][nowx]<='z'&& maze[nowy][nowx]>='a' && !reached[maze[nowy][nowx]-'a']){
        reached[maze[nowy][nowx]-'a']=true;
                for(auto p:teleport[(int)(maze[nowy][nowx]-'a')]){

                    if((nowy!=p.first) || (nowx!=p.second)){
                        if(dist[p.first][p.second]>dist[nowy][nowx]+1){
                            dist[p.first][p.second]=dist[nowy][nowx]+1;
#if debug                            
                            printf("teleport! %d %d\n",nowy,nowx);
#endif
                            q.push(p.first);
                            q.push(p.second);
                            maze[p.first][p.second]='#';
                        }
                    }
                }
        }
        rep(i,4){
            int ny=nowy+dy[i];
            int nx=nowx+dx[i];

            if(ny>h || ny<1 || nx>w || nx<1 || maze[ny][nx]=='#'){
                continue;
            }
            else if(dist[ny][nx]>dist[nowy][nowx]+1){
                dist[ny][nx]=dist[nowy][nowx]+1;
                q.push(ny);
                q.push(nx);
                //maze[ny][nx]='#';
            }
            
        }
        
    }
    //asm("int3");
#if debug
    rep2(i,h){
        rep2(k,w){
            if(dist[i][k]==INF){
                cout<<"# ";
            }
            else{
            cout<<dist[i][k]<<" ";
            }
        }
        cout<<endl;
    }

    rep(i,26){
        for(auto p:teleport[i]){
        cout<<(char)('a'+i)<<" "<<p.first<<" "<<p.second<<endl;
        }
    }
#endif
    if(dist[gy][gx]==INF)dist[gy][gx]=-1;
    cout<<dist[gy][gx]<<endl;
}
/*


*/
