// Url - https://codeforces.com/contest/702/problem/C
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
bool check(vi &c, vi &t, int k) {
  int j = 0;
  for (int i = 0; i < sz(t); i++) {
    int l = t[i] - k;
    int r = t[i] + k;
    while (j < sz(c) && c[j] >= l && c[j] <= r) {
      j++;
    }
  }
  return j == sz(c);
}

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vi c(n);
  vi t(m);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  int lo = 0;
  int hi = 1e13;
  int ans = 0;
  while (lo <= hi) {
    int mid = (hi - lo) / 2 + lo;
    if (check(c, t, mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
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

dp[0] = v[0];
for (int i = 1; i < n; i++) {
  for (int j : {1, 2}) {
    for (int k : {1, 2}) {
      if (j == 2 && k == j)
        continue;
      dp[i][k] = min(dp[i][k], dp[i - j][j]);
    }
  }
}

for (int i = 0; i < n; i++) {
  for (int j = 0; j < i; j++) {
    if (arr[i] > arr[j]) {
      dp[i][sum] = max(dp[i], dp[j] + 1);
    }
  }
}
