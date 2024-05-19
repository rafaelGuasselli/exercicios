#include <bits/stdc++.h>

// 5 8 3 10 7
// 2 2 1 3  2 // 8
// x        x
// 2 2 1 3  2 // 5
// x     x
// 2 2 1 3  2 // 3
// x x   x  x


// 3 2 1
// 1 5 1 // 5
// x x x
// 1 5 1 // 6
// x   x

using namespace std;

vector<int> sacos;

bool verifica(int alvo, long long int maximo) // alvo é o numero de competidores e maximo é o de segundos que cada competidor usa
{
    int sum = 0;
    int cont = 1;
    int tam = sacos.size();
    
    for (int i = 0; i < tam;i++)
    {
        sum += sacos[i];
        
        if (sacos[i] > maximo)
            return false;
        
		if (sum > maximo)
		{
			cont++;
			sum = sacos[i];
		}
    }
    return cont <= alvo;
}

int main()
{
    int n,c,t,a;
    int maior = 0;
    
    cin >> n >> c >> t;

    while (n--)
    {
        cin >> a;
        sacos.push_back(a);
    }
    
    long long int low = 0, high = 10e8;
    long long int mid = low + (low + high)/2;
    int res = 0;
    while (high >=low)
    {
        mid = low + (high - low)/2;
        if (verifica(c, mid * t))
		{
            high = mid -1 ;
			res = mid;
		}
        else
            low = mid + 1;
        // cout << low << " ==== " << mid << " ==== " << high <<  endl;
    }
    
	// cout << mid * t << endl;
	// cout << verifica(c, mid*t)<<endl;
    
    
    cout << res<<endl;
    return 0;
}