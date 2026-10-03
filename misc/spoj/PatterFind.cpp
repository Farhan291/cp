// Url -  https://www.spoj.com/problems/NAJPF/
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
int M = 1e9 + 7;
void Mizuhara() {
  string t, p;
  cin >> t >> p;
  int ts = sz(t);
  int ps = sz(p);
  vector<int> ppow(max(ts, ps));
  ppow[0] = 1;
  for (int i = 1; i < max(ts, ps); i++) {
    ppow[i] = (ppow[i - 1] * 31) % M;
  }
  vector<int> ht(ts + 1);
  for (int i = 1; i <= ts; i++) {
    ht[i] = (ht[i - 1] + (t[i - 1] - 'a' + 1) * ppow[i - 1]) % M;
  }
  int hs = 0;
  for (int i = 0; i < ps; i++) {
    hs = (hs + (p[i] - 'a' + 1) * ppow[i]) % M;
  }
  vector<int> occur;
  for (int i = 0; i + ps <= ts; i++) {
    int cur_h = (ht[i + ps] - ht[i] + M) % M;
    if (cur_h == (hs * ppow[i]) % M)
      occur.pb(i + 1);
  }
  if (occur.empty()) {
    cout << "Not Found";
    return;
  }
  cout << sz(occur) << nl;
  for (auto &x : occur) {
    cout << x << " ";
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--) {
    Mizuhara();
    cout << nl << nl;
  }
}
