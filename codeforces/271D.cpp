// Url - https://codeforces.com/problemset/problem/271/D
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
  string s;
  cin >> s;
  string good;
  cin >> good;
  int k;
  cin >> k;
  vector<int> prefbad(sz(s) + 1);
  for (int i = 0; i < sz(s); i++) {
    prefbad[i + 1] = prefbad[i] + (good[s[i] - 'a'] == '0');
  }
  vector<int> ppow(sz(s));
  ppow[0] = 1;
  for (int i = 1; i < sz(s); i++) {
    ppow[i] = (ppow[i - 1] * 31) % M;
  }
  vector<int> hs(sz(s) + 1);
  for (int i = 1; i <= sz(s); i++) {
    hs[i] = (hs[i - 1] + (s[i - 1] - 'a' + 1) * ppow[i - 1]) % M;
  }
  set<int> st;
  for (int l = 1; l <= sz(s); l++) {
    for (int i = 0; i + l <= sz(s); i++) {
      if (prefbad[i + l] - prefbad[i] > k)
        continue;
      int cur_h = (hs[i + l] - hs[i] + M) % M;
      cur_h = (cur_h * ppow[sz(s) - i - 1]) % M;
      st.insert(cur_h);
    }
  }
  cout << sz(st);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
