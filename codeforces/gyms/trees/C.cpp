// Url - https://codeforces.com/gym/102694/problem/C
// Date: 09/08/26
// codeforces
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
template <typename T> void sort_unique(vector<T> &vec) {
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
}
const char nl = '\n';

#ifdef REZE
struct _debug {
  template <typename T> static void __print(const T &x) {
    if constexpr (is_fundamental_v<T> || is_convertible_v<T, string>) {
      cerr << x;
    } else {
      cerr << "{";
      for (auto i : x) {
        __print(i);
        cerr << " ";
      }
      cerr << "}";
    }
  }
  template <typename T, typename V> static void __print(const pair<T, V> &x) {
    cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')';
  }
  template <typename T, typename... V>
  static void _print(const T &t, const V &...v) {
    __print(t);
    if constexpr (sizeof...(v))
      cerr << ", ", _print(v...);
    else
      cerr << "]\n";
  }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif
vi parent, depth;
void dfs(vector<vi> &g, int s, int p) {
  parent[s] = p;
  for (auto v : g[s]) {
    if (v == p)
      continue;
    depth[v] = depth[s] + 1;
    dfs(g, v, s);
  }
}

void Mizuhara() {
  int n;
  cin >> n;
  int LOG = 1;
  while ((1 << LOG) <= n) {
    LOG++;
  }
  vector<vector<int>> g(n + 1);
  parent.resize(n + 1);
  parent[1] = 1;
  depth.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(g, 1, 1);
  vector<vector<int>> up(n + 1, vi(LOG, -1));
  for (int i = 1; i <= n; i++) {
    up[i][0] = parent[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 1; i <= n; i++) {
      up[i][j] = up[up[i][j - 1]][j - 1];
    }
  }
  auto lca = [&](int u, int v) {
    if (depth[v] > depth[u])
      swap(u, v);
    int k = depth[u] - depth[v];
    for (int j = 0; j < LOG; j++) {
      if (k & (1 << j)) {
        u = up[u][j];
      }
    }
    if (u == v)
      return u;
    for (int j = LOG - 1; j >= 0; j--) {
      if (up[u][j] != up[v][j]) {
        u = up[u][j];
        v = up[v][j];
      }
    }
    return up[u][0];
  };
  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    int l = lca(a, b);
    int dist = depth[a] + depth[b] - 2 * depth[l];
    if (dist <= c) {
      cout << b << nl;
      continue;
    }
    if (c <= depth[a] - depth[l]) {
      for (int j = 0; j < LOG; j++) {
        if (c & (1 << j)) {
          a = up[a][j];
        }
      }
      cout << a << nl;
      continue;
    }
    int k = dist - c;
    for (int j = 0; j < LOG; j++) {
      if (k & (1 << j)) {
        b = up[b][j];
      }
    }
    cout << b << nl;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
