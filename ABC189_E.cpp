#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;
#define debug 0

pair<long long,long long>rotation(pair<long long,long long> now){
    return make_pair(now.second,-now.first);
}
int main(){
    int n;
    cin>>n;
    vector<pair<long long,long long>>point(n);
    
    rep(i,n){
        long long x,y;
        cin>>x>>y;
        point[i]=make_pair(x,y);
    }

    int m;
    cin>>m;
    int rotate[m+1]={};
    bool x_minus[m+1]={};
    bool y_minus[m+1]={};
    bool x_swap[m+1]={};
    bool y_swap[m+1]={};

    long long y_move[m+1]={};
    long long x_move[m+1]={};
    rep(i,m){
        int num;
        cin>>num;
        //rotate[i+1]=rotate[i];
        x_minus[i+1]=x_minus[i];
        y_minus[i+1]=y_minus[i];
        x_move[i+1]=x_move[i];
        y_move[i+1]=y_move[i];
        x_swap[i+1]=x_swap[i];
        if(num==1){
            //rotate[i+1]=(rotate[i]+1)%4;
            if(x_swap[i])y_minus[i+1]=!y_minus[i];
            else{
                x_minus[i+1]=!x_minus[i];
            }
            x_swap[i+1]=!x_swap[i];
            

            x_move[i+1]=y_move[i];
            y_move[i+1]=-x_move[i];
            
        }
        else if(num==2){
            
            if(!x_swap[i])y_minus[i+1]=!y_minus[i];
            else{
                x_minus[i+1]=!x_minus[i];
            }
            x_swap[i+1]=!x_swap[i];
            

            x_move[i+1]=-y_move[i];
            y_move[i+1]=x_move[i];
            
        }
        else if(num==3){
            long long p;
            cin>>p;
            x_move[i+1]=-x_move[i]+p;
            //位置が変わっていない時
            if(!x_swap[i])x_minus[i+1]=!x_minus[i];
            else{
            //位置が変わっている時
                y_minus[i+1]=!y_minus[i];
            }
        }
        else if(num==4){
            long long p;
            cin>>p;
            y_move[i+1]=-y_move[i]+p;
            if(!x_swap[i])y_minus[i+1]=!y_minus[i];
            else{
                x_minus[i+1]=!x_minus[i];
            }
        }
    }
    int q;
    cin>>q;

    rep(i,q){
        int a;
        long long b;
        cin>>a>>b;
        long long x=point[b-1].first;
        long long y=point[b-1].second;
        if(x_minus[a])x=-x;
        if(y_minus[a])y=-y;
        
        long long retx,rety;
        retx=x_swap[a]? y:x;
        rety=x_swap[a]? x:y;
        
        retx+=2*x_move[a];
        rety+=2*y_move[a];
        cout<<retx<<" "<<rety<<endl;

    }
#if debug
    rep(i,m+1){
        cout<<"op :"<<i<<endl;
        cout<<"y_move: "<<y_move[i]<<endl;
        cout<<"x_move: "<<x_move[i]<<endl;
        cout<<"y_minus: "<<y_minus[i]<<endl;
        cout<<"x_minus: "<<x_minus[i]<<endl;
        cout<<"swap: "<<x_swap[i]<<endl;
        //cout<<"rotation: "<<rotate[i]<<endl;
    }
#endif
}
/*
5
AND
AND
AND
AND
AND



*/
