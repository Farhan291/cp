// Url -https://codeforces.com/problemset/problem/1924/A
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
  int n, k, m;
  cin >> n >> k >> m;
  string s;
  cin >> s;
  vector<string> v;
  string abc = "abcdefghijklmnopqrdtuvwxyz";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      string t = {abc[i], abc[j]};
      v.push_back(t);
    }
  }
  for (auto a : v) {
    cout << a << " ";
  }
  cout << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
