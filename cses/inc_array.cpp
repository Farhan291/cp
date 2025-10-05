#include <bits/stdc++.h>
int main(void){
    int n;
    long long ans=0;
    std::cin>>n;
    std::vector<int> v;
    for (int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        v.push_back(x);
    }
    for(int i=1;i<n;i++){
        if(v[i-1]>v[i]){
            ans = ans+(v[i-1]-v[i]);
            v[i] = v[i-1];


        }
    }
    std::cout<<ans;

   return 0;
}