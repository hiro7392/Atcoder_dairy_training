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
  int n;
  cin >> n;

  long long sum[2][n + 1];
  sum[0][0] = 0, sum[1][0] = 0;

  rep(i, n) {
    long long c, p;
    cin >> c >> p;
    sum[c - 1][i + 1] = sum[c - 1][i] + p;
    sum[c % 2][i + 1] = sum[c % 2][i];
  }

  long long q;
  cin >> q;

  rep(i, q) {
    long long l, r;
    cin >> l >> r;
    cout << sum[0][r] - sum[0][l] << " " << sum[1][r] - sum[1][l] << endl;
  }
  return 0;
}
/*


*/
