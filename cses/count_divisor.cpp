#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        vector<int> v;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                v.push_back(i);
                
                if (i != x/i)
                {
                    v.push_back(x/i);
                    
                }
            }
            
        }
        cout << v.size()<<endl;
        
    }
    return 0;
}