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
  int k;
  cin >> k;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int best = 0;
  int bestl = 0;
  int bestr = 0;
  for (int l = 0; l + k - 1 < n; l++) {
    int r = l + k - 1;
    int i = 0;
    int mex = 0;
    while (1) {
      auto a = find(v.begin() + l, v.begin() + r + 1, i);
      if (a == v.begin() + r + 1) {
        mex = i;
        if (mex > best) {
          best = mex;
          bestl = l;
          bestr = r;
        }
        break;
      }
      i++;
    }
    debug(best, i, bestl, bestr);
  }
  auto mini = min_element(v.begin() + bestl, v.begin() + bestr + 1);
  debug(v);
  v.erase(mini);
  debug(v);
  cerr << "end" << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
