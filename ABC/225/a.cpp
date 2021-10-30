#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep2(i, N, k) for (int i = k + 1; i <= N; i++)
using namespace std;
long long INF = 1e18;
long long mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define debug 0

int main() {
  string s;
  cin >> s;
  int al[26] = {};
  rep(i, 3) {
    if (al[s[i] - 'a'] == 0) al[s[i] - 'a']++;
  }
  int ans = 0;
  rep(i, 26) {
    if (al[i]) ans++;
  }
  if (ans == 1) {
    cout << 1 << endl;

  } else if (ans == 2) {
    cout << 3 << endl;
  } else {
    cout << 6 << endl;
  }
  // cout << ans << endl;
}
/*


*/
