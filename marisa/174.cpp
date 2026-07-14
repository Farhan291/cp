// Url: https://marisaoj.com/problem/174
// Start:
// mintemplate
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
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  set<pair<int, int>> s;
  vector<int> dist(n + 1, 4e18);
  vector<int> parent(n + 1, -1);
  dist[1] = 0;
  s.insert({0, 1});
  while (!s.empty()) {
    auto x = *s.begin();
    int u = x.second;
    int d = x.first;
    s.erase(x);
    if (dist[u] != d)
      continue;
    for (auto z : g[u]) {
      if (dist[u] + z.second < dist[z.first]) {
        dist[z.first] = dist[u] + z.second;
        parent[z.first] = u;
        s.insert({dist[z.first], z.first});
      }
    }
  }
  vector<int> path;
  int cur = n;
  while (cur != -1) {
    path.pb(cur);
    cur = parent[cur];
  }
  reverse(all(path));
  if (dist[n] == 4e18) {
    cout << -1 << nl;
    return;
  }
  cout << dist[n] << nl;
  for (auto x : path) {
    cout << x << " ";
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
