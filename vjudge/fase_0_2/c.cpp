#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++) {
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    
    vector<ll> amigos; amigos.assign(n, 0);
    int atual = 0;
    ll big = 0;
    ll smallest = 1e18;

    for (int i = 0; i < n; i++) {
        amigos[i] += a[i] + b[i];
    }

    for (int i = 0; i < n; i++) {
        big = max(big, amigos[i]);
        smallest = min(smallest, amigos[i]);
    }

    cout<<big-smallest<<endl;
    return 0;
}