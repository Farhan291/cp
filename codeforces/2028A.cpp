// Url -https://codeforces.com/problemset/problem/2028/A
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
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int x = 0;
  int y = 0;
  for (int i = 0; i < n; i++) {
    char ch = s[i];
    cout << "ch" << ch;
    switch (ch) {
    case 'N':
      ++y;
      break;
    case 'E':
      ++x;
      break;
    case 'W':
      --x;
      break;
    case 'S':
      --y;
      break;
    }
  }
  cout << "x:" << x << "y:" << y;
  if (a % x == 0 && b % y == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
