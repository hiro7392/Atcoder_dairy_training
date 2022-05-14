#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0
 
bool cmp(pair<long long,int>p1,pair<long long,int>p2){
    return p1.first<p2.first;
}

int main(){
    long long n;
    cin>>n;
    bool pet[n+1]={};
    vector<pair<long long,int>>a(n);

    rep(i,n){
        long long x;
        cin>>x;
        a[i]=make_pair(x,i);
    }

    sort(a.begin(),a.end(),cmp);
    
    long long ans=0;
    for(int i=0;i<n;i++){
        pair<long long,int>food=a[i];
        if((!pet[food.second]) || (!pet[(food.second+1)%n])){
            ans+=food.first;
            pet[food.second]=pet[(food.second+1)%n]=true;
        }
    }
    cout<<ans<<endl;
    // for(auto now:a){
    //     cout<<now.first<<endl;
    // }
    return 0;

}
/*


*/
