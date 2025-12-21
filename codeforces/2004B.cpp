// Url -https://codeforces.com/problemset/problem/2004/B
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
  pii p1;
  cin >> p1.first >> p1.second;
  pii p2;
  cin >> p2.first >> p2.second;
  auto mini = [](pii a, pii b) -> pii { return a.first < b.first ? a : b; };
  auto maxi = [](pii a, pii b) -> pii { return a.first > b.first ? a : b; };
  pii mi = mini(p1, p2);
  pii mx = maxi(p1, p2);
  int ans = 0;
  if (mi.second < mx.first) {
    cout << 1 << nl;
    return;
  }
  if (p1 == p2) {
    ans = p1.second - p1.first;
    debug(ans, p1, p2);

  } else {
    debug(ans, p1, p2);
    int temp = min(p1.second, p2.second);
    ans += temp - mx.first;
    if (mi.second == mx.second) {
      ans += 1;
    } else {
      ans += 2;
    }
    debug(ans, p1, p2);
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
