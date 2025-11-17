// Url - https://usaco.org/index.php?page=viewproblem2&cpid=1301
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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int cost = 0;
  sort(all(v));
  int temp = v[0];
  for (int i = 0; i < n - 1; i++) {
    if (v[i + 1] - v[i] > k) {
      cost += v[i] - temp + 1 + k;
      temp = v[i + 1];
    }
  }
  cost += v[n - 1] - temp + 1 + k;
  cout << cost << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
