#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

long long dx[2]={1,2};
long long dy[2]={2,1};
long  dir[2]={-1,1};


#define debug 0

struct Point{
    long long x;
    long long y;

    //コンストラクタ
    Point(long long newX,long long newY):x{newX},y{newY}{}
};

int main(){
    vector<Point>near1;
    vector<Point>near2;

    long long x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    rep(i,2){
        rep(k,2){
            rep(l,2){
                near1.push_back(Point(x1+dx[k]*dir[i],y1+dy[k]*dir[l]));
            }
        }
    }
    rep(i,2){
        rep(k,2){
            rep(l,2){
                near2.push_back(Point(x2+dx[k]*dir[i],y2+dy[k]*dir[l]));
            }
        }
    }
#if debug
    for(auto np:near1)cout<<"x:"<<np.x<<" y: "<<np.y<<endl;
#endif
    bool ans=false;
    for(auto np:near1){
        for(auto np2:near2){
            if(np.x==np2.x && np.y==np2.y)ans=true;
        }
    }

    string outStr="No";
    if(ans)outStr="Yes";

    cout<<outStr<<endl;

}
/*


*/
