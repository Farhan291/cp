// Url -
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

  vector<int> dp(n, -1);
  dp[0] = 0;

  for (int i = 1; i < n; i++) {
    if (s[i] == 'w')
      continue;
    for (int j : {1, 3, 5}) {
      if (i - j >= 0 && dp[i - j] != -1)
        dp[i] = max(dp[i], dp[i - j]);
    }
    if (dp[i] != -1 && s[i] == '"')
      dp[i]++;
  }
  cout << dp[n - 1] << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("lepus.in", "r", stdin);
  freopen("lepus.out", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
