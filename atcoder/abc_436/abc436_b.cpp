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

int mod(int x, int y) {
  if (x < 0) {
    while (x < 0) {
      x += y;
    }
    return x % y;
  }
  return x % y;
}
void Solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vi(n, 0));
  v[0][(n - 1) / 2] = 1;
  int q = n * n - 1;
  int k = 1;
  int r = 0;
  int c = (n - 1) / 2;
  while (q--) {
    if (v[mod(r - 1, n)][mod(c + 1, n)] == 0) {
      v[mod(r - 1, n)][mod(c + 1, n)] = k + 1;
      k++;
      r = mod(r - 1, n);
      c = mod(c + 1, n);
    } else {
      v[mod(r + 1, n)][c] = k + 1;
      k++;
      r = mod(r + 1, n);
    }
  }
  for (auto i : v) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
