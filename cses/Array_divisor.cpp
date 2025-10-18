//https://cses.fi/problemset/task/1085
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int k,ll m,vector<int> &v,int n){
   int steps =1;
   ll sum=0;
   for(int i =0; i<n;i++){
     if(sum+v[i]>m){
       steps++;
       sum=v[i];
     }
     else{
            sum+=v[i];
     }


   }
   return steps<=k;
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i =0; i<n;i++){
    cin>>v[i];
  }
  ll l = *max_element(v.begin(), v.end());
  ll h = accumulate(v.begin(), v.end(),0LL);
  ll ans =0;
  while(l<=h){
    ll m = l+(h-l)/2;
    if(check(k,m,v,n)){
      ans =m;
      h=m-1;

    }
    else{
      l=m+1;
    }
  }
  cout<<ans<<endl;

  
}
