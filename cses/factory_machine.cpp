#include <bits/stdc++.h>
using namespace std;

bool check(long long time,vector<int> &v,long long n,long long t){
    long long p =0;
    for(long long i=0;i<n;i++){
        p=p+time/v[i];
        if (p>=t) return true;
    }
    return false;
    


}


int main(){
    long long n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(long long i=0; i<n;i++){
        cin>>v[i];
    }
    long long lo =0;
    long long hi = *(min_element(v.begin(),v.end()))*t;
    while(lo<hi){
        long long mid = lo+ (hi-lo)/2;
        if(check(mid,v,n,t)){
            hi=mid;
        }
        else{
            lo=mid+1;
        }

    }
    cout<<lo;


}