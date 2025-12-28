// Problem:B
// Contest:abc438
// URL:https://atcoder.jp/contests/abc438/tasks/abc438_b
// Time Limit:
// Start: 17:58 27/12/25
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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s;
  cin >> t;
  int best = INT_MAX;
  for (int i = 0; i < n; i++) {
    int temp = 0;
    for (int j = 0; j < m; j++) {
      if (i + j >= n) {
        cerr << "y";
        debug(i, j, temp, best);
        goto ANS;
      }
      int d = s[j + i] - '0';
      int tt = t[j] - '0';
      int c = 0;
      debug(d, tt, c);
      while (d != tt) {
        ++tt;
        tt %= 10;
        ++c;
      }
      debug(d, tt, c);
      temp += c;
      debug(temp, i, j, best);
    }
    debug(temp);
    if (temp < best) {
      best = temp;
    }
  }
ANS:
  cout << best << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
