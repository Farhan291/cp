// Url: https://cses.fi/problemset/task/1202
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
  int M = 1e9 + 7;
  vector<vector<pii>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
  }
  set<pii> s;
  vi num(n + 1, 0);
  vi dist(n + 1, 4e18);
  vi mini(n + 1, 0);
  vi maxi(n + 1, 0);
  dist[1] = 0;
  num[1] = 1;
  mini[1] = maxi[1] = 0;
  s.insert({0, 1});
  while (!s.empty()) {
    auto [d, u] = *s.begin();
    s.erase(s.begin());
    if (dist[u] != d)
      continue;
    for (auto [v, w] : g[u]) {
      if (d + w == dist[v]) {
        num[v] = (num[v] + num[u]) % M;
        mini[v] = min(mini[v], mini[u] + 1);
        maxi[v] = max(maxi[v], maxi[u] + 1);
      }
      if (d + w < dist[v]) {
        dist[v] = d + w;
        s.insert({dist[v], v});
        mini[v] = mini[u] + 1;
        maxi[v] = maxi[u] + 1;
        num[v] = num[u]; // delete any old num[v] ways to reach v with old
                         // dist[v] & update with new way to reach num[u]
      }
    }
  }
  cout << dist[n] << " " << num[n] << " " << mini[n] << " " << maxi[n] << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
