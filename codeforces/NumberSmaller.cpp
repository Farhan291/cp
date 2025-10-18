// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B 
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  vector<int> b(m);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<m;i++){
    cin>>b[i];
  }
  int i =0;
  int j =0;
  int c=0;
  while(i<a.size()|| j<b.size()){
    if(j==b.size()|| i<a.size() && b[j]>a[i]){
      c++;
      i++;

    }
    else{
      cout<<c<<" ";
      j++;
    }
  }
}
