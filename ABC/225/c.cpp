#include <bits/stdc++.h>

#define rep(i, N) for (long long i = 0; i < N; i++)
#define rep2(i, N) for (long long i = 1; i <= N; i++)
using namespace std;
long long INF = 1e18;
long long mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define debug 0

int main() {
  long long n, m;
  cin >> n >> m;
  long long b[n][m] = {};
  cin >> b[0][0];

  bool ans = true;
  long long seven = 7;
  rep(i, n) {
    rep(k, m) {
      if (i == 0 && k == 0) continue;
      long long now;
      cin >> now;
      b[i][k] = now;
      if (now != (b[0][0] + (i * seven + k))) {
        ans = false;
      }
    }
  }
  if (((b[0][0] - 1) % 7) > (b[0][m - 1] - 1) % 7) ans = false;
  if (ans) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
/*


*/
