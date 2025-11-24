// Url - https://cses.fi/problemset/task/1074/
// codeforces
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;

bool check(int m, int median, vi &v, int n) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    k += abs(v[i] - median);
  }
  return m >= k;
}
void Solve() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(all(v));
  int median = 0;
  if (n % 2 == 0) {
    median = (v[n / 2] + v[(n / 2) - 1]) / 2;

  } else {
    median = v[n / 2];
  }
  int l = 0;
  int h = 2e18;
  int ans = 0;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (check(m, median, v, n)) {
      h = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
