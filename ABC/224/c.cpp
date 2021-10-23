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
    long long n;
    cin>>n;

    double x[n],y[n];

    rep(i,n)cin>>x[i]>>y[i];
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            for(int l=k+1;l<n;l++){
                if(y[i]==y[k] && y[i]==y[l] && y[k]==y[l]){
                    continue;
                } 
                if(x[i]==x[k] && x[i]==x[l] && x[k]==x[l]){
                    continue;
                }    
                double a1=(x[i]-x[k])/(y[i]-y[k]);
                double a2=(x[i]-x[l])/(y[i]-y[l]);
                double a3=(x[k]-x[l])/(y[k]-y[l]);
                if(a1==a2 && a2==a3 && a3 == a1){
                    continue;
                }else{
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
/*


*/
