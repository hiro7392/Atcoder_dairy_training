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

bool cmp(pair<long long,int>p1,pair<long long,int>p2){
    return p1.first<p2.first;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<long long,int> > nums(n+m);
    rep(i,n){
        long long a;
        cin>>a;
        nums[i]=make_pair(a,1);
    }
    rep(i,m){
        long long a;
        cin>>a;
        nums[i+n]=make_pair(a,2);
    }

    sort(nums.begin(),nums.end(),cmp);
    long long ans=INF;
    rep(i,n+m-1){
        if(nums[i].second==nums[i+1].second)continue;

        ans=min(ans,nums[i+1].first-nums[i].first);
    }
    cout<<ans<<endl;
}
/*


*/
