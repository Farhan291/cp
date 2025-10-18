#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
using namespace std;
int agcd(int a[], int y)
{
    int g = a[0];
    for (int i = 1; i < y; i++)
    {
        g = gcd(a[i], g);
    }
    return g;
}
int main(void)
{
    int x;
    cin >> x;
    while (x--)
    {
        int y;
        cin >> y;
        int array[y];
        for (int i = 0; i < y; i++)
        {
            cin >> array[i];
        }
        int cost = 0;
        int gc = agcd(array, y);
        if (gc != 1)
        {
            array[y - 1] = gcd(array[y - 1], y);
            gc = agcd(array, y);
            cost++;
            if (gc != 1)
            {
                array[y - 2] = gcd(array[y - 2], y - 1);
                gc = agcd(array, y);
                cost += 2;
            }
            if (gc != 1)
            {
                array[y - 3] = gcd(array[y - 3], y - 1);
                gc = agcd(array, y);
                cost += 3;
            }
        }
        cout << cost << "\n";
    }
}
