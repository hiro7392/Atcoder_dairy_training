#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

int main(){
    int n,K;
    cin>>n>>K;
    string str[n];
    rep(i,n)cin>>str[i];
    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){

        //a〜zの出現回数
        int cnt[26]={};
        for(int k=0;k<n;k++){
            if(!(bit&(1<<k)))continue;

            //出現回数をカウント
            rep(i,str[k].size()){
                cnt[(int)(str[k][i]-'a')]++;
            }
        }
        int now=0;
        rep(l,26){
            if(cnt[l]==K)now++;
        }
        ans=max(ans,now);
    }
    cout<<ans<<endl;
    return 0;
}
/*


*/
