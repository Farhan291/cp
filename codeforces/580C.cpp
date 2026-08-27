// Url -https://codeforces.com/problemset/problem/580/C
// Date: 07/07/26
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
int ans = 0;
void dfs(vector<vector<int>> &v, int ve, vector<int> &cat, int cnt, int m,
         int parent) {
  if (cat[ve])
    cnt++;
  else
    cnt = 0;

  if (cnt > m)
    return;

  bool isleaf = true;

  for (auto child : v[ve]) {
    if (child == parent)
      continue;
    dfs(v, child, cat, cnt, m, ve);
    isleaf = false;
  }
  if (isleaf) {
    ans++;
  }
}

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vector<int> cat(n + 1);
  vector<vector<int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> cat[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int s, d;
    cin >> s >> d;
    v[s].pb(d);
    v[d].pb(s);
  }
  int cnt = 0;
  dfs(v, 1, cat, cnt, m, 0);
  cout << ans << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
