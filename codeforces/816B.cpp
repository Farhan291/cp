// Url - https://codeforces.com/contest/816/problem/B
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
  static int arr[200002] = {0};
  static int pref[200002] = {0};
  static int allow[200002] = {0};
  static int pallow[200002] = {0};

  int n, k, q;
  cin >> n >> k >> q;
  vector<pii> v(n);
  vector<pii> v1;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr[x]++;
    arr[y + 1]--;
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    v1.pb({x, y});
  }
  for (int i = 1; i <= 200000; i++) {
    pref[i] = pref[i - 1] + arr[i];
  }
  for (int i = 1; i <= 200000; i++) {
    if (pref[i] >= k) {
      allow[i] = 1;
    }
  }
  for (int i = 1; i <= 200000; i++) {
    pallow[i] = pallow[i - 1] + allow[i];
  }
  for (auto i : v1) {
    cout << pallow[i.second] - pallow[i.first - 1] << nl;
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
