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

//constexpr char bracket[2]={'(',')'};

void dfs(string now,int limit,int lb,int rb){
    

    if(lb<rb)return;

    int len=now.size();
    if(limit<=len && lb==rb){
        //cout<<now<<"lb  "<<lb<<"rb "<<rb<<endl;
        cout<<now<<endl;
        return;
    }
    else if(limit==len){
        return;
    }
    else{
        //cout<<"making bracker .."<<endl;
        string add_right;
        string add_left;
        add_right=now+")";
        add_left=now+"(";
        dfs(add_left,limit,lb+1,rb);
        dfs(add_right,limit,lb,rb+1);
        
        return;
    }
    
}

int main(){
    int n;
    cin>>n;
    string start="(";
    if(n%2)return 0;
    dfs(start,n,1,0);

    return 0;
}
/*

*/
