// Url -  https://codeforces.com/problemset/problem/1082/E
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
const int M = 5e5 + 1;
void Mizuhara() {
  int n, c;
  cin >> n >> c;
  vector<int> ar(n);
  vector<int> fre(M);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ar[i] = x;
    fre[x]++;
  }
  // prefc
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (ar[i - 1] == c);
  }
  auto cntc = [&](int l, int r) { return pref[r + 1] - pref[l]; };
  // compress kadane
  vector<int> lst(M, -1);
  vector<int> cur(M);
  vector<int> best(M);
  for (int i = 0; i < n; i++) {
    int &v = ar[i];

    // before first d
    int gaps = cntc(lst[v] + 1, i - 1);
    cur[v] = max(0LL, cur[v] - gaps);
    best[v] = max(best[v], cur[v]);

    cur[v] = max(0LL, cur[v] + 1);
    best[v] = max(best[v], cur[v]);

    lst[v] = i;
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    if (fre[i] == 0)
      continue;
    if (i == c)
      continue;
    int gaps = cntc(lst[i] + 1, n - 1);
    cur[i] = max(0LL, cur[i] - gaps);
    best[i] = max(best[i], cur[i]);
    ans = max(best[i], ans);
  }
  cout << ans + cntc(0, n - 1) << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
