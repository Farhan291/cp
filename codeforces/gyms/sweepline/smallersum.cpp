// Url - https://codeforces.com/group/7Dn3ObOpau/contest/503852/problem/A
// Date: 25/08/26
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

int sum(vector<int> &arr, int i) {
  int s = 0;
  while (i > 0) {
    s += arr[i];
    i -= (i & -i);
  }
  return s;
}
void update(int i, int v, vector<int> &arr) {
  while (i <= sz(arr)) {
    arr[i] += v;
    i += (i & -i);
  }
}

void Mizuhara() {
  int n;
  cin >> n;
  vector<pii> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.pb({x, i + 1});
  }
  int q;
  cin >> q;
  vector<tuple<int, int, int, int>> qs(q);
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    qs[i] = {l, r, x, i};
  }
  sort(all(v));
  sort(all(qs), [](tuple<int, int, int, int> &a, tuple<int, int, int, int> &b) {
    return get<2>(a) < get<2>(b);
  });
  int ptr = 0;
  vector<int> arr(n + 1);
  vector<int> ans(q + 1, -1);
  for (auto [l, r, x, i] : qs) {
    while (ptr < n && v[ptr].first <= x) {
      auto [val, i] = v[ptr];
      update(i, val, arr);
      ptr++;
    }
    ans[i] = sum(arr, r) - sum(arr, l - 1);
  }
  for (auto &x : ans) {
    if (x != -1) {
      cout << x << nl;
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
