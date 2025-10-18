
#include <bits/stdc++.h>
using namespace std;

bool check(long long m, long long k)
{
    long long sum = floor(sqrt(m));
    long long on = m - sum;
    return on >= k;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;
        long long l = 1;
        long long h = 2e18;
        long long ans = 0;
        while (h-l>1)
        {
            long long m = l + (h - l) / 2;
            if (check(m, k))
            {
                ans = m;
                h = m;
            }
            else
            {
                l = m;
            }
        }
        cout << h<< endl;
    }
    return 0;
}
