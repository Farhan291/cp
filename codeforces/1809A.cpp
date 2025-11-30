// Url -https://codeforces.com/problemset/problem/1809/A
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
  string s;
  cin >> s;
  map<char, int> m;
  for (int i = 0; i < sz(s); i++) {
    m[s[i]]++;
  }
  for (auto i : m) {
    if (i.second == 4) {
      cout << -1 << endl;
      return;
    } else if (i.second == 3) {
      cout << 6 << endl;
      return;
    } else if (i.second == 2) {
      cout << 4 << endl;
      return;
    }
  }
  cout << 4 << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
