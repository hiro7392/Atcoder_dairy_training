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
    int n;
    cin>>n;
    char block[n][n];
    rep(i,n)rep(k,n)cin>>block[i][k];

    string ans="No";
    //横
    rep(i,n){
        rep(k,n-5){
            int cntBlack=0;
            rep(l,6){
                if(block[i][k+l]=='#')cntBlack++;
            }
            if(cntBlack>=4){
                ans="Yes";
                break;
            }
        }
    }
    //縦
    rep(i,n){
        rep(k,n-5){
            int cntBlack=0;
            rep(l,6){
                if(block[k+l][i]=='#')cntBlack++;
            }
            if(cntBlack>=4){
                ans="Yes";
                break;
            }
        }
    }
    //斜め
    rep(i,n){
        rep(k,n){
            int sx=i;
            int sy=0;
            int cntBlack=0;
            if(sx+5+k>=n || sy+k+5>=n)continue;
            rep(l,6){
                if(sx+l+k>=n || sy+k+l>=n)continue;
                if(block[sx+l+k][sy+k+l]=='#')cntBlack++;
            }
            if(cntBlack>=4){
                ans="Yes";
                break;
            }
        }
    }
    rep(i,n){
        rep(k,n){
            int sx=0;
            int sy=i;
            int cntBlack=0;
            if(sx+5+k>=n || sy+k+5>=n)continue;
            rep(l,6){
                if(sx+l+k>=n || sy+k+l>=n)continue;
                if(block[l+k][sy+k+l]=='#')cntBlack++;
            }
            if(cntBlack>=4){
                ans="Yes";
                break;
            }
        }
    }

    //右上がり
    rep(i,n){
        rep(k,n){
            int sx=i;
            int sy=0;
            int cntBlack=0;
            if(sx-k-5<0 || sy+k+5>=n)continue;
            rep(l,6){
                if(sx-l<0 || sy+k+l>=n)continue;
                if(block[sx-l-k][sy+k+l]=='#')cntBlack++;
            }
            if(cntBlack>=4){
                ans="Yes";
                break;
            }
        }
    }

    rep(i,n){
        rep(k,n){
            int sx=n-1;
            int sy=i;
            int cntBlack=0;
            if(sx-k-5<0 || sy+k+5>=n)continue;
            rep(l,6){
                if(sx-l<0 || sy+k+l>=n)continue;
                if(block[sx-l-k][sy+k+l]=='#')cntBlack++;
            }
            if(cntBlack>=4){
                ans="Yes";
                break;
            }
        }
    }
    cout<<ans<<endl;
}
/*

6
#.....
......
..#...
...#..
....#.
.....#
Yes

7
.......
#......
.#.....
..#....
.......
.......
.....#.

Yes


7
.#.....
..#....
...#...
....#..
.....#.
......#
.....#.

7
..#....
...#...
.#..#..
..#..#.
.......
.......
.....#.

7
......#
.....#.
....#..
...#...
..#....
.#.....
.......


7
.......
...#...
.#.....
......#
.....#.
....#..
.#.#...
*/
