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
    long long  x;
    cin>>x;
    string xStr=to_string(x);
    if(x>0){
        rep(i,xStr.size()-1){
            cout<<xStr[i];
        }
        cout<<endl;
        if(xStr.size()<=1){
            cout<<'0'<<endl;
        }
    }else{
        
        if(xStr.size()<=2){
            cout<<x<<endl;
        }
        else if(xStr[xStr.size()-1]!='0'){
            x-=10;
            xStr=to_string(x);
            rep(i,xStr.size()-1){
                cout<<xStr[i];
            }
            cout<<endl;
        }else {
            rep(i,xStr.size()-1){
                cout<<xStr[i];
            }
            cout<<endl;
        }
        
    }
}
/*


*/
