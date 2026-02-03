// Url: https://cses.fi/problemset/task/1755
// Start:
// mintemplate
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
  int c[26] = {};
  for (char i : s) {
    c[i - 'A']++;
  }
  vector<pair<char, int>> v;
  for (int i = 0; i < 26; i++) {
    if (c[i] != 0) {
      v.pb({i + 'A', c[i]});
    }
  }
  debug(v);
  int o = 0;
  string ans;
  for (auto i : v) {
    if (i.second & 1) {
      o++;
    }
  }
  if (o > 1) {
    cout << "NO SOLUTION";
    return;
  }
  char k = '\0';
  for (auto i : v) {
    if (i.second >= 2) {
      for (int j = 0; j < i.second / 2; j++) {
        ans += i.first;
      }
    }
    if (i.second & 1) {
      k = i.first;
    }
  }
  debug(ans);
  debug(k);
  string rev;
  if (k == '\0') {
    rev = ans;
  } else {
    rev = ans + k;
  }
  debug(rev);
  reverse(all(rev));
  debug(rev);
  cout << ans + rev << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
