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


vector<long long> setNums(){
    vector<long long> nums(11,1);
    //nums[1]=1;
    for(int i=2;i<11;i++){
        nums[i]=nums[i-1]*(i);
    }
    return nums;
}
int main(){
    
    auto nums=setNums();

    long long p;
    cin>>p;

    int ans=0;
    for(int i=10;i>0;i--){
        if(p>0){
            ans+=p/nums[i];
            p%=nums[i];
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;


}
/*


*/
