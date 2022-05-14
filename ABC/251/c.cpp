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
    int n;
    cin>>n;
    string s;
    long long t;
    map<string,int>originals;//<文字列,index>

    map<long long,string>poems;////<文字列,得点>
    rep(i,n){
        cin>>s>>t;
        if(originals.find(s)==originals.end()){
            originals.insert(make_pair(s,i+1));
            poems.insert(make_pair(t,s));
        }
    }
    auto it=poems.end();
    it--;
    cout<<originals[it->second]<<endl;

    
    return 0;

}
/*


*/
