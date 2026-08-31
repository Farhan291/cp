
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
