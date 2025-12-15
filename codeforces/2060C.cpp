// Url -https://codeforces.com/problemset/problem/2060/C
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
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  int sum = 0;
  for (auto i : m) {
    int remain = k - i.first;
    auto it = m.find(remain);
    if (it == m.end())
      continue;

    if (it->first == i.first) {
      sum += (i.second / 2);
      continue;
    }
    if (i.first < it->first) {
      sum += min(i.second, it->second);
    }
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
