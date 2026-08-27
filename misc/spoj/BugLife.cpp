// Url - https://www.spoj.com/problems/BUGLIFE/
// Date: 10/07/26
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
bool dfs(vector<vector<int>> &v, int ve, vector<int> &b, int color) {
  b[ve] = color;
  for (auto x : v[ve]) {
    if (b[x] == -1) {
      if (!dfs(v, x, b, 1 - color)) {
        return false;
      }
    } else if (b[x] == color)
      return false;
  }
  return true;
}

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 1);
  vector<int> b(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == -1) {
      bool ans = dfs(v, i, b, 0);
      if (!ans) {
        cout << "Suspicious bugs found!" << nl;
        return;
      }
    }
  }
  cout << "No suspicious bugs found!" << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int j = 0;
  int t = 0;
  cin >> t;
  while (++j <= t) {
    cout << "Scenario #" << j << ":" << nl;
    Mizuhara();
  }
}
