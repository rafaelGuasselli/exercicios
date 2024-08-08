#include <queue>
#include <iostream>
#include <stack>

using namespace std;
int main() {
    while (true) {
        int qdtVagoes; cin>>qdtVagoes;
        if (qdtVagoes == 0) {
            break;
        }

        while (true) {
            stack<int> pilha;
            queue<int> vagoes;
            queue<int> ordem;

            int primeiro; cin>>primeiro;
            if (primeiro == 0) {
                break;
            }

            ordem.push(primeiro);
            for (int i = 0; i < qdtVagoes-1; i++) {
                int elemento; cin>>elemento;
                ordem.push(elemento);
                vagoes.push(i+1);
            }

            vagoes.push(qdtVagoes);

            int proximo = ordem.front(); ordem.pop();
            while (vagoes.size() > 0) {
                pilha.push(vagoes.front()); vagoes.pop();

                while (pilha.size() > 0 && pilha.top() == proximo) {
                    pilha.pop();
                    if (ordem.size() > 0) proximo = ordem.front(); ordem.pop();
                }
            }

            if (pilha.size() == 0) {
                cout<<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
        }

        cout<<endl;
    }

    return 0;
}