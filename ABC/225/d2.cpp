#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define debug 0

struct train{
    vector<int>size;
    vector<int>distFromTop;
    vector<int>back;
    vector<int>head;
    UnionFind(int n) : par(n, -1), back(n, -1), distFromTop(n, 0),size() {}

};


int main(){
    long long n,q;
    cin>>n>>q;

    rep(i,q){
         long long a, x, y;
        cin >> a;
        if (a == 1) {
            cin >> x >> y;
            x--, y--;
            
        } else if (a == 2) {
            cin >> x >> y;
            x--, y--;
            
        } else {
            cin >> x;
            x--;
        }
    }
}
/*


*/
