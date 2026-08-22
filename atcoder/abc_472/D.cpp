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

void Mizuhara() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<char>> g(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> g[i][j];
    }
  }
  // 0->safe , 1->not safe
  vector<vector<int>> gr(h, vi(w));
  vector<int> br(h), bc(w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g[i][j] == '#') {
        br[i] = 1;
        bc[j] = 1;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      gr[i][j] = (br[i] || bc[j]) ? 1 : 0;
    }
  }
  vector<vector<int>> level(h, vi(w));
  vector<vector<bool>> vis(h, vector<bool>(w, false));
  queue<pii> q;
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (gr[i][j] == 0) {
        q.push({i, j});
        level[i][j] = 0;
        vis[i][j] = true;
        cnt++;
      }
    }
  }
  int dr[] = {0, -1, 1, 0};
  int dc[] = {-1, 0, 0, 1};
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int z = 0; z < 4; z++) {
      int nr = dr[z] + i;
      int nc = dc[z] + j;
      debug(nc, nr, i, j);
      if (nr < 0 || nc < 0 || nr >= h || nc >= w)
        continue;
      if (g[nr][nc] == '#')
        continue;
      if (vis[nr][nc])
        continue;
      vis[nr][nc] = true;
      q.push({nr, nc});
      level[nr][nc] = level[i][j] + 1;
    }
  }
  int ans = 0;
  debug(level);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g[i][j] == '.' && gr[i][j] == 1 && vis[i][j] && level[i][j] <= k)
        ans++;
    }
  }
  cout << ans + cnt << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
