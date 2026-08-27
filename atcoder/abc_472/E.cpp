// Problem:
// Contest:
// URL:
// Time Limit:
// Start: 25/08/26
// atcoder
#include <atcoder/all>
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using namespace atcoder;
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
vector<int> color;
vector<vector<int>> g;
vector<int> parent;
vector<int> depth;
int badu = -1, badv = -1;
bool bipart(int node, int x) {
  color[node] = 1 ^ x;
  for (auto v : g[node]) {
    if (color[v] == -1) {
      parent[v] = node;
      depth[v] = depth[node] + 1;
      if (!bipart(v, color[node]))
        return false;
    } else if (color[v] == color[node]) {
      badu = node;
      badv = v;
      return false;
    }
  }
  return true;
}

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  g.assign(n + 1, {});
  color.assign(n + 1, -1);
  parent.assign(n + 1, -1);
  depth.assign(n + 1, 0);

  badu = badv = -1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  if (bipart(1, 0)) {
    cout << -1 << nl;
    return;
  }
  vi left, right;
  if (depth[badu] < depth[badv])
    swap(badu, badv);
  while (depth[badu] > depth[badv]) {
    left.pb(badu);
    badu = parent[badu];
  }
  while (badu != badv) {
    left.pb(badu);
    right.pb(badv);
    badu = parent[badu];
    badv = parent[badv];
  }
  left.pb(badu);
  reverse(right.begin(), right.end());
  for (int i = 1; i < sz(right); i++)
    left.pb(right[i]);
  cout << sz(left) << nl;
  for (auto &x : left) {
    cout << x << " ";
  }
  cout << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
