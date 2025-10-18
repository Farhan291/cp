#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<pair<string, string>> s;
    string tree, color;
    while(n--){
        cin>>tree >> color;
        s.insert({tree,color});
        

    }
    cout<<s.size();
    return 0;
}