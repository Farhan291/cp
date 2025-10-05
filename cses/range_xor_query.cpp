#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,q;
    cin>>n>>q;
    vector<long long> v(n+1,0);
    vector<long long> sum(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    } 
    
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]^v[i];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(sum[b]^sum[a-1])<<endl;
    }
}