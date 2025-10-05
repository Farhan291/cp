#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long long Sum(long long n)
{
    long long sum = 0;
    for (int p = 1; p <= n; p *= 10)
    {
        long long high = n / (p * 10);
        long long cur = (n / p) % 10;
        long long low = n % p;
        sum += high * 45 * p;             // full cycles
        sum += (cur * (cur - 1) / 2) * p; // 0..cur-1 in partial cycle
        sum += cur * (low + 1);           // cur for leftover
    }
    return sum;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << Sum(x) << endl;
    }
}