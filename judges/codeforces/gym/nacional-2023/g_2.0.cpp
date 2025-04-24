#include <bits/stdc++.h>
#define int long long

using namespace std;

struct GEO {
	int a, b, l, r; // y = a*x + b for x in [l, r].

	bool operator<(const GEO &other) const {
		if (a != other.a)
			return a < other.a;
		else if (b != other.b)
			return b < other.b;
		else if (l != other.l)
			return l < other.l;
		else
			return r < other.r;
	}
};

GEO intersect(const GEO &retaA, const GEO &retaB) {
	int a = retaA.a, b = retaA.b, lxa = retaA.l, rxa = retaA.r;
	int c = retaB.a, d = retaB.b, lxb = retaB.l, rxb = retaB.r;
	
	int lxc = max(lxa, lxb);
	int rxc = min(rxa, rxb);
	
	if(lxc > rxc) {
		return GEO{0, 0, 1, 0}; 
	}

	if(a != c) {
		double denominator = a - c;
		double x = (d - b) / denominator;
		double y = x * a + b;
		
		if(x == (int)x && y == (int)y && x >= lxc && x <= rxc) {
			return GEO{a, b, (int)x, (int)x};
		}
	} else if(b == d) {
		return GEO{a, b, lxc, rxc};
	}

	return GEO{0, 0, 1, 0};
}

set<GEO> construirRetas(int a, int b, int c) {
	set<GEO> retas;
	retas.insert(GEO{1, b + c - a, a - c, a});
	retas.insert(GEO{-1, a + b + c, a, a + c});
	retas.insert(GEO{1, b - a - c, a, a + c});
	retas.insert(GEO{-1, a + b - c,  a - c, a});
	return retas;
}

vector<pair<int,int>> construirPontos(const GEO &reta) {
	vector<pair<int,int>> pontos;
	for (int x = reta.l; x <= reta.r; x++) {
		int y = x * reta.a + reta.b;
		pontos.emplace_back(x, y);
	}
	return pontos;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; 
	cin >> n;
	int a, b, c; 
	cin >> a >> b >> c;
	set<GEO> retas = construirRetas(a, b, c);
	
	for (int k = 1; k < n; k++){
		cin >> a >> b >> c;
		set<GEO> novasRetas = construirRetas(a, b, c);
		set<GEO> interRetas;
		for (const auto &r1 : retas) {
			for (const auto &r2 : novasRetas) {
				auto inter = intersect(r1, r2);
				if(inter.l <= inter.r) {
					interRetas.insert(inter);
				}
			}
		}
		retas = move(interRetas);
	}
	
	set<pair<int,int>> pontos;
	for (const auto &r : retas) {
		vector<pair<int,int>> pts = construirPontos(r);
		for(auto &p: pts) {
			pontos.insert(p);
		}
	}
	for(auto &p : pontos) {
		cout << p.first << " " << p.second << "\n";
	}
	
	return 0;
}
