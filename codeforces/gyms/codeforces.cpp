// Url - https://codeforces.com/group/j8QJucdRBd/contest/685273/problem/B
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
  int n, q;
  cin >> n >> q;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  debug(v);
  vector<int> cpy = v;
  sort(all(cpy));
  cpy.erase(unique(all(cpy)), cpy.end());
  debug(cpy);
  vector<int> comp(n);
  vector<vector<int>> pos(sz(cpy));
  for (int i = 0; i < n; i++) {

    comp[i] = lower_bound(all(cpy), v[i]) - cpy.begin();
    debug(comp[i], v[i]);
    pos[comp[i]].pb(i);
  }
  debug(comp);
  debug(pos);
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;
    int cmi = lower_bound(all(cpy), x) - cpy.begin();
    if (cmi == sz(cpy) || cpy[cmi] != x) {
      cout << 0 << nl;
      continue;
    }
    cout << upper_bound(all(pos[cmi]), r) - lower_bound(all(pos[cmi]), l) << nl;
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
