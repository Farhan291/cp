// Problem:
// Contest:
// URL:
// Time Limit:
// Start:
// atcoder
#include <atcoder/all>
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using namespace atcoder;
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
int M = 998244353;

int mul(int a, int b) { return (a * b) % M; }
int add(int a, int b) {
  a += b;
  return (a > M) ? a -= M : a;
}
int pow(int a, int b) {
  int res = 1;
  a %= M;
  while (b > 0) {
    if (b & 1)
      res = mul(res, a);
    a = mul(a, a);
    b >>= 2;
  }
  return res;
}
int myinv(int a) { return pow(a, M - 2); }
void Mizuhara() {
  int n;
  cin >> n;

  vector<int> fac(n + 1, 1);

  vector<int> inv(n + 1);
  for (int i = 2; i <= n; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  inv[n] = myinv(fac[n]);
  for (int i = n; i > 0; i--) {
    inv[i - 1] = mul(inv[i], i);
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
