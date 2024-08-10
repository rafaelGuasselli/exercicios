#include <bits/stdc++.h>
using namespace std;
int main() {
    double r1, x1, y1, r2, x2, y2; 
    while (cin>>r1>>x1>>y1>>r2>>x2>>y2) {
        double biggestDistance = r2 + sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        if (r1 >=  biggestDistance) {
            cout<<"RICO"<<endl;
        } else {
            cout<<"MORTO"<<endl;
        }
    }

    return 0;
}