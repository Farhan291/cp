// Url -https://codeforces.com/contest/2176/problem/A
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
  int n;
  cin >> n;
  int ans = 0;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    if (v[i] == 200)
      continue;
    for (int j = i; j < n; j++) {
      if (v[i] > v[j]) {
        // cout << "i" << i << "v" << v[i] << endl;
        // cout << "j" << j << "V" << v[j];
        ans++;
        v[j] = 200;
      }
    }
  }
  // cout << endl;
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
