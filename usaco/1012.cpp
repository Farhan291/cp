// Url - https://usaco.org/index.php?page=viewproblem2&cpid=1012
// codeforces
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;

void Solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  bool temp = false;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (!temp) {
        ans++;
        temp = true;
      }
    } else {
      temp = false;
    }
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
