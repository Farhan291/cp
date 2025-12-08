#include <atcoder/all>
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using namespace atcoder;

void Solve() {
  int x;
  cin >> x;
  int n;
  cin >> n;
  vector<pair<int, bool>> v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = {x, false};
  }

  int q;
  cin >> q;
  while (q--) {
    int p;
    cin >> p;
    v[p - 1].second = !(v[p - 1].second);
    if (v[p - 1].second) {
      x += v[p - 1].first;
    } else {
      x -= v[p - 1].first;
    }
    cout << x << endl;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  while (t--)
    Solve();
}
