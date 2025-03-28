#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0

using namespace std;

int main() {
    int a, b, c, d; cin>>a>>b>>c>>d;
    cin>>a>>b>>c>>d;
    int winsA = 0;
    int winsB = 0;
    if (a > b) {
        winsA++;
    } else if (a < b) {
        winsB++;
    } 

    if (c > d) {
        winsA++;
    } else if (c < d) {
        winsB++;
    }

    if (winsA > winsB) {
        cout<<"A"<<endl;
    } else if (winsA < winsB) {
        cout<<"P"<<endl;
    } else {
        if (a+c > b+d) {
            cout<<"A"<<endl;
        } else if (a+c < b+d) {
            cout<<"P"<<endl;
        } else {
            cout<<"D"<<endl;
        }
    }

    return 0;
}