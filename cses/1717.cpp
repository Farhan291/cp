// Url: https://cses.fi/problemset/task/1717
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
int MAXN = 1e6;
int MOD = 1e9 + 7;
vector<int> fact(MAXN + 1);
vector<int> invfact(MAXN + 1);
void precompute() {
  fact[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  int b = MOD - 2;
  int ans = 1;
  int a = fact[MAXN];
  a %= MOD;
  while (b) {
    if (b & 1)
      ans = (a * ans) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  invfact[MAXN] = ans;
  for (int i = MAXN; i > 0; i--) {
    invfact[i - 1] = invfact[i] * i % MOD;
  }
}

void Mizuhara() {
  int n;
  cin >> n;
  int ans = 1;
  for (int k = 1; k <= n; k++) {
    if (k & 1) {
      ans = (ans - invfact[k] + MOD) % MOD;
    } else {
      ans = (ans + invfact[k]) % MOD;
    }
  }
  cout << ((fact[n] * ans) % MOD) << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  precompute();
  // cin >> t;
  while (t--)
    Mizuhara();
}
