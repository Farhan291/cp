// Url - https://codeforces.com/problemset/problem/292/B?locale=en
// codeforces
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> deg(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
  }

  int one = 0, two = 0, center = 0;

  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1)
      one++;
    else if (deg[i] == 2)
      two++;
    else if (deg[i] == n - 1)
      center++;
  }

  if (m == n - 1 && one == 2 && two == n - 2) {
    cout << "bus topology\n";
  } else if (m == n && two == n) {
    cout << "ring topology\n";
  } else if (m == n - 1 && center == 1 && one == n - 1) {
    cout << "star topology\n";
  } else {
    cout << "unknown topology\n";
  }

  return 0;
}
