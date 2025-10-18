#include <bits/stdc++.h>
using namespace  std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> v(n);
  vector<int> w(m);
  for(int i=0;i<n;i++){
    cin>>v[i];

  }
  for(int i=0;i<m;i++){
    cin>>w[i];
  }
  sort(v.begin(),v.end());
  for(int i=0;i<m;i++){
    int l =0;
    int h=n-1;
    int ans =0;
    while(l<=h){
      int m = l+(h-l)/2;
      if(v[m]<=w[i]){
        ans=m+1;
        
        l=m+1;
      }
      else{
        h=m-1;
      }
    }
    cout<<ans<<" ";
  }
  

}
