#include <bits/stdc++.h>
int main(void)
{
    std::string s;
    std::cin>>s;
    long long n=1;
    long long x =1;
    std::vector<int> v;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]){
            n++;
        }
        else{
            v.push_back(n);
            n=1;
        }

    }
    v.push_back(n);
    x = *std::max_element(v.begin(),v.end());
    std::cout<<x;

}