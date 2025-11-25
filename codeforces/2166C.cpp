// Url -https://codeforces.com/problemset/problem/2166/C
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

/*void Solve() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int cost = 0;
  while (sz(v) != 1) {
    int min_max = 2e18;
    int current = 0;
    int index_to_remove = 0;
    for (int i = 0; i < sz(v); i++) {
      if (i != sz(v) - 1) {
        current = max(v[i], v[i + 1]);
        if (current < min_max) {
          min_max = current;
          index_to_remove = i;
        }

      } else {

        current = max(v[0], v[sz(v) - 1]);
        if (current < min_max) {
          min_max = current;
          index_to_remove = sz(v) - 1;
        }
      }
    }
    if (index_to_remove == sz(v) - 1) {
      v.erase(v.end() - 1);
      v.erase(v.begin());
      v.insert(v.begin(), min_max);
    } else {
      v.erase(v.begin() + index_to_remove);
      v.erase(v.begin() + index_to_remove);
      v.insert(v.begin() + index_to_remove, min_max);
    }
    cost += min_max;
  }
  cout << cost << endl;
}*/
void Solve() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vi m;
  m.push_back(max(v[0], v[n - 1]));
  for (int i = 0; i < n - 1; i++) {
    m.push_back(max(v[i], v[i + 1]));
  }
  sort(all(m));
  int cost = 0;
  for (int i = 0; i < n - 1; i++) {
    cost += m[i];
  }
  cout << cost << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Solve();
}
