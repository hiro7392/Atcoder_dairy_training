#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

double sq(double x){return x*x;}

double radToAngle(double x){
    return (x/(M_PI))*180.0;
}
//余弦定理の逆から角度を求める
double getAngle(double l1,double l2,double l3){
    double cos=(sq(l3)-sq(l1)-sq(l2))/(-2.0*l1*l2);
    return radToAngle(acos(cos));
}


double getDistance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    int n;
    cin>>n;

    double px[n],py[n];
    rep(i,n){
        cin>>px[i]>>py[i];
    }
    double ans=0.0;
    for(int i=0;i<n;i++){
        for(int j=i+i;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(i==j ||j==k || k==i)continue;
                //3辺の長さを求める
                double l1=getDistance(px[i],py[i],px[j],py[j]);
                double l2=getDistance(px[j],py[j],px[k],py[k]);
                double l3=getDistance(px[k],py[k],px[i],py[i]);

                //それぞれの角度を余弦定理の逆から求める
                ans=max(ans,getAngle(l1,l2,l3));
                ans=max(ans,getAngle(l2,l3,l1));
                ans=max(ans,getAngle(l3,l1,l2));
            }
        }
    }
    printf("%.7f\n",ans);
}
/*


*/
