// Url: https://cses.fi/problemset/task/1091
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

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vi p(n);
  vi c(m);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  sort(all(p));
  debug(p);
  int i = 0;
  int j = 0;
  vi ans;
  int temp = -1;
  while (i < n && j < m) {
    if (p[i] <= c[j]) {
      temp = c[j] - p[i];
      debug(p[i], c[j], i, j, temp);
      i++;
    } else {
      if (temp != -1) {
        ans.pb(c[j] - temp);
        debug(c[j] - temp);
        temp = -1;
        j++;
      } else {
        ans.pb(-1);
        j++;
      }
    }
  }
  ans.pb(c[j] - temp);
  j++;
  while (j < m) {
    ans.pb(-1);
    j++;
  }
  debug(ans);
  for (auto i : ans) {
    cout << i << nl;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
