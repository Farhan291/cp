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
const int INF = 1e18;
vector<int> pos;
int n, s, L;
map<pii, int> best;
int ans = 1;

void recur(int l, int r, int d) {
  if (d > L)
    return;
  auto key = make_pair(l, r);
  auto it = best.find(key);
  if (it != best.end() && it->second <= d)
    return;
  best[key] = d;
  ans = max(ans, r - l + 1);
  if (pos[l - 1] > -INF)
    recur(l - 1, r, d + (pos[l] - pos[l - 1]));
  if (pos[r + 1] < INF)
    recur(l, r + 1, d + (pos[r + 1] - pos[r]));
}

void Mizuhara() {
  cin >> n >> s >> L;
  pos.assign(n + 2, 0);
  pos[0] = -INF;
  pos[1] = 0;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    pos[i + 1] = pos[i] + x;
  }
  pos[n + 1] = INF;
  recur(s, s, 0);
  cout << ans << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
