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
  int n;
  cin >> n;
  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    int w, j;
    cin >> w >> j;
    v[i] = {w, j};
  }
  sort(all(v));
  int t = 0;
  int r = 0;
  for (int i = 0; i < n; i++) {
    t += v[i].first;
    r += v[i].second - t;
  }
  cout << r << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
