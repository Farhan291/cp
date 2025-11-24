// Url -
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

void Solve() {
  int n, m;
  cin >> n >> m;
  if (m > n) {
    cout << "NO\n";
    return;
  }
  if (m == n) {
    cout << "YES\n";
    return;
  }
  vi v;
  v.push_back(n);
  for (int i = 0; i < sz(v); i++) {
    int x = v[i];
    if (x == m) {
      cout << "YES\n";
      return;
    }
    if (x < m)
      continue;
    if (x % 3 != 0)
      continue;
    int a = 2 * (x / 3);
    int b = x / 3;
    v.push_back(a);
    v.push_back(b);
  }
  cout << "NO\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
