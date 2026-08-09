// Url: https://cses.fi/problemset/task/1646
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
vi tree;
int f(int node, int node_low, int node_high, int query_low, int query_high) {
  if (node_low >= query_low && node_high <= query_high)
    return tree[node];
  if (node_high < query_low || node_low > query_high)
    return 0;
  int left_id = (node_low + node_high) / 2;
  return f(2 * node, node_low, left_id, query_low, query_high) +
         f(2 * node + 1, left_id + 1, node_high, query_low, query_high);
}

void Mizuhara() {
  int n, q;
  cin >> n >> q;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  while (__builtin_popcount(n) != 1) {
    v.pb(0);
    n++;
  }
  tree.resize(2 * n);
  for (int i = 0; i < n; i++) {
    tree[n + i] = v[i];
  }
  for (int i = n - 1; i > 0; i--) {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << f(1, 0, n - 1, a - 1, b - 1) << nl;
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
