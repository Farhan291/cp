// Url -
// codeforces
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;

void Solve() {
  int m, s, c;
  cin >> m >> s >> c;
  vector<int> v(c);
  for (int i = 0; i < c; i++) {
    cin >> v[i];
  }
  sort(all(v));
  if (m == 1) {
    cout << v[c - 1] - v[0] + 1 << endl; // lenght is distance+1
    return;
  }
  vector<int> gap;
  for (int i = 1; i < c; i++) {
    gap.pb(v[i] - v[i - 1] - 1); // number of empty sheds is distance -1
  }
  sort(gap.rbegin(), gap.rend());

  int sumgaps = 0;
  for (int i = 0; i < min(m - 1, sz(gap)); i++) {
    sumgaps += gap[i];
  }
  cout << v[c - 1] - v[0] + 1 - sumgaps << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
