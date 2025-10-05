#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<3){
            cout<<-1;
            return 0;
        }
        int k = n/2 +1;
        vector <long long> v(n);
        for(int i =0; i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        
    }
}