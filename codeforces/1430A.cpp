// Url -https://codeforces.com/problemset/problem/1430/A
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
  int low = n / 7;
  int high = n / 3;
  for (int i = 0; i <= low; i++) {
    int remain = n - i * 7;
    for (int j = 0; j <= n / 5; j++) {
      int x = (remain - 5 * j) % 3;
      int idk = (remain - 5 * j) / 3;
      if (x == 0) {
        cout << idk << " " << j << " " << i << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
