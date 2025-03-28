#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n;
    int total = 0;
    
    for (int i = 0; i < n; i++) {
        int pretas = 0;
        for (int j = 0; j < n; j++) {
            char val; cin>>val;
            if (val == 'N') {
                pretas++;
            } else {
                total += pretas/2;
                pretas = 0;
            }
        }
        
        total += pretas/2;
    }

    cout<<total<<endl;

    return 0;
}