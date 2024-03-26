#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string input;

    while (true) {
        cin >> input;
        if (input == "#") {
            break;
        }

        bool proximoExiste = next_permutation(input.begin(), input.end());
        if (proximoExiste) {
            cout<<input<<endl;
        } else {
            cout<<"No Successor"<<endl;
        }
    }

    return 0;
}