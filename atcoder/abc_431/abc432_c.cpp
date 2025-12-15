#include <atcoder/all>
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using namespace atcoder;

void Solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vi v(n);
  vi v1(m);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> v1[i];
  }
  int j = min(n, m);
  for (int i = 0; i < j; i++) {
    if (v[i] <= v1[i]) {
      ans++;
    }
  }
  if (ans >= k)
    cout << "Yes";
  else
    cout << "No";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
