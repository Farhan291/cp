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
int n;
bool check(vi v, int k) {
  int del = n - k;
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1])
      if (del > 0) {
        del--;
        v.erase(v.begin() + i);
      }
    if (del == 0)
      break;
  }
  debug(del);
  bool done = false;
  debug(k, v);
  for (int i = 0; i < sz(v); i++) {
    if (v[i] == v[i - 1]) {
      if (done)
        return false;
      if (i == sz(v) - 1) {
        if (sz(v) > 3) {
          if (v[i] == v[i - 2] || v[i - 1] == v[i - 3])
            return false;
          continue;
        }
      }
      if (v[i - 1] == v[i + 1])
        return false;
      if (i != sz(v) - 1)
        swap(v[i], v[i + 1]);
      done = true;
    }
  }
  return true;
}

void Mizuhara() {
  cin >> n;
  cerr << n;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int lo = 1;
  int hi = n;
  int ans = 0;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(v, mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
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
