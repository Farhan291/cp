
bool bipartite(const vector<vector<int>> &g, vector<int> &color, int u, int c) {
  color[u] = c;
  for (auto v : g[u]) {
    if (color[v] == -1) {
      if (!bipartite(g, color, v, 1 ^ c))
        return false;
    } else if (color[v] == c)
      return false;
  }
  return true;
}
