// Problem:
// Contest:
// URL: https://atcoder.jp/contests/dp/tasks/dp_c
// Time Limit:
// Start: 16/07/26
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
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> v[i][j];
    }
  }
  vector<vector<int>> dp(n + 1);
  int prev = -1;
  int maxi = max({v[0][0], v[0][1], v[0][2]});
  for (int i = 0; i < 3; i++) {
    if (v[0][i] == maxi)
      prev = i;
  }
  dp[0][prev] = maxi;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == prev)
        continue;
      dp[i][j] = max(dp[i][j], dp[i - 1][prev] + v[i][j]);
      prev = max(dp[i][(prev + 1) % 3], dp[i][(prev + 2) % 3]);
    }
  }
  cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
