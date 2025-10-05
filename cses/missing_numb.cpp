#include <bits/stdc++.h>
int main(void)
{
    long long n;
    std::cin>>n;
    long long m = n - 1;
    std::set<int> s;
    while (m--)
    {
        long long x;
        std::cin>>x;
        s.insert(x);
        

    }
    for(long long i =1; i<=n;i++){
        if(s.find(i)==s.end()){
            std::cout<<int(i);
        }

    }
    return 0;
}
