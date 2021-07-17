#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

long long GCD(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    else return GCD(b, a % b);
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

int main(){
    long long n,k;
    cin>>n>>k;

    long long c[n];
    rep(i,n)cin>>c[i];

    long long ans=-1;
    map<long long,long long>exist;
    //multiset<int>exist;
    
    
    long long tmp=0;

    for(int i=0;i<k;i++){
        auto it=exist.find(c[i]);
        if(it==exist.end()){
            exist.insert(make_pair(c[i],1));
            tmp++;
        }else{
            exist[c[i]]++;
        }
        ans=max(ans,tmp);
    }
#if 0
    cout<<"point1"<<endl;

#endif 
    for(int i=k;i<n;i++){
        
        auto it=exist.find(c[i-k]);
        
        //前の要素を削除
        if(it->second==1){
            exist.erase(c[i-k]);
            tmp--;
        }
        else{
            exist[c[i-k]]--;
            //if(exist[c[i-k]]==0)tmp--;
        }

        //新しい要素
        auto itM=exist.find(c[i]);
        //ない場合
        if(itM==exist.end()){
            exist.insert(make_pair(c[i],1));
            tmp++;
        }else{
            //すでにある時
            exist[c[i]]++;
        }
        ans=max(ans,tmp);
    }
    
    cout<<ans<<endl;



    // for(int i=0;i<n;i++){
    //     int numColor=0;
        
    //     while(q.size()<k){
    //         q.push(c[now]);
    //         //すでに持っている色
    //         if(exist.find(c[now])!=exist.end()){
                
    //         }
    //         else{
    //             tmp++;
    //         }
    //         now++;
    //     }
        
    //     ans=max(ans,numColor);
    // }
}
/*


*/
