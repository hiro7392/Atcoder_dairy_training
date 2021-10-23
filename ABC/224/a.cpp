#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep2(i, N) for (int i = 1; i <= N; i++)
using namespace std;
long long INF = 1e18;
long long mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define debug 0

bool checkEr(string s) {
  string st = "er";
  if ((s[s.size() - 1] == st[1]) && (s[s.size() - 2] == st[0])) {
    return true;
  } else {
    false;
  }
}
bool checkIst(string s) {
  string st = "ist";
  if (s[s.size() - 1] == st[2] && (s[s.size() - 2] == st[1]) &&
      s[s.size() - 3] == st[0]) {
    return true;
  } else {
    false;
  }
}
int main() {
  string s;
  cin >> s;

  if ((s[s.size()-1]=='r')) {
    cout << "er" << endl;
  } else if ((s[s.size()-1]=='t')) {
    cout << "ist" << endl;
  }
}
/*


*/
