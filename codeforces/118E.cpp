// Url - https://codeforces.com/contest/118/problem/E
// Date: 26/08/26
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
bool bridge = false;
vector<vector<int>> g;
vector<bool> vis;
vector<pii> ans;
vector<int> parent, depth, dp;
int dfs(int u, int p) {
  vis[u] = true;
  for (auto v : g[u]) {
    if (v == p)
      continue;
    if (!vis[v]) {
      depth[v] = depth[u] + 1;
      parent[v] = u;
      int c = dfs(v, u);
      dp[u] += c;
      if (c == 0) {
        bridge = true;
      }
      ans.pb({u, v});
    } else if (depth[u] > depth[v]) {
      dp[u]++;
      dp[v]--;
      ans.pb({u, v});
    }
  }
  return dp[u];
}
void Mizuhara() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  vis.resize(n + 1);
  parent.resize(n + 1);
  depth.resize(n + 1);
  dp.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1, 1);
  if (bridge) {
    cout << 0 << nl;
    return;
  }
  for (auto &[u, v] : ans) {
    cout << u << " " << v << nl;
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
