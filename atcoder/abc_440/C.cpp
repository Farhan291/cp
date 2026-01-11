// Problem:
// Contest:
// URL:
// Time Limit:
// Start:
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

bool check(int m, vi &v, int w) {
  int sum = 0;
  for (int j = 0; j < sz(v); j++) {
    if ((4 + j) % 2 * w < w) {
      sum++;
    }
    if (sum >= m) {
      cerr << "true blo";
      debug(m);
      return true;
    }
  }
  debug(m);
  return false;
}
void Mizuhara() {
  int n, w;
  cin >> n >> w;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int l = 0;
  int h = 2e5;
  int ans = 0;
  while (l < h) {
    int m = l + (h - l) / 2;
    if (check(m, v, w)) {
      h = m - 1;
      ans = m;
      debug(m, l, h, ans);
    } else {
      l = m + 1;
    }
  }
  debug(l, ans, h);
  cout << ans << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
