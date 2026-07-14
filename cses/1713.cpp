// Url: https://cses.fi/problemset/task/1713
// Start: 03/07/26
// mintemplate
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

int divs[1000001] = {0};

void Mizuhara() {
  int x;
  cin >> x;
  cout << divs[x] << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
  int t = 1;
  cin >> t;
  for (int i = 1; i < 1000001; i++) {
    for (int j = i; j < 1000001; j += i) {
      divs[j]++;
    }
  }
  while (t--)
    Mizuhara();
}

/*#include <bits/stdc++.h>
using namespace std;

int main() {

        vector<int> sieve(1e6 + 1, 0);
        for (int i = 2; i <= 1e6; i++) {
                if (sieve[i] == 0) {
                        for (int j = i; j <= 1e6; j += i)
                                sieve[j] = i;
                }
        }

        int T;
        cin >> T;

        while (T--) {
                int N;
                cin >> N;

                int ans = 1;
                while (N > 1) {

                        int prime = sieve[N];
                        int exp = 0;

                        while (N % prime == 0) {
                                N /= prime;
                                exp++;
                        }

                        ans *= (exp + 1);
                }

                cout << ans << "\n";
        }
}*/
