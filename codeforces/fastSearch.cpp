// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int k;
    cin>>k;
    while(k--){
        int l,r;
        cin>>l>>r;
        int low1 =0;
        int high1 =n-1;
        int low2=0;
        int high2=n-1;
        int ans1 =0;
        int ans2=0;
        while(low1<=high1){
            int m =low1+(high1-low1)/2;
            if(v[m]<l){
               ans1 = m+1;
               low1 =m+1;
            }
            else{
                high1=m-1;
            }

        }
        while(low2<=high2){
            int m =low2+(high2-low2)/2;
            if(v[m]<=r){
               ans2 = m+1;
               low2=m+1;
            }
            else{
                high2=m-1;
            }

        }
        cout<<ans2-ans1<<" "; 


    }
}