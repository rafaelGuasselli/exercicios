#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    vector<int> lista;
    int nextValue;

    while (cin >> nextValue) {
        lista.push_back(nextValue);

        int tamanho = lista.size();
        if (tamanho % 2 == 0) {
            int meio = floor(tamanho/2);
            nth_element(lista.begin(), lista.begin()+meio, lista.end());
            nth_element(lista.begin(), lista.begin()+meio-1, lista.end());

            int mediana1 = lista[meio];
            int mediana2 = lista[meio-1];
            int mediana = (mediana1+mediana2)/2;
            cout<<mediana<<endl;
        } else {
            int meio = floor(tamanho/2);
            nth_element(lista.begin(), lista.begin()+meio, lista.end());
            int mediana = lista[meio];
            cout<<mediana<<endl;
        }
    }
    
    return 0;
}