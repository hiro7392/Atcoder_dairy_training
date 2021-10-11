#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0
bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.first>p2.first)return true;
    else if(p1.first==p2.first){
        return p1.second<p2.second;
    }else{
    return false;
    }
}

int main(){
    long long n,m;
    cin>>n>>m;

    //ジャンケンで出す手
    vector<string> A(2*n);
    //<勝ち数,番号>
    vector<pair<int,int>>win(2*n);
    //各自の勝ち数
    rep(i,2*n){
        string now;
        cin>>now;
        A[i]=now;
        win[i]=make_pair(0,i);
    }
    

    //mラウンドジャンケンをする
    rep(i,m){

        rep(k,n){
            //引き分けのとき
            if(A[win[2*k].second][i]==A[win[2*k+1].second][i])continue;

            //勝ち負けがつく時
            if(A[win[2*k].second][i]=='C' && A[win[2*k+1].second][i]=='P'){
                win[2*k].first++;
            }else if(A[win[2*k].second][i]=='G' && A[win[2*k+1].second][i]=='C'){
                win[2*k].first++;
            }else if(A[win[2*k].second][i]=='P' && A[win[2*k+1].second][i]=='G'){
                win[2*k].first++;
            }

            if(A[win[2*k+1].second][i]=='C' && A[win[2*k].second][i]=='P'){
                win[2*k+1].first++;
            }else if(A[win[2*k+1].second][i]=='G' && A[win[2*k].second][i]=='C'){
                win[2*k+1].first++;
            }else if(A[win[2*k+1].second][i]=='P' && A[win[2*k].second][i]=='G'){
                win[2*k+1].first++;
            }
        }
        sort(win.begin(),win.end(),cmp);
    }
    rep(i,2*n){
        cout<<win[i].second+1<<endl;
    }
}
/*


*/
