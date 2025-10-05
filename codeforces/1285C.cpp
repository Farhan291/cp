#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main(void)
{

    long long x;
    cin >> x;

    long long a, b;
    a = 1;
    b = x;
    for (long long i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (lcm(i, x / i) == x)
            {
                if (max(i, x / i) < max(a, b))
                {
                    a = i;
                    b = x / i;
                }
            }
        }
    }
    cout << a << ' ' << b;
    return 0;
}