struct DSU {

  vector<int> parent, sizes;
  DSU(int n) {
    parent.resize(n);
    sizes.resize(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  bool same(int a, int b) { return find(a) == find(b); }

  bool Union(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb)
      return false;
    if (sizes[roota] < sizes[rootb]) {
      swap(roota, rootb);
    }
    parent[rootb] = roota;
    sizes[roota] += sizes[rootb];
    return true;
  }

  int size(int x) { return sizes[find(x)]; }
};
