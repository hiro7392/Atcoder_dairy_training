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
    stack<pair<int,int>>st;
    //q.push(make_pair(1,1));
    //pair<int,int>back=make_pair(1,);
    int nowBallNum=0;
    rep(i,n){
        int a;
        cin>>a;
        nowBallNum++;
        if(i==0 || st.empty()){
            st.push(make_pair(a,1));
            cout<<nowBallNum<<endl;
            continue;
        }


        auto back=st.top();
#if debug
    cout<<"< " <<back.first<<" "<<back.second<<" >"<<endl;
#endif

        if(back.first!=a){
            st.push(make_pair(a,1));
        }
        else{
            st.pop();
            st.push(make_pair(back.first,back.second+1));
        }

        if(st.top().first==st.top().second){
            nowBallNum-=st.top().second;
            st.pop();
        }

        cout<<nowBallNum<<endl;
    }
}
/*
11
2 3 2 3 3 3 2 3 3 2 8


丁徳
*/
