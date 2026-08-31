// Url -
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

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<int> indeg(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    indeg[v]++;
  }
  queue<int> q;
  vector<int> topo;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    topo.pb(u);
    q.pop();
    for (auto v : g[u]) {
      if (--indeg[v] == 0) {
        q.push(v);
      }
    }
  }
  // dp[i] represent longest path till ith node
  vector<int> dp(n + 1, 0);
  for (auto &u : topo) {
    for (auto &v : g[u]) {
      dp[v] = max(dp[v], dp[u] + 1);
    }
  }
  cout << *max_element(all(dp));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("longpath.in", "r", stdin);
  freopen("longpath.out", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
