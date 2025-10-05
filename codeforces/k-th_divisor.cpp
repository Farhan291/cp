#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void)
{
    long long x, y;
    vector<long long> v;
    vector<long long> t;
    cin >> x >> y;
    for (long long i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            v.push_back(i);
            if (i != x / i)
            {
                t.push_back(x / i);
            }
        }
    }
    reverse(t.begin(), t.end());
    v.insert(v.end(), t.begin(), t.end());
    if(y>(long long)v.size()){
        cout<<-1<<endl;
        return 0;
    }
    cout<<v[y-1]<<endl;

}