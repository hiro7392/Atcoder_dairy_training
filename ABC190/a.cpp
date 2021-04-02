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
//a^mを求める
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

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

int main(){
    long long k;
    cin>>k;

    string s;
    string t;
    cin>>s;
    cin>>t;
    long long sumS=0,sumT=0;
    int s_num[10]={},t_num[10]={};//1~9
    rep(i,4){
        int sn=s[i]-'1';
        int tn=t[i]='1';
        s_num[sn]++;
        t_num[tn]++;
    }
    rep2(i,9){
        sumS+=i*modpow(10,s_num[i]);
        sumT+=i*modpow(10,t_num[i]);
    }


}
/*


*/
