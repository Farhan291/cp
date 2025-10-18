//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C

#include <bits/stdc++.h>
using namespace std; 
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n;i++){
        cin>>v[i];
    }
    
    while(k--){
        int x;
        cin>>x;
        int l=0;
        int h=n-1;
        int ans =n+1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(v[m]<x){
                l = m + 1;
            }
            else{
                ans =m+1;
                h=m-1;
            }

        }
        cout<<ans<<endl;
    }
    return 0;

}