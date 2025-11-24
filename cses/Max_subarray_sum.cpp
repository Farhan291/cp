// Url -https://cses.fi/problemset/task/1643
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
  vi v(n);
  int best = 0;
  int current = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
    current += x;
    if (current > best) {
      best = current;
    }
    if (current < 0) {
      current = 0;
      continue;
    }
  }
  if (best == 0) {
    int y = *max_element(all(v));
    cout << y << endl;
    return;
  }
  cout << best << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
