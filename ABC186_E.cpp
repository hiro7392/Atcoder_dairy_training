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
//solved 2021/01/01
int main(){
    int t;cin>>t;
    rep(_,t){
        long long n,s,k;
        cin>>n>>s>>k;
        long long tmp=GCD(n,-k);
        
        if(s%tmp!=0){
            cout<<"-1\n";
        }
        else{
            //s+b*k=0 (mod N)をみたす最小のbを求める


            //移行してs<-n-sとする
            //b*k=n-s (mod N)
            s=n-s;
            //求めるbは最小の整数なので
        
            //最大公約数でs,b,kを割る
            //b*k=s (mod N) <=> b*k=s+N*i (iは任意の自然数)より両辺を最大公約数でわる
            long long d=GCD(tmp,s);
            n/=d;s/=d;k/=d;

            //b*k=s (mod N)に対して
            //b=s* k^(-1) (mod N) 
            //s*(kのNに対する逆元) (mod N)
            //で求めたい自然数bが求められる
            cout<<(s*modinv(k,n))%n<<endl;
        }
    }
}
/*


*/
