#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

//2~nまでの素数の集合を返す
set<int>eratos(int n){
    vector<bool>nums(n+3,false);
    

    set<int>ret;
    int END=n+3;
    for(int i=2;i<END;i++){
        int now=i;
        //すでに素数でないなら無視
        if(nums[now])continue;
        else{
            //素数であった時
            while(now<=n){
                now+=i;
                nums[now]=true;
            }
        }
    }
    for(int i=2;i<=END;i++){
        if(!nums[i])ret.insert(i);
    }
    
    return ret;

}

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    set<int> primes=eratos(250);

    string ans="Aoki";
    bool AokiWin=true;
    for(int i=a;i<=b;i++){
        bool TakahashiWin=true;
        for(int k=c;k<=d;k++){
            //素数になる組み合わせが見つかった時
            if(primes.find(i+k)!=primes.end()){
                TakahashiWin=false;
            }
        }
        //一つでも先手が勝てる方法があれば先手の勝ち
        if(TakahashiWin)ans="Takahashi";
    }
#if debug
    for(auto now:primes)cout<<now<<endl;
#endif
    cout<<ans<<endl;
}
/*


*/
