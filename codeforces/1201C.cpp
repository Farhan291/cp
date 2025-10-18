#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll m, vector<ll> &v, int n,ll k, ll moves){
  for(int i=n/2;i<n;i++){
    if(m>=v[i]){
      moves+=m-v[i];
    }
    if(moves>k){
      return false;
    }
     }
  return true;

}

int main(){
    int n;
    ll k;
    cin>>n>>k;
    
    vector<ll>  v(n);
    for(int i =0;i<n;i++){
      cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll moves = 0;
    ll l=v[n/2];
    ll h =v[n/2]+k;
    ll ans =0;
    while(l<=h){
      ll m = l+(h-l)/2;
      if(check(m,v,n,k,moves)){
        ans =m;
        l=m+1;
      }
      else{
        h=m-1;
      }
    }
    cout<<ans;


}
