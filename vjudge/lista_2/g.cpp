#include <iostream>
#include <bits/stdc++.h>

#define QTD_TIMES 100
#define QTD_QUESTOES 9


using namespace std;

struct Time{
	int id, penalidade;
	set<int> resolvidos;
};

int main() {
	string entrada;
	getline(cin, entrada);
	int qtdTestes = stoi(entrada);

	getline(cin, entrada);
	for (int i = 0; i < qtdTestes; i++) {
		Time times[QTD_TIMES];
		int penalidades[QTD_TIMES][QTD_QUESTOES] = {};

		for (int i = 0; i < QTD_TIMES; i++) {
			times[i].id = -1;
			times[i].penalidade = 0;
		}

		while(true){
			string line;
			if (!getline(cin, line)) {
				break;
			}

			if (line.empty()) {
				break;
			}

			stringstream input(line);
			int time, questao, tempo;
			char evento;

			input>>time>>questao>>tempo>>evento;

			time -= 1;
			questao -= 1;


			times[time].id = time+1;

			if (evento == 'C' && times[time].resolvidos.find(questao) == times[time].resolvidos.end()) {
				times[time].penalidade += tempo + penalidades[time][questao];
				times[time].resolvidos.insert(questao);
			} else if (evento == 'I') {
				penalidades[time][questao] += 20;
			}
		}

		int n = sizeof(times)/sizeof(times[0]);
		stable_sort(times, times + n, [](Time a, Time b) {
			return a.penalidade < b.penalidade;
		});

		stable_sort(times, times + n, [](Time a, Time b) {
			return a.resolvidos.size() > b.resolvidos.size();
		});

		for (int i = 0; i < QTD_TIMES; i++) {
			if (times[i].id == -1) {
				continue;
			}

			cout<<times[i].id<<" "<<times[i].resolvidos.size()<<" "<<times[i].penalidade<<endl;
		}

		if (i+1 != qtdTestes) cout<<endl;
	}	

	return 0;
}