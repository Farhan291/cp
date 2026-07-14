// Url: https://cses.fi/problemset/task/1195
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
  vector<vector<pair<int, int>>> rg(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    rg[v].pb({u, w});
  }
  vector<int> sdist(n + 1, 4e18);
  vector<int> ddist(n + 1, 4e18);
  set<pair<int, int>> ss;
  set<pair<int, int>> sd;
  sdist[1] = 0;
  ddist[n] = 0;
  ss.insert({0, 1});
  sd.insert({0, n});
  while (!ss.empty()) {
    auto [d, u] = *ss.begin();
    ss.erase(ss.begin());
    if (sdist[u] != d)
      continue;
    for (auto [v, w] : g[u]) {
      if (d + w < sdist[v]) {
        sdist[v] = d + w;
        ss.insert({sdist[v], v});
      }
    }
  }
  while (!sd.empty()) {
    auto [d, u] = *sd.begin();
    sd.erase(sd.begin());
    if (ddist[u] != d)
      continue;
    for (auto [v, w] : rg[u]) {
      if (d + w < ddist[v]) {
        ddist[v] = d + w;
        sd.insert({ddist[v], v});
      }
    }
  }
  int mini = LONG_MAX;
  for (int i = 1; i <= n; i++) {
    for (auto x : g[i]) {
      int src = sdist[i];
      int edge = x.second / 2;
      int dest = ddist[x.first];
      mini = min(mini, src + edge + dest);
    }
  }
  cout << mini << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
