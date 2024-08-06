#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0

using namespace std;

ll distance2(ll x1, ll y1, ll x2, ll y2) {
    return pow(x1-x2, 2) + pow(y1-y2, 2);
}

int main() {
    int n; cin>>n;
    int a, b, alvoX, alvoY; cin>>a>>b>>alvoX>>alvoY;
    vector<ll> timeA;
    vector<ll> timeB;

    for (int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        if (x > a || y > b || x < 0 || y < 0) {
            continue;
        }

        timeA.push_back(distance2(x, y, alvoX, alvoY));
    }

    for (int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        if (x > a || y > b || x < 0 || y < 0) {
            continue;
        }

        timeB.push_back(distance2(x, y, alvoX, alvoY));
    }

    sort(timeA.begin(), timeA.end());
    sort(timeB.begin(), timeB.end());

    char winner = 'A';
    ll smallest = 0;
    if (timeA[0] < timeB[0]) {
        winner = 'A';
        smallest = timeB[0];
    } else {
        winner = 'R';
        smallest = timeA[0];
    }

    int points = 0;
    for (int i = 0; i < n; i++) {
        if (winner == 'A') {
            if (timeA[i] < smallest) {
                points++;
            } else {
                break;
            }
        } else {
            if (timeB[i] < smallest) {
                points++;
            } else {
                break;
            }
        }
    }

    cout<<winner<<" "<<points<<endl;

    return 0;
}