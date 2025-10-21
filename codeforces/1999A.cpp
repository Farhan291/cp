// https://codeforces.com/problemset/problem/1999/A

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int temp = n;
    int sum = 0;
    while (temp != 0) {
      int dig = temp % 10;
      sum += dig;
      temp = temp / 10;
    }
    cout << sum << endl;
  }
  return 0;
}
