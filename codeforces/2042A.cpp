// Url -https://codeforces.com/problemset/problem/2042/A
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
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(all(v), [](auto &a, auto &b) { return a > b; });
  int sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i];
    if (sum == k) {
      break;
    } else if (sum > k) {
      sum = sum - v[i];
      count += (k - sum);
      sum += v[i];
      break;
    }
  }
  if (sum < k) {
    count = k - sum;
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
