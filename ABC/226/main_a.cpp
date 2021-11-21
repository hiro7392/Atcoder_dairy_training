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
 double x;
 cin>>x;

 int xInt=x;
 //cout<<xInt<<endl;
 x-=xInt;
 if(x>=0.5){
     xInt++;
 }
 cout<<xInt<<endl;
}
/*

//縦21 横64




*/
