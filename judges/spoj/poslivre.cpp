#include<bits/stdc++.h>

using namespace std;
bitset<505> pos[505];

int main() {
    int w, h, n;
    while (cin>>w>>h>>n) {
        if (w == 0 && h == 0 && n == 0) {
            break;
        }
        
        for (int i = 0; i <= h; i++) {
            pos[i].set();
        }
        
        int total = w * h;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            x1--; y1--; x2--; y2--;

            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                for (int x = min(x1, x2); x <= max(x1, x2); x++) {
                    if (pos[y].test(x)) {
                        total--;
                        pos[y].reset(x);
                    }
                }
            }
        }

        if (total <= 0) {
            cout<<"There is no empty spots."<<endl;
        } else if (total == 1) {
            cout<<"There is one empty spot."<<endl;
        } else {
            cout<<"There are "<<total<<" empty spots."<<endl;
        }
    }

    return 0;
}