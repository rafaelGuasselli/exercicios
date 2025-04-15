#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj = {{7, 8, 9}, {2, 4, 5}, {1, 3, 4, 5, 6}, {2, 5, 6}, {1, 2, 5, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, {2, 3, 5, 8, 9}, {0, 4, 5, 8}, {0, 4, 5, 6, 7, 8, 9}, {0, 5, 6, 8}};	
vector<ll> xLimits = {0, 45, 270, 1962, 15318, 141975, 990864, 9876753, 98765442, 987654321, 9876543210};

ll s, d;
int possivel;
ll numbersArray[10];
int digits[10];
bitset<10> visited;

int find(int u, int index) {
	ll total = 0;
	for (int i = 0; i <= index; i++) {
		total += numbersArray[i];
	}
	
	if (total == s) {
		possivel = 1;
		for (int i = 0; i <= index; i++) {
			if (i > 0) {
				printf(" ");
			}

			if(numbersArray[i] > 0 && digits[i] > 1+floor(log10(numbersArray[i]))) {
				printf("0");
			}

			printf("%lld", numbersArray[i]);
		}

		printf("\n");
		if (visited.test(0)) {
			return 0;
		}
	} else if (total > s) {
		return 1;
	}

	for (int v: adj[u]) {
		if (!visited.test(v)) {
			int childIndex = index;
			if (digits[childIndex] == d) {
				childIndex++;
			}
			
			visited.set(v);
			numbersArray[childIndex] = numbersArray[childIndex] * 10 + v; 
			digits[childIndex]++;

			int bigger = find(v, childIndex);

			digits[childIndex]--;
			numbersArray[childIndex] = (numbersArray[childIndex] - v) / 10; 
			visited.reset(v);

			if (bigger) {
				break;
			}
		}
	}

	return 0;
}


int main() {
	int instancia = 1;
	while (scanf("%lld %lld", &s, &d) != EOF) {
		if (s == -1 && d == -1) {
			break;
		}

		possivel = 0;
		printf("#%d\n", instancia++);
		visited.reset();
		
		for (int i = 0; i < 10; i++) {
			digits[i] = 0;
			numbersArray[i] = 0;
		}

		if (s <= xLimits[d]) {
			for (int i = 0; i < 10; i++) {
				visited.set(i);
				numbersArray[0] = numbersArray[0] * 10 + i; 
				digits[0]++;

				int bigger = find(i, 0);

				digits[0]--;
				visited.reset(i);
				numbersArray[0] = (numbersArray[0] - i) / 10; 
				
				if (bigger) {
					break;
				}
			}
		}

		if (!possivel) {
			printf("impossivel\n");
		}
	}
	

	return 0;
}