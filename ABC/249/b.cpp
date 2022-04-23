#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

bool ckeckCapital(string s){
    rep(i,s.size()){
        if(s[i]<='Z'){
            return true;
        }
    }
    return false;
}
bool checkSmall(string s){
    rep(i,s.size()){
        if(s[i]<='z' && s[i]>='a'){
            return true;
        }
    }
    return false;
}
bool checkNotSame(string s){
    set<char>tree;
    rep(i,s.size()){
        if(tree.find(s[i])!=tree.end())return false;
        else{
            tree.insert(s[i]);
        }
    }
    return true;
}
int main(){
    
    string s;
    cin>>s;

    if(checkNotSame(s)&& checkSmall(s)&& ckeckCapital(s)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}
/*


*/
