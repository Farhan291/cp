// Url -
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
  vi z;
  int k = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    int x = v[i];
    if (x == 0) {
      k++;
    } else {
      z.push_back(k);
      k = 0;
    }
  }
  if (k > 0) {
    z.push_back(k);
  }
  if (sz(z) == 0) {
    cout << 0 << endl;
  } else {
    cout << *max_element(z.begin(), z.end()) << endl;
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
