// Url -
// codeforces
#include <bits/stdc++.h>
#include <cmath>

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
  int x, y, z;
  cin >> x >> y >> z;
  int sum = 11;
  int a = 0;
  for (int i = 0; i <= 10; i++) {
    int tsum = abs(i - x) + abs(i - y) + abs(i - z);
    if (tsum < sum) {
      sum = tsum;
      a = i;
    }
  }
  cout << sum << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
