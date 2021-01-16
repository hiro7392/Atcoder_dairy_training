#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
const long long mod=998244353;

long long GCD(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    else return GCD(b, a % b);
}

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() const { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr istream& operator >> (istream& is, Fp<MOD>& x) noexcept {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream& os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD>& r, long long n) noexcept {
        if (n == 0) return 1;
        if (n < 0) return modpow(modinv(r), -n);
        auto t = modpow(r, n / 2);
        t = t * t;
        if (n & 1) t = t * r;
        return t;
    }
    friend constexpr Fp<MOD> modinv(const Fp<MOD>& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        return Fp<MOD>(u);
    }
};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

char maze[5010][5010];
long long h,w,k;
 

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
    cin>>h>>w>>k;
    rep2(i,h){
        rep2(k,w){
            maze[i][k]='N';
        }
    }
    Fp<mod> dist[h+1][w+1]={};
    rep(i,k){
        int a,b;
        char p;
        cin>>a>>b>>p;
        maze[a][b]=p;
    }
    dist[1][1]=1;
    
    dist[1][1]*=modpow(3,h*w-k);


    //map<long long,long long> dp[h][w];
    //if(maze[1][1]=='N')dp[1][1]

    
    for(int nowy=1;nowy<=h;nowy++){
        for(int nowx=1;nowx<=w;nowx++){
        rep(i,2){
            int nx=nowx+dx[i];
            int ny=nowy+dy[i];

            if(nx>w ||ny>h)continue;

            else if(maze[nowy][nowx]=='X'){
                dist[ny][nx]+=dist[nowy][nowx];
            }
            else if(i==0){
                if(maze[nowy][nowx]=='D')continue;

                else if(maze[nowy][nowx]=='R'||maze[nowy][nowx]=='X'){
                    dist[ny][nx]+=dist[nowy][nowx];
                    
                }
                else if(maze[nowy][nowx]=='N'){
                    dist[ny][nx]+=((dist[nowy][nowx]/3)*2);
                    
                }
            }
            else if(i==1){
                if(maze[nowy][nowx]=='R')continue;

                else if(maze[nowy][nowx]=='D'||maze[nowy][nowx]=='X'){
                    dist[ny][nx]+=dist[nowy][nowx];
                    
                }
                else if(maze[nowy][nowx]=='N'){
                    dist[ny][nx]+=((dist[nowy][nowx]/3)*2);
                    
                }
            }
        }
        }
    }
#if 0
    rep2(i,h){
        rep2(k,w){
            cout<<dist[i][k]<<" ";
        }
        cout<<endl;
    }
    rep2(i,h){
        rep2(k,w){
            cout<<maze[i][k]<<" ";
        }
        cout<<endl;
    }

#endif
    cout<<dist[h][w]<<endl;




    
}
/*
139923295

5000 5000 10
585 1323 R
2633 3788 X
1222 4989 D
1456 4841 X
2115 3191 R
2120 4450 X
4325 2864 X
222 3205 D
2134 2388 X
2262 3565 R


*/
