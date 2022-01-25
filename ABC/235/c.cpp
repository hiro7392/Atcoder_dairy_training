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

    vector<string>stations(n);
    set<string>stopStations;

    rep(i,n){
        string s;
        cin>>s;
        stations[i]=s;
    }

    rep(i,m){
        string s;
        cin>>s;
        stopStations.insert(s);
    }
    rep(i,n){

        auto it=stopStations.find(stations[i]);

        if(it!=stopStations.end()){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    
}
/*




*/
