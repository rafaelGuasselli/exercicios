#include <queue>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    while (true) {
        queue<int> cartas;
        vector<int> cartasDescartadas;

        int qtdCartas; cin>>qtdCartas;
        if (qtdCartas == 0) {
            break;
        }

        for (int i = 1; i <= qtdCartas; i++) {
            cartas.push(i);
        }

        while (cartas.size() >= 2) {
            int front = cartas.front(); cartas.pop();
            int nFront = cartas.front(); cartas.pop();
            cartasDescartadas.push_back(front);
            cartas.push(nFront);
        }

        cout<<"Discarded cards:";
        for (int i = 0; i < cartasDescartadas.size(); i++) {
            cout<<" "<<cartasDescartadas[i];
            if ((i+1) != cartasDescartadas.size()) {
                cout<<",";
            }
        }
        cout<<endl;
        cout<<"Remaining card: "<<cartas.front()<<endl;
    }

    return 0;
}