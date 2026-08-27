// Url -
// Date: 06/08/26
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
  int n;
  cin >> n;
  vi b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vi c = b;
  sort(all(b));
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    m[b[i]]++;
  }
  if (!m.count(0)) {
    cout << -1 << nl;
    return;
  }
  b.erase(unique(all(b)), b.end());
  vi a;
  for (int i = 1; i < sz(b); i++) {
    int diff = b[i] - b[i - 1];
    if (diff % m[b[i - 1]] != 0) {
      cout << -1 << nl;
      return;
    }
    if (!a.empty() && diff / m[b[i - 1]] <= a.back()) {
      cout << -1 << nl;
      return;
    }
    a.pb(diff / m[b[i - 1]]);
  }
  if (a.empty())
    a.push_back(1);
  else
    a.push_back(a.back() + 1);
  debug(a);
  for
    for (auto x : a) {
      cout << x << " ";
    }
  cout << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
