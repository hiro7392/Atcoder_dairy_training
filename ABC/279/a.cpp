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
    string s;
    cin>>s;
    int ans=0;
    rep(i,s.size()){
        if(s[i]=='v'){
            ans++;
        }else{
            ans+=2;
        }
    }
    cout<<ans<<endl;

}
/*


*/
