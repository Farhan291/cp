#include <bits/stdc++.h>
int main(void){
    int n;
    std::cin>>n;

    if(n==1){
        std::cout<<1;
        return 0;
    }
    else if (n==2|| n==3)
    {
        std::cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            std::cout<<i<<' ';
        }

    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            std::cout<<i<<' ';
        }

    }
    return 0;
    
    
}