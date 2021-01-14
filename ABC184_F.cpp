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
#define debug2 0

#define simple_solve 0



vector<long long>getSum(vector<long long>B){
    long long sec[25];
    sec[0]=1;
    rep2(i,24)sec[i]=sec[i-1]*2;
    vector<long long>sumB;
    for(int i=0;i<(1<<B.size());i++){
        long long tmp=0;
        for(int k=0;k<B.size();k++){
            if(sec[k]&i){
                tmp+=B[k];
            }
        }
        sumB.push_back(tmp);
    }
    sort(sumB.begin(),sumB.end());
    return sumB;
}

int main(){
    long long n,t;
    cin>>n>>t;

    vector<long long>a(n);
    rep(i,n)cin>>a[i];

    //sort(a.begin(),a.end());
    long long ans=0;

#if simple_solve
    vector<vector<bool>>dp(n+1,vector<bool>(t+1,false));// dp[n+1][t+1]

    rep(i,n+1)dp[i][0]=true;
    
    for(long long k=0;k<=t;k++){
        
        for(int i=1;i<=n;i++){
            if(k-a[i-1]>=0){
                dp[i][k]=dp[i-1][k-a[i-1]]|dp[i][k];
            }
            //else{
                dp[i][k]=dp[i-1][k]|dp[i][k];
            //}
        }
    }
    for(long long k=t;k>0;k--){
        if(dp[n][k]){
            ans=k;
            break;
        }
    }
    #if debug
    for(int i=1;i<=n;i++){
        for(long long k=0;k<=t;k++){
            if(dp[i][k]){
                cout<<"T ";
            }
            else{
                cout<<"F ";
            }
        }
        cout<<endl;
    }
    #endif

    cout<<ans<<endl;
#endif

    long long Ans=0;

    int half=n/2;
    vector<long long> B(half);
    vector<long long> C(n-half);

    for(int i=0;i<n;i++){
        if(i<half)B[i]=a[i];

        else{
            C[i-half]=a[i];
        }
    }
    //sort(C.begin(),C.end());

    

    vector<long long>sumB=getSum(B);
    vector<long long>sumC=getSum(C);
#if debug2 
    cout<<"sumB:";
    rep(i,sumB.size()){
        cout<<sumB[i]<<" ";
    }
    cout<<endl;
    cout<<"sumC:";
    rep(i,sumC.size()){
        cout<<sumC[i]<<" ";
    }
    cout<<endl;
#endif
    
    rep(i,sumB.size()){

        long long res=t-sumB[i];
        if(res<0)continue;

        int iter=(int)(upper_bound(sumC.begin(),sumC.end(),res)-sumC.begin());
        iter--;

        Ans=max(Ans,sumB[i]+sumC[iter]);
    }
    
    cout<<Ans<<endl;
#if debug
    assert(ans==Ans);
#endif
}
/*


*/
