#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep2(i, N) for (int i = 1; i <= N; i++)
using namespace std;
long long INF = 1e18;
const long long MOD = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define debug 0

inline long long mod(long long a, long long m) { return (a % m + m) % m; }

inline long long mul(long long a, long long b, long long m) {
  a = mod(a, m);
  b = mod(b, m);
  if (b == 0) return 0;
  long long res = mul(mod(a + a, m), b >> 1, m);
  if (b & 1) res = mod(res + a, m);
  return res;
}

inline long long inv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a = mod(a - mul(t, b, m), m);
    swap(a, b);
    u = mod(u - mul(t, v, m), m);
    swap(u, v);
  }
  return mod(u, m);
}

long long pow(long long a, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long t = pow(a, n / 2, m);
  t = mul(t, t, m);
  if (n & 1) t = mul(t, a, m);
  return t;
}

int main() {
  long long n;
  cin >> n;
  long long left = 1;
  long long right = 9;
  long long tens = 1;
  long long ans = 0;
  long long before = 55;
  while (right < n) {
    if (right < 10) {
      ans += (((left + right) * (right - left + 1)) / 2);
      // before=(((left+right)*(right-left+1))/2);
    } else {
      ans +=
          mul((1 + (right - left + 1)), (right - left + 1), MOD) * inv(2, MOD);
    }
#if debug
    cout << "right = " << right << endl;
    cout << "left = " << left << endl;
#endif
    ans %= MOD;
    left = right + 1;
    right = (right + 1) * 10 - 1;
  }
#if debug
  cout << "left = " << left << endl;
  cout << "ans = " << ans << endl;
#endif
  // ans += mul(mul(n - left + 1, n - left + 1, MOD),inv(2, MOD),MOD);
  ans += (((((n - left + 1) + 1)%MOD) * ((n - left + 1)%MOD) % MOD) * inv(2, MOD))%MOD;
  ans %= MOD;

#if debug
  cout << "left= " << left << endl;
#endif
  cout << ans << endl;
}
/*


*/
