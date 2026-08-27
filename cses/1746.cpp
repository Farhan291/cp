// Url: https://cses.fi/problemset/task/1746
// Start: 21/07/26
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
  int n, m;
  int M = 1e9 + 7;
  cin >> n >> m;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  // dp[i][x] represent how many ways to have array with ith position as x
  vector<vector<int>> dp(n, vector<int>(m + 1));
  if (v[0] == 0) {
    for (int i = 1; i <= m; i++) {
      dp[0][i] = 1;
    }
  } else {
    dp[0][v[0]] = 1;
  }
  for (int i = 1; i < n; i++) {    // for every index from 1 to n-2
    for (int j = 1; j <= m; j++) { // for every no. from 0 to m
      for (auto z : {j, j + 1, j - 1}) {
        if (1 <= z && z <= m) {
          if (v[i] != 0 && v[i] != z)
            continue;
          dp[i][z] = (dp[i][z] + dp[i - 1][j]) % M;
        }
      }
    }
  }
  int ans = 0;
  for (auto x : dp[n - 1]) {
    ans = (ans + x) % M;
  }
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
