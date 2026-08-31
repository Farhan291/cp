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
  vector<vector<int>> g(8, vi(8));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<int>> dp(9, vi(9, 10001));
  dp[7][1] = 0;
  for (int i = 7; i >= 0; i--) {
    for (int j = 1; j < 9; j++) {
      if (i == 7 && j == 1)
        continue;
      dp[i][j] =
          min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]}) + g[i][j - 1];
    }
  }
  cout << dp[0][8];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("king2.in", "r", stdin);
  freopen("king2.out", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
