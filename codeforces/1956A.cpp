// Url -https://codeforces.com/problemset/problem/1956/A
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
  int k, q;
  cin >> k >> q;
  vi v(k);
  vi m(q);
  for (int i = 0; i < k; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    cout << min(v[0] - 1, x) << " ";
  }
  cout << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
