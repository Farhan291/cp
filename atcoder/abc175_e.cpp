// Problem:
// Contest:
// URL:
// Time Limit:
// Start: 12/08/26
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

void Mizuhara() {
  int r, c, k;
  cin >> r >> c >> k;
  vector<vector<int>> g(r, vi(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<vector<int>>> dp(r, vector<vi>(c, vi(4)));
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;
  for (int k = 2; k < 4; k++) {
    dp[0][0][k] = 0;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < 4; k++) {
        if (i == 0 && j == 0)
          continue;
        if (j - 1 >= 0 && k - 1 >= 0)
          dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[i][j]);
        if (j - 1 >= 0)
          dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
        if (i - 1 >= 0)
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
        if (i - 1 >= 0)
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] + g[i][j]);
      }
    }
  }
  cout << dp[r - 1][c - 1][3];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
