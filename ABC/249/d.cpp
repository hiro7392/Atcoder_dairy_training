#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

vector<int>factorize(long long n){
    vector<int>ret;
    for(int i=1;i<=n;i++){
        if(n%i==0)ret.push_back(i);
    }
    return ret;
}
int main(){
    long long n;
    cin>>n;
    multiset<long long>a;
    rep(i,n){
        int p;
        cin>>p;
        a.insert(p);
    }

    
    
    long long ans=0;

    for(auto now:a){
        vector<int> fact=factorize(now);
        for(int i=0;i<fact.size();i++){
            if(a.find(fact[i])!=a.end() && a.find(now/fact[i])!=a.end()){
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
/*


*/
