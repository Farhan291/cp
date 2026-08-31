// url- https://projecteuler.net/problem=10#111677
// date- 28/08/26
#include <bits/stdc++.h>
using namespace std;
struct sieve {
  vector<int> primes;
  vector<int> spf;

  sieve(int N) {
    spf.assign(N + 1, 0);
    for (int i = 2; i < N; i++) {
      if (spf[i] == 0) {
        spf[i] = i;
        primes.push_back(i);
      }
      for (int j = 0; j < (int)primes.size() && i * primes[j] < N; j++) {
        spf[i * primes[j]] = primes[j];
        if (i % primes[j] == 0)
          break;
      }
    }
  }

  int sf(int x) { return spf[x]; }
  bool isprime(int x) { return spf[x] == x; }

  vector<int> primefac(int x) {
    vector<int> pf;
    while (x > 1) {
      int prime = spf[x];
      pf.push_back(prime);
      while (x % prime == 0) {
        x /= prime;
      }
    }
    return pf;
  }

  vector<int> reppf(int x) {
    vector<int> pf;
    while (x > 1) {
      pf.push_back(spf[x]);
      x /= spf[x];
    }
    return pf;
  }

  vector<pair<int, int>> fac2(int x) {
    vector<pair<int, int>> pf;
    while (x > 1) {
      int exp = 0;
      int prime = spf[x];
      while (x % prime == 0) {
        exp++;
        x /= prime;
      }
      pf.push_back({prime, exp});
    }
    return pf;
  }
  vector<int> divs(int x) const {
    vector<int> divisors(1, 1);
    while (x > 1) {
      int p = spf[x], c = 0;
      while (x % p == 0)
        x /= p, c++;
      int sz = divisors.size();
      divisors.reserve(sz * (c + 1));
      for (int i = 1, pw = p; i <= c; i++, pw *= p) {
        for (int j = 0; j < sz; j++) {
          divisors.push_back(divisors[j] * pw);
        }
      }
    }
    return divisors;
  }
};
sieve s(2'000'001);
int main() {
  // __int128_t sum = 0;
  unsigned long long sum = 0;
  for (auto &p : s.primes) {
    sum += p;
  }
  cout << sum << "\n";
}
