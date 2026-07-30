template <typename T> struct fenwick {
  int n;
  vector<T> bit;
  fenwick(int n) {
    this->n = n;
    bit.resize(n + 1);
  }
  T sum(int i) {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= (i & -i);
    }
    return s;
  }
  // [l,r]
  T query(int l, int r) { return sum(r) - sum(l - 1); }
  void update(int i, T v) {
    while (i <= n) {
      bit[i] += v;
      i += (i & -i);
    }
  }
}
