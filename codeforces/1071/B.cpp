// Url -
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
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int best = -100;
  int s;
  for (int i = 0; i < n - 1; i++) {
    if (abs(v[i + 1] - v[i]) > best) {
      s = i;
      best = abs(v[i + 1] - v[i]);
      debug(s, best, i);
      continue;
    }
    debug(s, best, i);
  }
  if (v[n - 1] - v[n - 2] > best) {
    s = n - 1;
    best = abs(v[n - 1] - v[n - 2]);
  }
  debug(s, best);
  if (abs(v[s] - v[s - 1]) > abs(v[s + 1] - v[s])) {
    debug(v[s + 2], v[s + 1]);
    s = s + 1;
  }
  debug(s);
  v.erase(v.begin() + s);
  debug(v);
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    ans += abs(v[i] - v[i - 1]);
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
