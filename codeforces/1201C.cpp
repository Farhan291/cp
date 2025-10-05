#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> v(n);
    for(int i=0; i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i =0; i<k;i++){
        if(v[n/2]<v[(n/2)+1]){
        v[n/2]++;
    }
    else{
        long long temp=0;
        temp = v[n/2];
        v[(n/2)]=v[(n/2)+1];
        v[(n/2)+1] = temp;
    }
        
    }
    cout<<v[n/2];
    return 0;
    
}