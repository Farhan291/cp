//1203C
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main(void){
    int x;
    cin>>x;
    vector<long long> v(x);
    for(long long i=0;i<x;i++){
        cin>>v[i];

    }
    long long g =v[0];
    for(long long i =1;i<x;i++){
        g=gcd(g,v[i]);

    }
    long long ans=0;
    for(long long i=1;i*i<=g;i++){
        if(g%i==0){
            ans++;
            if(i!=g/i){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}