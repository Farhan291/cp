// Url:https://www.spoj.com/problems/AGGRCOW/
// Start: 25/01/2026
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
bool check(vi v, int m, int c) {
  int prev = v[0];
  int count = 1;
  for (int i = 1; i < sz(v); i++) {
    if (v[i] - prev >= m) {
      count++;
      prev = v[i];
    }
  }
  debug(count, c);
  return count >= c;
}
void Mizuhara() {
  int n, c;
  cin >> n >> c;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(all(v));
  int l = 1;
  int h = 1e9;
  int ans = 0;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (check(v, m, c)) {
      debug(v, ans);
      ans = m;
      l = m + 1;
    } else {
      // debug(m);
      h = m - 1;
    }
  }
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
