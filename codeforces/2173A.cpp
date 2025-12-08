// Url -https://codeforces.com/contest/2173/problem/A
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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  int awake = 0;
  for (int i = 0; i < n; i++) {
    if (awake > 0) {
      if (s[i] == '1') {
        awake = k;
        continue;
      }
      awake--;
      continue;
    }
    if (s[i] == '1') {
      awake = k;
    } else {
      ans++;
    }
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
