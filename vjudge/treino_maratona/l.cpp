
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n; cin>>n;
    ll remover = 1;
    while (n > 0) {
        if (n & 1 > 0) {
            remover *= 2;
        }
        
        n = n>>1;
    }
    
    cout<<remover<<endl;
    return 0;
}