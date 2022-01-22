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
    string s;
    cin>>s;


    long long ans=0;
    int nums[3]={1,10,100};
    rep(i,3){
        int temp=0;
        rep(k,3){
            temp+=nums[k]*(int)(s[(i+k)%3]-'0');
        }
        ans+=temp;
    }
    cout<<ans<<endl;
}
/*





*/
