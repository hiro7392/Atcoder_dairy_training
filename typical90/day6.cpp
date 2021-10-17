#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

/* 辞書順最小を求める
辞書順最小:=次の文字におけるものとして最も早い文字chを
貪欲に付け足すことで求められる文字列

高速化のための工夫
"前に選んだ文字の右にある文字cの中で最左のもの"
を求める処理を高速化するために
以下のような配列c[i][k]を前計算する

c[i][k]:=i文字目の右にある文字kの中で最も左側にあるもののインデックス


*/
int main(){
    long long  n,K;
    cin>>n>>K;

    string s;
    cin>>s;

    //c[i][k]:=i文字目の右にある文字kの中で最も左側にあるもののインデックス
    int c[n+1][26];

    for(int i=n-1;i>-1;i--){
        rep(k,26){
            char nch=(char)('a'+k);
            if(nch==s[i]){
                c[i][k]=i+1;
            }else if(i==n-1){
                c[i][k]=n+1;
            }else{
                c[i][k]=c[i+1][k];
            }
        }
    }
    string ans="";

    for(int i=0;i<n;i++){
        rep(k,26){
            //文字kが出現しない時
            if(c[i][k]>=n+1)continue;

            //その文字をとってもK文字以上が実現可能か
            //　(n-1移動するindex)>=残り必要な文字数
            if(n-c[i][k]>=K-ans.size()-1){
                ans.append(1,s[c[i][k]-1]);
                #if debug
                cout<<ans.size()<<"文字目 : "<<s[c[i][k]-1]<<endl;
                cout<<"現在のindex : "<<i<<endl;
                #endif
                i=c[i][k]-1;
                break;
            }
        }
        if(ans.size()>=K)break;
    }
    cout<<ans<<endl;
#if debug
    rep(k,26){
        cout<<(char)('a'+k)<<" ";
        rep(i,s.size()){
            cout<<c[i][k]<<" ";
        }
        cout<<endl;
    }
#endif
}
/*
sample

7 3
bacbcba

*/
