// Url - https://codeforces.com/problemset/problem/1473/E
// Date: 14/08/26
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
  int INF = 4e18;
  cin >> n >> m;
  vector<vector<pii>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  vector<vector<vector<int>>> dist(n + 1, vector<vi>(2, vi(2, INF)));
  dist[1][0][0] = 0; // f1-> 1 if max used  , f2-> 1 if min used
  set<tuple<int, int, int, int>> s;
  s.insert({0, 1, 0, 0});
  while (!s.empty()) {
    auto [d, u, f1, f2] = *s.begin();
    s.erase(s.begin());
    if (dist[u][f1][f2] != d)
      continue;
    for (auto [v, w] : g[u]) {
      if (f1 == 0 && d < dist[v][1][f2]) {
        dist[v][1][f2] = d;
        s.insert({d, v, 1, f2});
      }
      if (f2 == 0 && d + 2LL * w < dist[v][f1][1]) {
        dist[v][f1][1] = d + 2LL * w;
        s.insert({d + 2LL * w, v, f1, 1});
      }
      if (d + w < dist[v][f1][f2]) {
        dist[v][f1][f2] = d + w;
        s.insert({d + w, v, f1, f2});
      }
      if (f1 == 0 && f2 == 0 && d + w < dist[v][1][1]) {
        dist[v][1][1] = d + w;
        s.insert({d + w, v, 1, 1});
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    cout << dist[i][1][1] << " ";
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
