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
  int maxi = 0;
  pii best = {0, 0};
  vector<int> one;
  vector<int> minus;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1)
      one.pb(i);
    if (x == -1)
      minus.pb(i);
    v[i] = x;
  }
  for (int i = 0; i < n; i++) {
    if (v[i] == 1) {
      if (upper_bound(all(one), i) != one.end()) {
        int cur = *upper_bound(all(one), i) - i;
        if (cur > maxi) {
          maxi = cur;
          best = {i, cur + i};
        }
      } else {
        if (!minus.empty() && minus.back() > i) {
          int cur = minus.back() - i;
          if (cur > maxi) {
            maxi = cur;
            best = {i, cur + i};
          }
        }
      }
    }
    if (v[i] == -1) {
      debug(upper_bound(all(one), i) - one.begin(), i);
      if (upper_bound(all(one), i) == one.end()) {
        int cur = minus.back() - i;
        if (cur > maxi) {
          maxi = cur;
          best = {i, cur + i};
        }
      } else {
        int cur = *upper_bound(all(one), i) - i;
        if (cur > maxi) {
          maxi = cur;
          best = {i, cur + i};
        }
      }
    }
  }
  debug(one, minus);
  debug(best, maxi);
  if (maxi == 0) {
    if (!minus.empty())
      v[minus[0]] = 1;

    for (auto x : v)
      cout << x << " ";
    cout << nl;
    return;
  }
  if (v[best.first] == -1)
    v[best.first] = 1;
  if (v[best.second] == -1)
    v[best.second] = 1;
  for (int i = best.first + 1; i < best.second; i++) {
    if (v[i] == -1)
      v[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (v[i] == -1)
      v[i] = 0;
  }
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--) {
    Mizuhara();
    cerr << t << nl;
  }
}
