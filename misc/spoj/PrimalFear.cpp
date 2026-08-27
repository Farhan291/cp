// Url - https://www.spoj.com/problems/VECTAR8/
// Date: 27/08/26
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
const int M = 1e6 + 1;
vector<int> pref(M + 1);
vector<bool> sieve(M, true);
void sie() {
  sieve[0] = sieve[1] = false;
  for (int i = 2; i < M; i++) {
    if (sieve[i]) {
      for (int j = 2 * i; j < M; j += i) {
        sieve[j] = false;
      }
    }
  }
}
bool zero(int n) {
  while (n > 0) {
    if (n % 10 == 0)
      return true;
    n /= 10;
  }
  return false;
}

bool lefttrunc(int n) {
  while (n >= 10) {
    int p = 1;
    while (p <= n / 10) {
      p *= 10;
    }
    n %= p;
    if (!sieve[n])
      return false;
  }
  return true;
}
void precompute() {
  vector<int> ar(M + 1);
  for (int i = 1; i < M; i++) {
    if (sieve[i] && !zero(i) && lefttrunc(i)) {
      ar[i] = 1;
    }
  }
  for (int i = 1; i <= M; i++) {
    pref[i] = pref[i - 1] + ar[i - 1];
  }
}
void Mizuhara() {
  int n;
  cin >> n;
  cout << pref[n + 1] << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  sie();
  precompute();
  while (t--)
    Mizuhara();
}
