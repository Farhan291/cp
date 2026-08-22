#include <bits/stdc++.h>

int main() {

  long long n = 600851475143;
  long long ans = 0;
  while (!(n & 1)) {
    ans = 2;
    n /= 2;
  }
  for (int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      ans = i;
      n /= i;
    }
  }
  if (n > 1)
    ans = n;
  std::cout << ans << "\n";
}
