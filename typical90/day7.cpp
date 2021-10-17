#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

/* 

*/
int main(){
    
    int n;
    cin>>n;
    vector<long long>v(n);
    rep(i,n){
        cin>>v[i];
    }
    sort(v.begin(),v.end());

#if debug
    rep(i,n)cout<<v[i]<<endl;
#endif

    int q;
    cin>>q;
    long long b;
    long long ans=0;
    rep(i,q){
        cin>>b;
        long long now;
        int index=(int)(upper_bound(v.begin(),v.end(),b)-v.begin());
        if(index>0){
            now=min(abs(b-v[min(index,n-1)]),abs(b-v[index-1]));
        }else{
            now=abs(b-v[min(index,n-1)]);
        }
#if debug
        cout<<"index : "<<index<<" now: "<<now<<endl;
#endif
        cout<<now<<endl;

    }
    
}
/*


*/
