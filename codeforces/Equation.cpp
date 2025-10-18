#include <bits/stdc++.h>
using namespace std;

double f(double m)
{
    return m * m + sqrt(m);
}

int main()
{
    double c;
    cin >> c;
    double l = 0;
    double h = sqrt(c);
    while (h - l > 1e-7)
    {
        double m = l + (h - l) / 2;
        if (f(m) < c)
        {
            l = m;
        }
        else if (f(m) > c)
        {
            h = m;
        }
    }
    cout << fixed << setprecision(10) << l << "\n";
    return 0;
}


/*
double l = 0, r = something_big;
while (r - l > 1e-7) {       // stop when close enough
    double m = (l + r) / 2;
    if (f(m) < target)
        l = m;               // move boundary slightly
    else
        r = m;
}

cout << fixed << setprecision(10) << l;


while (r - l > 1e-7) {
    double m = (l + r) / 2;
    if (ok(m)) l = m; else r = m;
}

*/