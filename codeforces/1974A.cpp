// Url - https://codeforces.com/problemset/problem/1974/A
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
  int x, y;
  cin >> x >> y;
  int count = 0;
  if (x == 0 & y == 0) {
    cout << 0 << endl;
    return;
  }
  int s = ceil(y / 2.0);
  if (y == 0) {
    int w = ceil(x / 15.0);
    count += w;
    cout << count << endl;
    return;
  }
  if (y % 2 == 0) {
    int w = ceil(x / 7.0);
    count = max(s, w);
    cout << count << endl;
    return;
  }
  if (y % 2 != 0) {
    int fs = 7 * (s - 1);
    int ls = 11;
    if (x <= fs + ls) {
      cout << s << endl;
      return;
    }
    int remaining = x - (fs + ls);
    count = s + ceil(remaining / 15.0);
    cout << count << endl;
    return;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
