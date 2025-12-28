#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back

class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    sort(all(happiness), [](auto a, auto b) { return a > b; });
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
      ans += max(0, happiness[i] - i);
    }
    return ans;
  }
};
