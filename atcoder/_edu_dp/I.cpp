// Problem:
// Contest:
// URL:
// Time Limit:
// Start: 04/08/26
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
  vector<double> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  // dp[i][j] = probability of getting exactly j heads after tossing the first i
  // coins.
  vector<vector<double>> dp(n + 1, vector<double>(n + 1));
  dp[0][0] = 1;
  for (int coin = 1; coin <= n; coin++) {
    for (int heads = 0; heads <= coin; heads++) {
      if (heads == 0)
        dp[coin][heads] = dp[coin - 1][heads] * (1 - v[coin - 1]);
      else
        dp[coin][heads] = dp[coin - 1][heads - 1] * v[coin - 1] +
                          dp[coin - 1][heads] * (1 - v[coin - 1]);
    }
  }
  double ans = 0;
  for (int i = (n + 1) / 2; i <= n; i++) {
    ans += dp[n][i];
  }
  cout << fixed << setprecision(10) << ans << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
