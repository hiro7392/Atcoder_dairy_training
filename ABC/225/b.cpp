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

  int cnt[n] = {};
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cnt[a]++;
    cnt[b]++;
  }
  rep(i, n) {
    if (cnt[i] == n - 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
/*


*/
