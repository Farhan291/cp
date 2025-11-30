// Url -https://codeforces.com/problemset/problem/1946/A
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
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  sort(all(v));
  int m = n % 2 == 0 ? n / 2 : n / 2 + 1;
  m--;
  int count = 1;
  for (int i = m + 1; i < n; i++) {
    if (v[i] < v[m] + 1) {
      count += v[m] + 1 - v[i];
    }
  }
  cout << count << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
