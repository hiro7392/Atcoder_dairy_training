#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep2(i, N) for (int i = 1; i <= N; i++)
using namespace std;
long long INF = 1e18;
long long mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define debug 0

int main() {
  long long n, q;
  cin >> n >> q;

  vector<long long> front(
      n + 1, -1);  // front[i]:=電車iの前部に連結している電車なければ-1
  vector<long long> back(
      n + 1, -1);  // back[i]:=電車iの前部に連結している電車なければ-1

  rep(i, q) {
    long long a, x, y;
    cin >> a;
    if (a == 1) {
      cin >> x >> y;
      x--, y--;
      //連結する時
      front[y] = x;
      back[x] = y;

    } else if (a == 2) {
      cin >> x >> y;
      x--, y--;
      //分離する時
      front[y] = -1;
      back[x] = -1;
    } else {
      cin >> x;
      x--;
      //まずxが連結している電車の先頭へ移動
      while (front[x] > 0) {
        x = front[x];
        if (front[x] < 0) break;
      }
      vector<long long> ans;
      while (x >= 0) {
        ans.push_back(x);
        x = back[x];
      }
      cout << ans.size() << " ";
      for (auto now : ans) {
        cout << now+1 << " ";
      }
      cout << endl;
    }
  }
}
/*
//分離しないとき
5 5
1 1 2
1 3 4
1 5 3
1 2 5
3 1

//分離するとき
5 6
1 1 2
1 3 4
1 5 3
1 2 5
2 2 5
3 1

*/
