// Url: https://www.spoj.com/problems/CAPCITY/
// Start: 28/08/26
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
struct tarjan {
  vector<int> st;
  vector<int> roots;
  int timer = 0;
  vector<int> tin;
  vector<int> tlow;

  void dfs(int u, vector<vector<int>> &g, vector<vector<int>> &comp) {
    tlow[u] = tin[u] = timer++;
    st.push_back(u);

    for (auto v : g[u]) {
      if (tin[v] == -1) { // tree-edge
        dfs(v, g, comp);
        tlow[u] = min(tlow[v], tlow[u]);
      } else if (roots[v] == -1) { // back-edge
        tlow[u] = min(tin[v], tlow[u]);
      }
    }

    if (tlow[u] == tin[u]) {
      comp.push_back({u});
      while (true) {
        int v = st.back();
        st.pop_back();
        roots[v] = u;
        if (u == v)
          break;
        comp.back().push_back(v);
      }
    }
  }

  vector<vector<int>> get_scc(vector<vector<int>> &g, int l = 0) {
    int n = (int)g.size();
    st.clear();
    roots.assign(n, -1);
    tin.assign(n, -1);
    tlow.assign(n, -1);
    vector<vector<int>> c;
    for (int u = l; u < n; u++) {
      if (tin[u] == -1) {
        dfs(u, g, c);
      }
    }
    return c;
  }
};

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
  }
  tarjan t;
  vector<vector<int>> scc = t.get_scc(g, 1);
  vector<bool> indeg(n + 1), outdeg(n + 1);
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      if (t.roots[v] != t.roots[u]) {
        indeg[t.roots[v]] = true;
        outdeg[t.roots[u]] = true;
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    if (indeg[t.roots[u]])
      indeg[u] = true;
    if (outdeg[t.roots[u]])
      outdeg[u] = true;
  }

  vi ans;
  for (int u = 1; u <= n; u++) {
    if (!outdeg[u])
      ans.pb(u);
  }
  cout << sz(ans) << nl;
  for (auto &u : ans) {
    cout << u << " ";
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
