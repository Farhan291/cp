template <typename T, int MOD, int MAXN> struct Combinator {
  vector<T> fact, invfact;

  static T binpow(T a, long long b) {
    T ans = 1;
    while (b) {
      if (b & 1)
        ans = (ans * a) % MOD;
      a = (a * a) % MOD;
      b >>= 1;
    }
    return ans;
  }
  Combinator() {
    fact.resize(MAXN + 1);
    invfact.resize(MAXN + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
      fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXN] = binpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--) {
      invfact[i - 1] = invfact[i] * i % MOD;
    }
  }
  T ncr(T a, T b) {
    if (a < 0 || b > a)
      return 0;
    return ((fact[a] * invfact[b]) % MOD * invfact[a - b]) % MOD;
  }
  T dearrangement(T a) {
    if (a < 0)
      return 0;
    T ans = 1;
    for (int k = 1; k <= a; k++) {
      if (k & 1) {
        ans = (ans - invfact[k] + MOD) % MOD;
      } else {
        ans = (ans + invfact[k]) % MOD;
      }
    }
    return ((fact[a] * ans) % MOD);
  }
};
