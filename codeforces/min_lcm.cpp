//1765M
#include <bits/stdc++.h>
#include <numeric>
#include <cmath>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin>>x;
        int a=1;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
               a=x/i;
               break;
            }
        }
        cout<<a<<' '<<x-a<<endl;
    }
}