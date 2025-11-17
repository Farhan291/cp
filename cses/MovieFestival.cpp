// Url - https://cses.fi/problemset/task/1629/
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
    int w, j = 0;
    cin >> w >> j;
    v[i] = {w, j};
  }
  sort(all(v), [](auto &a, auto &b) { return a.second < b.second; });
  int m = 1;
  auto last = v[0].second;
  for (int i = 1; i < n; i++) {
    if (last <= v[i].first) {
      m++;
      last = v[i].second;
    }
  }
  cout << m << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
