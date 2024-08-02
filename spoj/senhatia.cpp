#include<bits/stdc++.h>
using namespace std;

int main() {
	int nChars, nLower, nUpper, nNumbers; scanf("%d %d %d %d", &nChars, &nLower, &nUpper, &nNumbers);
	char senha[1000]; scanf("%s", &senha[0]);
	
	int chars = strlen(senha);
	int lowers = 0; 
	int uppers = 0;
	int numbers = 0; 

	for (int i = 0; i < strlen(senha); i++) {
		if (isupper(senha[i]) ) {
			uppers++;
		} 

		if (islower(senha[i])) {
			lowers++;
		}

		if (isdigit(senha[i])) {
			numbers++;
		}
	}

	if (chars >= nChars && lowers >= nLower && uppers >= nUpper && numbers >= nNumbers) {
		printf("Ok =/");
	} else {
		printf("Ufa :)");
	}

	return 0;
}