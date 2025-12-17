// Url -https://codeforces.com/problemset/problem/2051/A
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
  vi m(n);
  vi s(n);
  int mo = 0;
  int st = 0;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      mo += m[i];
      break;
    }
    if (m[i] > s[i + 1]) {
      mo += m[i];
      st += s[i + 1];
    }
  }
  cout << mo - st << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
