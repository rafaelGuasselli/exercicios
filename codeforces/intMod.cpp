#include<bits/stdc++.h>
#define numeral long long
using namespace std;

class intMod{
 public:
	numeral value;
	numeral mod = 998244353LL;

	intMod() {}

	friend istream& operator>>(istream& in, intMod& a) {
        in>>a.value;
		return in;
    }

	void operator = (numeral valor) {
		value = valor;
	}

	void operator + (numeral valor) {
		value = (value + valor) % mod;
	}

	void operator * (numeral valor) {
		value = ((value % mod) * (valor % mod)) % mod;
	}

	void operator - (numeral valor) {
		value = (value - valor) % mod;
	}

	void operator / (numeral valor) {
		value = ((value% mod) / (valor% mod));
	}

	bool operator < (intMod& a) {
		return value < a.value;
	}

	bool operator > (intMod& a) {
		return value > a.value;
	}
};

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	return 0;
}