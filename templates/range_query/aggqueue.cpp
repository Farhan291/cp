template <typename T, typename Op> struct aggstack {
  Op op;
  stack<pair<T, T>> st;

  aggstack(Op op) : op(op) {}
  T agg() const { return st.top().second; }

  void push(T x) {
    (st.empty()) ? st.push({x, x}) : st.push({x, op(x, agg())});
  }

  void pop() { st.pop(); }
};

template <typename T, typename Op> struct aggqueue {
  Op op;
  aggstack<T, Op> in, out;

  aggqueue(Op op) : op(op), in(op), out(op) {}

  void push(T x) { in.push(x); }

  void pop() {
    if (out.st.empty()) {
      while (!in.st.empty()) {
        T v = in.st.top().first;
        in.pop();
        out.push(v);
      }
    }
    out.pop();
  }

  T query() {
    if (in.st.empty())
      return out.agg();
    if (out.st.empty())
      return in.agg();
    return op(out.agg(), in.agg());
  }
};
auto mx = [](int a, int b) { return max(a, b); };
auto mn = [](int a, int b) { return min(a, b); };
auto bor = [](int a, int b) { return a | b; };
auto band = [](int a, int b) {
  return a & b;
}; // aggqueue<int,decltype(bor)> q(bor);
