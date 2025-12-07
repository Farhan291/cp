// Url -https://codeforces.com/problemset/problem/2143/B
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
  vi v1(k);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> v1[i];
  }
  sort(all(v1));
  sort(all(v), [](auto &a, auto &b) { return a > b; });
  int index = 0;
  for (auto i : v1) {
    if (index + i > sz(v)) {
      // cout << "idk" << index + i << endl;
      break;
    }
    sum += accumulate(v.begin() + index, v.begin() + index + i, 0LL) -
           *min_element(v.begin() + index, v.begin() + index + i);
    index += i;
  }
  sum += accumulate(v.begin() + index, v.end(), 0LL);
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
