// Problem:
// Contest:
// URL:
// Time Limit:
// Start:
// atcoder
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
template <typename T> void sort_unique(vector<T> &vec) {
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
}
const char nl = '\n';

void Mizuhara() {
  int n, q;
  cin >> n >> q;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  set<int> s;
  vi rev;
  set<int> check;
  vi ques;
  while (q--) {
    int x;
    cin >> x;
    s.insert(x);
    ques.pb(x);
  }
  for (int i = 0; i < n; i++) {
    if (s.find(v[i]) == s.end())
      cout << v[i] << " ";
  }
  for (int i = sz(ques) - 1; i >= 0; i--) {
    if (check.find(ques[i]) == check.end()) {
      check.insert(ques[i]);
      rev.pb(ques[i]);
    }
  }
  reverse(all(rev));
  for (auto &x : rev) {
    cout << x << " ";
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Mizuhara();
}
