//https://codeforces.com/problemset/problem/1730/B 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(vector<int> &v,double m,int n, vector<int> &t){
  //ll t =0;
  vector<double> l;
  vector<double> r;
  for(int i=0;i<n;i++){
    double left=v[i]-(m-t[i]);
    double right=v[i]+(m-t[i]);
    l.push_back(left);
    r.push_back(right);
  }
  //xo in range intersection
  double Left = *max_element(l.begin(), l.end());
  double Right = *min_element(r.begin(), r.end());

  return Left<=Right;
  
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n;i++){
      cin>>v[i];
    }
    vector<int> b(n);
    for(int i=0; i<n;i++){
      cin>>b[i];
    }
    long double l = 0.0L;
    long double h=2e18;
    long double ans=0;
    while(h-l>1e-6){
      double m = l+(h-l)/2;
      if(check(v,m,n,b)){
        ans=m;
        h=m;
      }
      else{
        l=m;
      }
    }
  vector<double> L;
  vector<double> R;
  for(int i=0;i<n;i++){
     double left=(b[i]-ans)+v[i];
    double right=(ans-b[i])+v[i];

       L.push_back(left);
    R.push_back(right);
  }
  //xo in range intersection
  double Left = *max_element(L.begin(), L.end());
  double Right = *min_element(R.begin(), R.end());
  cout << fixed << setprecision(10) << Left << "\n";
    

  

  }
}
