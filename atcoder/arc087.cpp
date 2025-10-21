// https://atcoder.jp/contests/arc087/tasks/arc087_a?lang=en
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++; // m[x]++ creates if the key value pair with default 0  then
            // increament 1,  if already there increamentvalue by 1
  }
  int steps = 0;
  for (auto v : m) {
    if (v.first > v.second) {
      steps += v.second;
    } else if (v.first < v.second) {
      steps += (v.second - v.first);
    }
  }
  cout << steps;
  return 0;
}
