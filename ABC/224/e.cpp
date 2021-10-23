#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep2(i, N) for (int i = 1; i <= N; i++)
using namespace std;
long long INF = 1e18;
long long mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define debug 0

//各ノードからの有効グラフ
vector<vector<long long>> graph(200010);

int ans[200010] = {};
void dfs(int now, int before) {
  ans[now] = max(ans[now], before + 1);
  for (auto next : graph[now]) {
    dfs(next, before + 1);
  }
  return;
}
int main() {
  long long h, w, n;
  cin >> h >> w >> n;

  //行のソート用
  //<aの値,ノード番号>
  vector<multimap<long long, int>> mpH(h);
  vector<multimap<long long, int>> mpW(w);

  //入力
  rep(i, n) {
    long long r, c, a;
    cin >> r >> c >> a;
    r--, c--;
    mpH[r].insert(make_pair(a, i));
    mpW[c].insert(make_pair(a, i));
  }
  bool start[n] = {};
  //各行についてソートして連結
  rep(i, h) {
    auto it = mpH[i].begin();
    while (it != mpH[i].end()) {
      auto it2 = it;
      it2++;
      if (it2 == mpH[i].end() || it2->first == it->first) {
        it++;
        continue;
      }
      graph[it2->second].push_back(it->second);
      start[it->second] = true;
      
      //同じ数字が連続する時
      long long now = it2->first;
      while (1) {
        it2++;
        if (it2 == mpH[i].end() || now != it2->first) break;
#if debug
        cout << "same" << now << "=" << it2->first << endl;
        cout << "index " << it->second << " and " << it2->second << endl;
#endif
        graph[it2->second].push_back(it->second);
        start[it->second] = true;
      }
      it++;
    }
  }
  rep(i, w) {
    auto it = mpW[i].begin();
    while (it != mpW[i].end()) {
      auto it2 = it;
      it2++;
      if (it2 == mpW[i].end() || it2->first == it->first) {
        it++;
        continue;
      }
      //前と後ろを連結
      graph[it2->second].push_back(it->second);
      start[it->second] = true;

      //同じ数字が連続する時
      long long now = it2->first;
      while (1) {
        it2++;
        if (it2 == mpH[i].end() || now != it2->first) break;
#if debug
        cout << "same" << now << "=" << it2->first << endl;
        cout << "index " << it->second << " and " << it2->second << endl;
#endif
        graph[it2->second].push_back(it->second);
        start[it->second] = true;
      }
      it++;
    }
  }
  int st = -1;
  rep(i, n) {
    if (!start[i]) {
      st = i;
      break;
    }
  }
  // cout << st << endl;

  dfs(st, -1);
  rep(i, n) cout << ans[i] << endl;
}
/*
3 3 8
1 1 4
1 2 7
2 1 3
2 3 5
3 1 2
1 3 5
3 2 5
3 3 7


*/
