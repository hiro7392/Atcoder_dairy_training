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
    int n,m;
    cin>>n>>m;
    multiset<long long>a;
    rep(i,n){
        long long tmpA;
        cin>>tmpA;
        a.insert(tmpA);
    }

    bool ans=true;
    rep(i,m){
        long long b;
        cin>>b;
        auto ita=a.find(b);
        if(ita!=a.end()){
            a.erase(ita);
        }else{
            ans=false;
        }
    }
    string outStr=ans? "Yes":"No";
    cout<< outStr<<endl;



}
/*


*/
