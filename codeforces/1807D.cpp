#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main(void){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<long long> v(n+1,0);
        vector<long long> v1(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>v[i];
            v1[i]=v1[i-1]+v[i];
        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            long long total_sum = v1[n];
            long long sum = total_sum - (v1[r]-v1[l-1]) + (r-l+1)*k;
            if(sum&1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        

    }
}