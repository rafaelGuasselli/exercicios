#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> words;
vector<int> visited;
vector<int> dist;
vector<vector<int>> adj;
map<string, int> code;
string input;

int wordDifference(string a, string b) {
    if (a.size() != b.size()) {
        return 100000000;
    }

    int difference = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            difference++;
        }
    }  

    return difference;
}

void bfs(int from, int to) {
    queue<int> queue;
    queue.push(from);
    dist[from] = 0;

    while(!queue.empty() && !visited[to]) {
        int vertice = queue.front(); queue.pop();
        visited[vertice] = 1;

        for (int child: adj[vertice]) {
            if (!visited[child]) {
                visited[child] = 1;
                dist[child] = dist[vertice] + 1;
                queue.push(child);
            }
        }
    }
}

int main() {
    getline(cin, input);
    stringstream parser(input);
    int nTests; parser>>nTests;

    getline(cin, input);
    for (int i = 0; i < nTests; i++) {
        adj.clear();
        words.clear();
        code.clear();

        if (i > 0) {
            cout<<endl;
        }

        while (true) {
            getline(cin, input);
            if (input == "*") {
                break;
            }

            if (code.find(input) != code.end()) {
                continue;
            }

            code[input] = words.size();
            words.push_back(input);
            adj.push_back({});
            dist.push_back(0);
            visited.push_back(0);

            for (string word: words) {
                if (wordDifference(input, word) == 1) {
                    adj[code[input]].push_back(code[word]);
                    adj[code[word]].push_back(code[input]);
                }
            }
        }

        while (!cin.eof()) {
            getline(cin, input);
            if (input.size() == 0 || input == "" || input.empty()) {
                break;
            }
            
            stringstream parser(input);
            string from, to; parser>>from>>to;
            
            visited.assign(words.size(), 0);
            dist.assign(words.size(), 0);
            
            bfs(code[from], code[to]);
            cout<<from<<" "<<to<<" "<<dist[code[to]]<<endl;
        }
    }

    return 0;
}