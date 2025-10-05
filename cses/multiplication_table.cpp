#include <bits/stdc++.h>
using namespace std;

long long counts(long long x, long long n){

    long long count=0;
    for(long long i=1;i<=n;i++){
        count+=min(n,x/i);
    }
    return count;

}

int main()
{
    long long n;
    cin >> n;
    long long lo =1;
    long long hi =n*n;
    long long median = (n*n +1)/2;
    while(lo<hi){
        long long mid = lo +(hi-lo)/2;
        if(counts(mid,n)>=median){
            hi=mid;
        }
        else{
            lo=mid+1;
        }


    }
    cout<<lo;
    return 0;
    
}