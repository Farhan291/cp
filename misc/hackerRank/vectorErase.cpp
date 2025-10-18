// https://www.hackerrank.com/challenges/vector-erase/problem
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int t;
    cin>>t;
    for(int i =0; i<n;i++){
        cin>>v[i];
    }
    v.erase(v.begin()+t -1);
    int l,r;
    cin>>l>>r;
    v.erase(v.begin()+l-1,v.begin()+r);
    cout<<v.size()<<endl;

    for(auto value: v){
        cout<< value <<"\t";
    }

    return 0;
}