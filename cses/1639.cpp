// Url: https://cses.fi/problemset/task/1639
// Start: 24/07/26
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
  string n, m;
  cin >> n >> m;
  // dp[i][j] represent cost to transform first i characters of n to first j
  // chars of m
  vector<vector<int>> dp(sz(n) + 1, vector<int>(sz(m) + 1, 1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n.size(); i++)
    dp[i][0] = i;
  for (int j = 1; j <= m.size(); j++)
    dp[0][j] = j;
  for (int i = 1; i <= sz(n); i++) {
    for (int j = 1; j <= sz(m); j++) {
      // add char in n to match with m[j]
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      // remove char
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      // replace char
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (n[i - 1] != m[j - 1]));
    }
  }
  cout << dp[sz(n)][sz(m)];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
