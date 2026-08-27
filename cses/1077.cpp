// Url: https://cses.fi/problemset/task/1077
// Start: 30/07/26
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

void Mizuhara() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  multiset<int> l, r;
  int lsum = 0, rsum = 0;
  for (int i = 0; i < k; i++) {
    l.insert(v[i]);
    lsum += v[i];
  }
  while (sz(l) > (k + 1) / 2) {
    r.insert(*prev(l.end()));
    rsum += *prev(l.end());
    lsum -= *prev(l.end());
    l.erase(prev(l.end()));
  }
  if (k & 1) {
    int med = *prev(l.end());
    int cost = sz(l) * med - lsum + rsum - sz(r) * med;
    cout << cost << " ";
  } else {
    int med = (*prev(l.end()) + *r.begin()) / 2;
    int cost = sz(l) * med - lsum + rsum - sz(r) * med;
    cout << cost << " ";
  }
  for (int i = k; i < n; i++) {
    if (v[i] <= *prev(l.end())) {
      l.insert(v[i]);
      lsum += v[i];
    } else {
      r.insert(v[i]);
      rsum += v[i];
    }
    if (v[i - k] <= *prev(l.end())) {
      l.extract(v[i - k]);
      lsum -= v[i - k];
    } else {
      r.extract(v[i - k]);
      rsum -= v[i - k];
    }
    while (sz(l) < (k + 1) / 2) {
      l.insert(*r.begin());
      lsum += *r.begin();
      rsum -= *r.begin();
      r.erase(r.begin());
    }
    while (sz(l) > (k + 1) / 2) {
      r.insert(*prev(l.end()));
      rsum += *prev(l.end());
      lsum -= *prev(l.end());
      l.erase(prev(l.end()));
    }
    if (k & 1) {
      int med = *prev(l.end());
      int cost = sz(l) * med - lsum + rsum - sz(r) * med;
      cout << cost << " ";
    } else {
      int med = (*prev(l.end()) + *r.begin()) / 2;
      int cost = sz(l) * med - lsum + rsum - sz(r) * med;
      cout << cost << " ";
    }
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
