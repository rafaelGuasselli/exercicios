#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	char save[105]; cin>>save;
	int index = 0;
	int result = 0;
	while (!cin.eof()) {
		char b; cin>>b;
		char a = save[index];

		if (a == 0 || b == 0) {
			break;
		}

		if (tolower(a) == tolower(b)) {
			index++;
		} else if (tolower(a) > tolower(b)){
			result = 1;
			break;
		} else {
			result = -1;
			break;
		}
	}

	cout<<result<<endl;
	return 0;
}