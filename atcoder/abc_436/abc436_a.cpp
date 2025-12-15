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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int add = n - sz(s);
  char ans[add + 1];
  for (int i = 0; i < add; i++) {
    ans[i] = 'o';
  }
  ans[add] = '\0';
  string z = ans + s;
  cout << z << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
