//https://codeforces.com/contest/1703/problem/F
#include <bits/stdc++.h>
using namespace std;

bool check(int j, vector<int> &v,int i){
  if(j+1>v[j]){
    return i+1<j+1;
  }
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    for(int i=0;i<n;i++){
      if(v[i]<i+1){
        int l =0;
        int h =n-1;
        long long count =0;
        while(l<=h){
          int m = l+(h-l)/2;
          if(check(m,v,i)){
            count++;
          }

        }
      }
    }
  }

}
