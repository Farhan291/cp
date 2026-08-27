// Url -
// Date: 07/08/26
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

void Mizuhara() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c0 = 0, c1 = 0;
  for (auto x : s) {
    if (x == '0')
      c0++;
    else
      c1++;
  }
  // dp[i][j] represent longest alternate subsequnce ending on i with j as
  // startchar endingchar 0->00 1->01 2->10 3->11
  vector<vector<int>> dp(n + 1, vector<int>(4, -1e9));
  if (s[0] == '0') {
    dp[0][0] = 1;
  } else {
    dp[0][3] = 1;
  }
  for (int i = 1; i < n; i++) {
    // skip s[i]
    for (int j = 0; j < 4; j++) {
      dp[i][j] = dp[i - 1][j];
    }
    if (s[i] == '0') {
      if (dp[i - 1][1] != -1e9)
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
      if (dp[i - 1][3] != -1e9)
        dp[i][2] = max(dp[i][2], dp[i - 1][3] + 1);
      // las start at i
      dp[i][0] = max(dp[i][0], 1ll);
    } else {
      if (dp[i - 1][0] != -1e9)
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
      if (dp[i - 1][2] != -1e9)
        dp[i][3] = max(dp[i][3], dp[i - 1][2] + 1);
      // las start at i
      dp[i][3] = max(dp[i][3], 1ll);
    }
  }
  int ans = -1;
  int original_diff = c1 - c0;
  for (int j = 0; j < 4; j++) {
    int kept_diff;
    if (j == 0)
      kept_diff = -1;
    else if (j == 1 || j == 2)
      kept_diff = 0;
    else
      kept_diff = 1;
    if (abs(original_diff - kept_diff) <= 1) {
      ans = max(ans, dp[n - 1][j]);
    }
  }
  if (ans == -1) {
    cout << -1 << nl;
    return;
  }
  cout << n - ans << nl;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
