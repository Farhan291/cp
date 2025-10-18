// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
bool check(long long time, long long n, long long x, long long y)
{
    long long first = min(x, y);
    if (time < first)
        return false;
    long long remaining = time - first;
    long long copies = 1 + remaining / x + remaining / y;
    return copies >= n;
}
int main()
{
    long long n, x, y;
    cin >> n >> x >> y;
    int l = 0;
    int ans = 0;
    int h = min(x, y) + max(x, y) * n;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (check(m, n, x, y))
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans;
    return 0;
}