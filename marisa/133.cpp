// Url: https://marisaoj.com/problem/133
// Start: 05/09/26
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
struct DSU {
  vector<int> parent;
  DSU(int n) {
    parent.resize(n + 2);
    for (int i = 1; i <= n + 1; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] == x)
      return x;
    else
      return parent[x] = find(parent[x]);
  }
  void occupy(int x) { parent[x] = find(x + 1); }
};
void Mizuhara() {
  int n;
  cin >> n;
  DSU d(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int s = d.find(x);
    if (s == n + 1) {
      cout << d.find(1) << " ";
      d.occupy(d.find(1));
    } else {
      cout << s << " ";
      d.occupy(s);
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
