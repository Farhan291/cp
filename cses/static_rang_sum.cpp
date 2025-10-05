#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    vector<long long> v1(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    v1[0]=v[0];

    for (long long i = 1; i < n; i++)
    {
        v1[i] = v1[i - 1] + v[i];
    }

    while (q--)
    {
        int a, b;
        long long sum =0;
        cin >> a >> b;
        if(a==1){
            sum = v1[b-1];
        }
        else{
              sum = v1[b-1] - v1[a-2];
        }
        
        cout << sum << endl;
    }
}