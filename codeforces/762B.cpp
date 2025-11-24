// Url -https://codeforces.com/contest/762/problem/B
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
  int a, b, c;
  cin >> a >> b >> c;
  int m;
  cin >> m;
  vi usb;
  vi ps;
  for (int i = 0; i < m; i++) {
    int n;
    string s;
    cin >> n >> s;
    if (s == "USB") {
      usb.push_back(n);
    } else {
      ps.push_back(n);
    }
  }
  sort(all(usb));
  sort(all(ps));
  int count = 0;
  int sum = 0;
  int usb_bought = min(a, sz(usb));
  for (int i = 0; i < usb_bought; i++) {
    sum += usb[i];
    count++;
  }
  int ps_bought = min(b, sz(ps));
  for (int i = 0; i < ps_bought; i++) {
    sum += ps[i];
    count++;
  }

  usb.insert(usb.end(), all(ps));
  sort(all(usb));
  usb.erase(remove(all(usb), 0), usb.end());
  int adapter_count = min(c, sz(usb));
  for (int i = 0; i < adapter_count; i++) {
    sum += usb[i];
  }
  count += adapter_count;
  cout << count << " " << sum << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    Solve();
}
