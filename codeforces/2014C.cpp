#include <bits/stdc++.h>
using namespace std;

bool robin(vector<long long> &v, long long x, long long n)
{
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    double avg = (sum + x) / (double)n;
    int unhappy = 0;
    for (auto w : v)
    {
        if (w < 0.5 * avg)
            unhappy++;
    }
    return unhappy > n / 2;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n < 3)
        {
            cout << -1<<endl;
            continue;
        }
        
        
        long long l = 0;
        long long ans = -1;
        long long h = 1e12;
        while (l <= h)
        {
            long long m = l + (h - l) / 2;
            if (robin(v, m, n))
            {
                ans = m;
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        cout << ans << endl;
    }
}