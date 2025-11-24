// Url -https://codeforces.com/problemset/problem/1991/A
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

auto sum(vi &v) {
  vi pf;
  for (int i = 1; i < sz(v); i++) {
    pf.push_back(v[i - 1] + v[i]);
  }
  auto it = min_element(all(pf)) - pf.begin();
  return it;
}

void Solve() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  while (sz(v) != 1) {
    auto index = sum(v);
    v.erase(v.begin() + index);
    v.erase(v.begin() + index);
  }
  for (auto i : v) {
    cout << i << endl;
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
