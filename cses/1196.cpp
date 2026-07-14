// Url: https://cses.fi/problemset/task/1196
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
  }
  priority_queue<int> best[n + 1];
  priority_queue<pair<int, int>, vector<pii>, greater<pii>> pq;
  pq.push({0, 1});
  best[1].push(0);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > best[u].top())
      continue;
    for (auto [v, w] : g[u]) {
      int tmp = d + w;
      if (sz(best[v]) < k) {
        best[v].push(tmp);
        pq.push({tmp, v});
      } else if (best[v].top() > tmp) {
        best[v].pop();
        best[v].push(tmp);
        pq.push({tmp, v});
      }
    }
  }
  vi ans;
  while (!best[n].empty()) {
    ans.pb(best[n].top());
    best[n].pop();
  }
  reverse(all(ans));
  for (auto x : ans) {
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
