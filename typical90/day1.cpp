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
    long long n,l,k;
    cin>>n>>l;
    cin>>k;
    long long a[n+2];
    a[0]=0,a[n+1]=l;
    rep2(i,n){
        cin>>a[i];
    }

    long long right=l,left=0;
    long long mid=(right+left)/2;
    while(left<right){
        mid=(right+left)/2;
        //cout<<mid<<endl;
        //切れ目を選択した回数
        int cnt=0;
        long long nr=a[0];
        for(int i=1;i<=n+1;i++){
            if(a[i]>=nr+mid){
                cnt++;
                nr=a[i];
            }
        }
        if(cnt>=k+1){
            //大きくする
            left=mid;
        }
        else{
            //探索範囲を小さく
            right=mid;
        }
        if(mid==(right+left)/2)break;
    }

    cout<<mid<<endl;
}
/*


*/
