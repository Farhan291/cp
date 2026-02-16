// Url - https://codeforces.com/contest/300/problem/C
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
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e6;

template <typename T, int MOD, int MAXN> struct Combinator {
  vector<T> fact, invfact;

  static T binpow(T a, long long b) {
    T ans = 1;
    while (b) {
      if (b & 1)
        ans = (ans * a) % MOD;
      a = (a * a) % MOD;
      b >>= 1;
    }
    return ans;
  }
  Combinator() {
    fact.resize(MAXN + 1);
    invfact.resize(MAXN + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
      fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXN] = binpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) {
      invfact[i - 1] = invfact[i] * i % MOD;
    }
  }
  T ncr(T a, T b) {
    if (a < 0 || b > a)
      return 0;
    return ((fact[a] * invfact[b]) % MOD * invfact[a - b]) % MOD;
  }
  T dearrangement(T a) {
    if (a < 0)
      return 0;
    T ans = 1;
    for (int k = 1; k <= a; k++) {
      if (k & 1) {
        ans = (ans - invfact[k] + MOD) % MOD;
      } else {
        ans = (ans + invfact[k]) % MOD;
      }
    }
    return ((fact[a] * ans) % MOD);
  }
};
Combinator<long long, MOD, MAXN> c;
bool check(int a, int b, int n) {
  if (n == 0)
    return false;
  int temp = n;
  while (temp) {
    int d = temp % 10;
    if (d != a && d != b) {
      return false;
    }
    temp /= 10;
  }
  return true;
}

void Mizuhara() {
  int a, b, n;
  cin >> a >> b >> n;
  int cnt = 0;
  int m = 1e9 + 7;

  for (int i = 0; i <= n; i++) {
    int sum = a * i + (n - i) * b;
    if (check(a, b, sum)) {
      cnt = (cnt + c.ncr(n, i)) % MOD;
    }
  }
  cout << cnt % MOD;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
