// Url -https://codeforces.com/problemset/problem/1978/A
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
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  auto it = max_element(all(v));
  if (*it == v[n - 1]) {
    sum = v[n - 1] + *max_element(v.begin(), v.end() - 1);
  } else {
    sum = sum + *it;
    sum += v[n - 1];
  }
  cout << sum << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
