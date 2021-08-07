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

bool all_same(string s){

    char c=s[0];
    rep(i,s.size()){
        if(c!=s[i])return false;
    }
    return true;
}
int main(){
    string pass;
    cin>>pass;
    char nums[11];
    nums[0]='0';

    rep(i,10){
        nums[i+1]=char((int)nums[i]+1);
    }
    nums[10]=0;

    bool weak=true;
    
    rep(i,3){
        if(pass[i]=='9'){
            if(pass[i+1]!='0')weak=false;
        }
        else if(pass[i+1]!=char((int)pass[i]+1)){
            weak=false;
        }
    }
    weak |=all_same(pass);
    string ans="Strong";
    if(weak)ans="Weak";

    cout<<ans<<endl;
    
}
/*


*/
