// Url -https://codeforces.com/contest/1692/problem/H
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
template <typename T> void sort_unique(vector<T> &vec) {
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
}
const char nl = '\n';

#ifdef REZE
struct _debug {
  template <typename T> static void __print(const T &x) {
    if constexpr (is_fundamental_v<T> || is_convertible_v<T, string>) {
      cerr << x;
    } else {
      cerr << "{";
      for (auto i : x) {
        __print(i);
        cerr << " ";
      }
      cerr << "}";
    }
  }
  template <typename T, typename V> static void __print(const pair<T, V> &x) {
    cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')';
  }
  template <typename T, typename... V>
  static void _print(const T &t, const V &...v) {
    __print(t);
    if constexpr (sizeof...(v))
      cerr << ", ", _print(v...);
    else
      cerr << "]\n";
  }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif
const int M = 2e5 + 1;
void Mizuhara() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  // coordinate compression
  vi cp = v;
  sort(all(cp));
  cp.erase(unique(all(cp)), cp.end());
  map<int, int> m;
  for (int i = 0; i < sz(cp); i++) {
    m[cp[i]] = i;
  }
  vector<int> b(M);
  for (int i = 0; i < n; i++) {
    b[i] = m[v[i]];
  }
  vector<int> frq(M);
  for (auto &x : b) {
    frq[x]++;
  }

  vector<int> lst(M, -1);
  vector<int> cur(M);
  vector<int> best(M);
  vector<int> start(M);
  vector<int> bestl(M);
  vector<int> bestr(M);
  for (int i = 0; i < n; i++) {
    int v = b[i];
    int gaps = i - (lst[v] + 1);
    if (cur[v] - gaps < 0) {
      cur[v] = 0;
      start[v] = i;
    } else {
      cur[v] -= gaps;
    }
    if (cur[v] > best[v]) {
      best[v] = cur[v];
      bestl[v] = start[v];
      bestr[v] = i;
    }

    cur[v]++;
    if (cur[v] > best[v]) {
      best[v] = cur[v];
      bestl[v] = start[v];
      bestr[v] = i;
    }
    lst[v] = i;
  }
  int bestVal = -1, ansA = v[0], ansL = 0, ansR = 0;
  for (int i = 0; i < M; i++) {
    if (best[i] > bestVal) {
      bestVal = best[i];
      ansA = cp[i];
      ansL = bestl[i];
      ansR = bestr[i];
    }
  }

  cout << ansA << " " << ansL + 1 << " " << ansR + 1 << "\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  while (t--)
    Mizuhara();
}
