// Url - https://codeforces.com/problemset/problem/2161/C
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
  int x;
  cin >> x;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int p1 = 0;
  int p2 = n - 1;
  int s = 0;
  int ans = 0;
  vi ansv;
  sort(all(v));
  while (p1 <= p2) {
    int gap = x - s % x;
    if (v[p2] >= gap) {
      s += v[p2];
      ansv.push_back(v[p2]);
      ans += v[p2];
      p2--;
    } else {
      s += v[p1];
      ansv.push_back(v[p1]);
      p1++;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < sz(ansv); i++) {
    cout << ansv[i] << " ";
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
