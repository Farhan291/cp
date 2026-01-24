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

void Mizuhara() {
  int n, q;
  cin >> n >> q;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  debug(v);
  vi pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + v[i];
  }
  debug(pref);
  vector<vector<int>> v1(q);
  for (int i = 0; i < q; i++) {
    int x, y, z;
    cin >> x;
    if (x == 1) {
      cin >> y;
      v1[i].pb(x);
      v1[i].pb(y);
    } else {
      cin >> y >> z;
      v1[i].pb(x);
      v1[i].pb(y);
      v1[i].pb(z);
    }
  }
  debug(v1);
  for (auto i : v1) {
    if (i[0] == 1) {
      pref[i[1]] -= v[i[1] - 1];
      pref[i[1]] += v[i[1]];

      int temp = v[i[1] - 1];
      v[i[1] - 1] = v[i[1]];
      v[i[1]] = temp;
      debug(pref);
    } else {
      debug(i[2] + 1, i[1], i[0]);
      int sum = 0;
      debug(pref[i[2]]);
      debug(pref[i[1] - 1]);
      sum = pref[i[2]] - pref[i[1] - 1];

      cout << sum << nl;
    }
  }
  debug(v);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
