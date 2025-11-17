// Url -https://codeforces.com/problemset/problem/1980/A
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
  int n, m;
  cin >> n >> m;
  int count = 0;
  map<char, int> v;
  for (int i = 0; i < n; i++) {
    char a;
    cin >> a;
    v[a]++;
  }

  string levels = "ABCDEFG";
  for (char l : levels) {
    if (v[l] < m) {
      count += (m - v[l]);
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
