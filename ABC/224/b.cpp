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
    
    int h,w;
    cin>>h>>w;

    long long a[h][w];

    rep(i,h){
        rep(k,w){
            cin>>a[i][k];
        }
    }
    rep(i,h){
        rep(k,w){
            for(int p=i+1;p<h;p++){
                for(int l=k+1;l<w;l++){
                    if(a[i][k]+a[p][l]>a[p][k]+a[i][l]){
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
/*


*/
