// Url -
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

bool check(vector<int> v, int n, int m) {
  int ones = 0;
  auto max = max_element(all(v));
  v.erase(max);
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == 1) {
      ones++;
    } else {
      count += 2 * (v[i]) - 1;
    }
  }
  count += ones;
  return count <= m;
}

void Solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int l = 0;
  int h = 2e18;
  int ans = 0;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (check(v, n, m)) {
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
  cin >> t;
  while (t--)
    Solve();
}
