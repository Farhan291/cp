// Url: https://cses.fi/problemset/task/1628/
// Start:
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
void subset(vector<int> &v, int idx, int sum, int end, vector<int> &sub) {
  if (idx == end) {
    sub.pb(sum);
    return;
  }

  subset(v, idx + 1, sum + v[idx], end, sub);
  subset(v, idx + 1, sum, end, sub);
}

void Mizuhara() {
  int n, x;
  cin >> n >> x;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> left, right;
  subset(v, 0, 0, n / 2, left);
  subset(v, n / 2, 0, n, right);
  sort(all(right));
  sort(all(left));
  int ans = 0;
  for (auto i : left) {
    auto l = lower_bound(all(right), x - i);
    auto r = upper_bound(all(right), x - i);
    ans += r - l;
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
