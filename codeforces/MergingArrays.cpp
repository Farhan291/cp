// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A 
# include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> v1(n);
  vector<int> v2(m);
  for(int i=0;i<n;i++){
    cin>>v1[i];
  }
  for(int i=0;i<m;i++){
    cin>>v2[i];
  }
  vector<int> v3(n+m);
   int i =0;
   int j =0;
   while(i<v1.size() || j<v2.size()){
     if (j == v2.size() || i < v1.size() && v1[i] < v2[j]){
       v3[i + j] = v1[i];
       i++;
     }
    else{
       v3[i + j] = v2[j];
       j++;
   }
      }
   for(int i=0;i<n+m;i++){
     cout<<v3[i]<<" ";
   }
}

  


