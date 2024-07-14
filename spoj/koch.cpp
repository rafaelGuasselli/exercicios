#include<bits/stdc++.h>
#define ll long long
using namespace std;

int values[100000000];
ll pisano(long m) {
    ll limit = 0;
    values[0] = 0;
    values[1] = 1;
    for (ll i = 2; i < 100000000; i++) {
        values[i] = (values[i-1] + values[i-2]) % m; 
        if (values[i-1] == 0 && values[i] == 1) {
            limit = i-1;
            break;
        }
    }
    
    return limit;
}
 

int main() {
    int nTests; cin>>nTests;
    ll limit = pisano(1000);
    for (int t = 0; t < nTests; t++) {
        string n; cin>>n;
        
        ll index = 0;
        for (char a: n) {
            int digit = a-'0';
            index = (index*10 + digit) % limit;
        }

        index = ((index)%limit);
        cout<<setfill('0')<<setw(3)<<values[index]<<endl;
    }

    return 0;
}