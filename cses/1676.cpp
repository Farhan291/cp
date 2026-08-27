// Url: https://cses.fi/problemset/task/1676
// Start: 13/07/26
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
vi parent(2e5 + 1);
vi sizes(2e5 + 1, 1);
void make(int x) { parent[x] = x; }
int find(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}
bool Union(int a, int b) {
  int ra = find(a);
  int rb = find(b);
  if (ra != rb) {
    if (sizes[ra] < sizes[rb]) {
      swap(ra, rb);
    }
    parent[rb] = ra;
    sizes[ra] += sizes[rb];
    return true;
  }
  return false;
}
void Mizuhara() {
  int n, m;
  cin >> n >> m;
  int cmpt = n;
  int maxi = 1;
  for (int i = 1; i <= n; i++)
    make(i);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (Union(a, b)) {
      cmpt--;
      maxi = max(sizes[find(a)], maxi);
      cout << cmpt << " " << maxi << nl;
    } else {
      cout << cmpt << " " << maxi << nl;
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
