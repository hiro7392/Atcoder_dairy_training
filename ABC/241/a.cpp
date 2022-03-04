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
    /*
    string origin="nueinukf";
    string changed=origin;
    rep(i,origin.size()){
        int num=origin[i]-'a';
        num+=6;
        if(num<0)num+=26;
        else{
            num%=26;
        }
        changed[i]='a'+num;
    }
    cout<<changed<<endl;
    */
    int startNum=0;
    const int n=10;
    vector<int> nums(n);
    rep(i,n)cin>>nums[i];

    rep(i,3){
        startNum=nums[startNum];
    }
    cout<<startNum<<endl;
}
/*


*/
