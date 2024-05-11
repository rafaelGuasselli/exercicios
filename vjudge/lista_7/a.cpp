#include<bits/stdc++.h>

using namespace std;

char matrix[100][100];
bool visited[100][100];
int row = 0;
int column = 0;


int dfs(int l, int c) {
    if (l < 0 || c < 0 || l >= row || c >= column) {
        return 0;
    }

    if (matrix[l][c] == 'L') {
        return 0;
    }

    if (visited[l][c]) {
        return 0;
    }

    visited[l][c] = true;
    int soma = 1;
    vector<pair<int, int>> lookUp = {{l+1, c}, {l-1, c}, {l, c+1}, {l, c-1}, {l+1, c+1}, {l+1, c-1}, {l-1, c+1}, {l-1, c-1}};
    

    for (auto look: lookUp) {
        soma += dfs(look.first, look.second);
    }

    return soma;
}


int main() {
    string line;
    getline(cin, line);
    stringstream inp(line);

    int nTest; inp>>nTest;
    getline(cin, line);
    for (int t = 0; t < nTest; t++) {
        row = 0;

        if (t > 0) {
            cout<<endl;
        }

        while (!cin.eof()) {     
            getline(cin, line);

            if (line.size() == 0 || line == "" || line.empty()) {
                break;
            }

            if (isdigit(line[0])) {
                for (int l = 0; l < row; l++) {
                    for (int c = 0; c < column; c++) {
                        visited[l][c] = false;
                    }
                }

                stringstream inp(line);
                int l, c; inp>>l>>c;
                l -= 1; c -= 1;

                cout<<dfs(l, c)<<endl;
                continue;
            } else {
                for (int c = 0; c < line.size(); c++) {
                    matrix[row][c] = line[c];
                }

                row++;
                column = line.size();
            }
        }
    }

    return 0;
}