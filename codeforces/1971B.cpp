// Url -https://codeforces.com/problemset/problem/1971/B
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
  char a = s[0];
  bool idk = false;
  for (int i = 1; i < sz(s); i++) {
    if (s[i] != a) {
      idk = true;
      s[0] = s[i];
      s[i] = a;
      break;
    }
  }
  if (idk) {
    cout << "YES" << endl;
    cout << s << endl;

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
