#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep2(i, N) for (int i = 1; i <= N; i++)
using namespace std;
long long INF = 1e18;
long long mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define debug 0

/*
    ・併合時の工夫: union by size
    par[x]: x が根のときは x を含むグループのサイズ (の -1
   倍)、そうでないときは親ノード

    issame(x, y): x と y が同じグループにいるか, 計算量はならし O(α(n))
    merge(x, y): x と y を同じグループにする, 計算量はならし O(α(n))
    size(x): x を含むグループの所属メンバー数
*/
struct UnionFind {
  vector<int> par;
  vector<int> child;
  vector<int> distFromTop;

  UnionFind() {}
  UnionFind(int n) : par(n, -1), child(n, -1), distFromTop(n, 0) {}
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0)
      return x;
    else {
      return root(par[x]);
    }
  }
  int end(int x) {
    if (child[x] < 0)
      return x;
    else {
      distFromTop[child[x]] = distFromTop[x] + 1;
      return end(child[x]);
    }
  }
  //枝の先端までの距離
  int getEndDist(int x, int d) {
    if (child[x] < 0)
      return d;
    else
      return getEndDist(child[x], d + 1);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    // y = root(y);
    child[x] = y;
    // x = root(x);

    if (x == y) return false;
    // if (par[x] > par[y]) swap(x, y);  // merge technique
    par[root(x)] += size(y);
    par[y] = x;
    // child
    // child[x] = y;
    distFromTop[y] = size(root(x));
    end(y);
    return true;
  }
  // bool dispath(int x, int y) { par[root(x)] -=

  int size(int x) { return -par[root(x)]; }

  int getDistFromTop(int x) { return distFromTop[x] - 1; }

  int dispath(int x, int y) {
    child[x] = -1;
    par[y] = -1;

    // child
    par[root(x)] -= getDistFromTop(end(y)) + 1;
    distFromTop[y] -= getDistFromTop(x);
    end(y);
    return true;
  }
  int showElem(int x) {
    cout << x + 1 << " ";
    if (child[x] < 0)
      return 0;
    else {
      return showElem(child[x]);
    }
  }
};

int main() {
  long long n, q;
  cin >> n >> q;
  UnionFind uf(n);

  rep(i, q) {
    long long a, x, y;
    cin >> a;
    if (a == 1) {
      cin >> x >> y;
      x--, y--;
      uf.merge(x, y);
    } else if (a == 2) {
      cin >> x >> y;
      x--, y--;
      uf.dispath(x, y);
    } else {
      cin >> x;
      x--;
      cout << uf.size(x) << " ";
      uf.showElem(x);
      cout << endl;
#if 1  // debug
      cout << x << "のsize: " << uf.size(x) << endl;
      cout << x << "のend: " << uf.end(x) << endl;
      cout << x << "のendまでの距離: " << uf.getDistFromTop(x) << endl;
      // cout << 4 << "のendまでの距離: " << uf.getDistFromTop(4) << endl;

      // cout << "c==3 query!" << endl;
#endif
    }
  }
}
/*
例

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

7 8
1 6 3
1 4 1
1 5 2
1 2 7
1 3 5
3 2
3 4
3 6

7 6
1 6 3
1 4 1
1 5 2
1 2 7
1 3 5
3 2



*/
