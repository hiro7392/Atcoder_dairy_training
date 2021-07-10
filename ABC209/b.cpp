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
    
    long long sum=0;

    long long n,x;
    cin>>n>>x;

    long long a[n];
    rep(i,n){
        
        cin>>a[i];
        if(i%2!=0)sum+=a[i]-1;
        else{
            sum+=a[i];
        }
    }
    if(sum<=x){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }

}
/*


*/
