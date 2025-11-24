// Url -https://cses.fi/problemset/task/1073
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
  vi s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = upper_bound(all(s), x);
    if (it == s.end()) {
      s.push_back(x);
    } else {
      *it = x;
    }
  }
  cout << sz(s) << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  //  cin >> t;
  while (t--)
    Solve();
}
