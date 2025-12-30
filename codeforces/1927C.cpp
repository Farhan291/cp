// Url -https://codeforces.com/problemset/problem/1927/C
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
  int n, m, k;
  cin >> n >> m >> k;
  vi v(n);
  vi v1(m);
  set<int> s;
  set<int> s1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> v1[i];
  }
  for (auto i : v) {
    if (i <= k) {
      s.insert(i);
    }
  }
  for (auto j : v1) {
    if (j <= k) {
      s1.insert(j);
    }
  }
  int x = 0;
  int z = 0;
  int comm = 0;
  for (int i = 1; i <= k; i++) {
    if (s.find(i) != s.end() && s1.find(i) != s1.end()) {
      comm++;
      continue;
    }
    if (s.find(i) != s.end()) {
      x++;
    } else if (s1.find(i) != s1.end()) {
      z++;
    } else {
      cerr << "ne";
      debug(x, z, s, s1);

      cout << "NO" << nl;
      return;
    }
    if (x > k / 2 || z > k / 2) {
      cerr << "ni";
      debug(x, z, s, s1);

      cout << "NO" << nl;
      return;
    }
  }
  if (comm != (k / 2 - x) + (k / 2 - z)) {
    cout << "NO" << nl;
    return;
  }

  debug(x, z, s, s1, comm, k);
  cout << "YES" << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
