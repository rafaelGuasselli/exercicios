#include <queue>
#include <vector>
#include <iostream>

using namespace std;
int main(){
    while (true) {
        priority_queue<int, vector<int>, greater<int> > queue;
        int qtdElementos; cin >> qtdElementos;
        if (qtdElementos == 0) {
            break;
        }

        for (int i = 0; i < qtdElementos; i++) {
            int elemento; cin >> elemento;
            queue.push(elemento);
        }

        int custoTotal = 0;
        while (queue.size() > 1) {
            int elementoA = queue.top(); queue.pop();
            int elementoB = queue.top(); queue.pop();

            int soma = elementoA + elementoB;
            custoTotal += soma;

            queue.push(soma);
        }
        
        cout<<custoTotal<<endl;
    }


    return 0;
}