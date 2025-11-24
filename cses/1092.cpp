// Url - https://cses.fi/problemset/task/1092
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
  vi f;
  vi s;
  if (((n * n + n) / 2) % 2 == 0) {
    int target = (n * n + n) / 4;
    int sum = 0;
    for (int i = n; i > 0; i--) {
      if (target - (sum + i) >= 0) {
        sum += i;
        f.push_back(i);
      } else {
        s.push_back(i);
      }
    }
    cout << "YES" << endl;
    cout << sz(f) << endl;
    for (int i = 0; i < sz(f); i++) {
      if (i == sz(f) - 1) {
        cout << f[i] << endl;
      } else {
        cout << f[i] << " ";
      }
    }
    cout << sz(s) << endl;
    for (int i = 0; i < sz(s); i++) {
      if (i == sz(s) - 1) {
        cout << s[i] << endl;
      } else {
        cout << s[i] << " ";
      }
    }

  } else {
    cout << "NO" << endl;
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
