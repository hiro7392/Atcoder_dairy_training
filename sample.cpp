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
char maze[2010][2010];
//dist[i][k]=sx,syからの最短距離
long long dist[2010][2010];
//solved 2021/01/02
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    printf("debug1\n");
    asm("int3");
    printf("debug2\n");
    printf("debug3¥n");
}
/*


*/
