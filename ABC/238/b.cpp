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

    vector<int> angles(n+1);
    int nowPos=0;   //現在の角度
    angles[0]=0;    //最初の切れ目
    rep2(i,n){   
        int nowAngle;
        cin>>nowAngle;
        nowPos+=nowAngle;
        if(nowPos>360)nowPos-=360;
        angles[i]=nowPos;
#if debug
        cout<<"nowPos "<<nowPos<<endl;
        cout<<"angles "<<angles[i]<<endl;
#endif 
        
        
    }
    sort(angles.begin(),angles.end());

#if debug
    cout<<"angle state\n";
    rep(i,n+1)cout<<angles[i]<<" ";
    cout<<endl;
#endif
    int ans=0;
    rep2(i,n){
        ans=max(ans,angles[i]-angles[i-1]);
#if debug
        cout<<ans<<endl;
#endif
    }
    cout<<max(ans,360-angles[n])<<endl;
}
/*


*/
