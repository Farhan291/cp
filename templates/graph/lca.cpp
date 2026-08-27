struct LCA {
  int n, LOG = 0;
  vector<vector<int>> up;
  vector<int> depth;
  LCA(const vector<int> &parent, const vector<int> &depth)
      : n((int)parent.size()), depth(depth) {
    while ((1LL << LOG) <= n)
      ++LOG;
    up.resize(n, vector<int>(LOG, -1));
    for (int i = 0; i < n; i++) {
      up[i][0] = parent[i];
    }
    for (int j = 1; j < LOG; j++) {
      for (int i = 0; i < n; i++) {
        up[i][j] = up[up[i][j - 1]][j - 1];
      }
    }
  }
  int jump(int x, int k) {
    for (int j = 0; j < LOG; j++) {
      if (k & (1LL << j))
        x = up[x][j];
    }
    return x;
  }
  int lca(int a, int b) {
    if (depth[a] < depth[b])
      swap(a, b);
    a = jump(a, depth[a] - depth[b]);
    if (a == b)
      return a;
    for (int j = LOG - 1; j >= 0; j--) {
      if (up[a][j] != up[b][j]) {
        a = up[a][j];
        b = up[b][j];
      }
    }
    return up[a][0];
  }
};
