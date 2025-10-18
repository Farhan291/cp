// https://cses.fi/problemset/task/1090
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n,x;
  cin>>n>>x;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  ll count =0;
  for(auto val:v){
    ll rem = x-v;
    ll l=0;
    ll h=n-1;
    ll ans=0;
    while(l<=h){
      ll m= l+(h-l)/2;
      if(v[m]<=rem){
        ans=m;
        l=m+1;
      }
      else{
        h=m+1;
      }
    }
   v.erase(ans);
   count++;
  }

