// Url:
// Start: 05/08/26
// mintemplate
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
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

/*bool Mizuhara() {
  int n, k;
  if (!(cin >> n >> k))
    return false;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  deque<int> mini, maxi;
  vi a, b;
  int i = 0;
  for (int j = 0; j < n; j++) {
    while (!mini.empty() && v[mini.back()] > v[j]) {
      mini.pop_back();
    }
    while (!maxi.empty() && v[maxi.back()] < v[j]) {
      maxi.pop_back();
    }
    mini.pb(j);
    maxi.pb(j);
    if (j - i + 1 < k)
      continue;
    else {
      a.pb(v[mini.front()]);
      if (!mini.empty() && mini.front() == i)
        mini.pop_front();
      b.pb(v[maxi.front()]);
      if (!maxi.empty() && maxi.front() == i)
        maxi.pop_front();
      i++;
    }
  }
  for (int i = 0; i < sz(a); i++) {
    (i != sz(a) - 1) ? cout << a[i] << " " : cout << a[i] << nl;
  }
  for (int i = 0; i < sz(b); i++) {
    (i != sz(b) - 1) ? cout << b[i] << " " : cout << b[i] << nl;
  }
  return true;
}*/
void Mizuhara() {
  int n;
  cin >> n;
  vi nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  vi v;
  int mini = min({nums[0], nums[1], nums[2]});
  v.pb(mini);
  int cost = max({nums[0], nums[1], nums[2]});
  if (n == 4) {
    cost += max({mini, nums[3]});
  }
  for (int i = 3; i < n - 1; i++) {
    cost += max({mini, nums[i], nums[i + 1]});
    mini = min({mini, nums[i], nums[i + 1]});
    v.pb(mini);
    debug(i);
  }
  debug(v);
  cout << cost << nl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cin >> t;
  // while (Mizuhara())
  Mizuhara();
}
