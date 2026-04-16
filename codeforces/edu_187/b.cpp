// Url - https://codeforces.com/problemset/problem/2203/B
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
  string s;
  cin >> s;

  vi d;
  for (char c : s)
    d.pb(c - '0');

  int sum = accumulate(all(d), 0);

  if (sum <= 9) {
    cout << 0 << nl;
    return;
  }

  int n = sz(d);

  int rem1 = 9 - d[0];
  vi a = d;
  a.erase(a.begin());
  sort(all(a));

  int keep = 0, r = rem1;
  for (int x : a) {
    if (r - x < 0)
      break;
    r -= x;
    keep++;
  }

  int ans1 = (n - 1) - keep;

  int rem2 = 8;
  vi b = d;
  b.erase(b.begin());
  sort(all(b));

  keep = 0;
  r = rem2;

  for (int x : b) {
    if (r - x < 0)
      break;
    r -= x;
    keep++;
  }

  int ans2 = (n - 1) - keep + 1;

  cout << min(ans1, ans2) << nl;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
