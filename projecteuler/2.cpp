#include <bits/stdc++.h>

const int n = 1e6 + 1;
int main() {
  int a = 1, b = 2;
  int ans = 0;

  while (b <= 4000000) {
    if (b % 2 == 0)
      ans += b;

    int c = a + b;
    a = b;
    b = c;
  }

  std::cout << ans << '\n';
}
