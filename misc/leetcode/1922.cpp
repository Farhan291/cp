#include <bits/stdc++.h>
using namespace std;
// URL: https://leetcode.com/problems/count-good-numbers/description/
#define ll long long

class Solution {
public:
  int countGoodNumbers(long long n) {
    ll MOD = 1e9 + 7;
    ll ed = 0;
    ll od = 0;
    if (n & 1) {
      ed = n / 2 + 1;
      od = n / 2;
    } else {
      ed = od = n / 2;
    }
    ll a = 5;
    ll b = 4;
    ll ans = 1;
    while (ed) {
      if (ed & 1)
        ans = (ans * a) % MOD;
      a = (a * a) % MOD;
      ed /= 2;
    }
    while (od) {
      if (od & 1)
        ans = (ans * b) % MOD;
      b = (b * b) % MOD;
      od /= 2;
    }
    return (int)ans;
  }
};
