#include<bits/stdc++.h>
#define int long long

using namespace std;

struct GEO {
	string type; // "reta", "ponto"
	int a, b, l, r; // for "reta": ax+b, and valid x in [l, r]. For "ponto": a = x, b = y.

	bool operator<(const GEO &other) const {
		if (type != other.type) {
			return type == "ponto";
		} else if (a != other.a) {
			return a < other.a;
		} else if (b != other.b) {
			return b < other.b;
		} else if (l != other.l) {
			return l < other.l;
		} else {
			return r < other.r;
		}
	}
};

GEO intersect(const GEO &retaA, const GEO &retaB) {
	string typeA = retaA.type; string typeB = retaB.type;
	int a = retaA.a, b = retaA.b, lxa = retaA.l, rxa = retaA.r;
	int c = retaB.a, d = retaB.b, lxb = retaB.l, rxb = retaB.r;
	
	int lxc = max(lxa, lxb);
	int rxc = min(rxa, rxb);
	
	if(lxc > rxc) return {};
	
	if(typeA == "reta" && typeB == "reta") {
		if(a != c) {
			double denominator = a - c;
			double x = (d - b) / denominator;
			double y = x * a + b;
			
			if(x == (int)x && y == (int)y && x >= lxc && x <= rxc) {
				return GEO{"ponto", (int)x, (int)y, (int)x, (int)x};
			}
		} else if(a == c && b == d) {
			return GEO{"reta", a, b, lxc, rxc};
		}
	} else if(typeA == "ponto" && typeB == "ponto" && a == c && b == d) {
		return retaA;
	} else if(typeA == "ponto" && typeB == "reta" && a * c + d == b) {
		return GEO{"ponto", a, b, a, a};
	} else if(typeA == "reta" && typeB == "ponto" && c * a + b == d) {
		return GEO{"ponto", c, d, c, c};
	}

	return {};
}

set<GEO> construirRetas(int a, int b, int c) {
	set<GEO> retas;
	retas.insert(GEO{"reta",  1, b + c - a, a - c,		a});
	retas.insert(GEO{"reta", -1, a + b + c,   a,    a + c});
	retas.insert(GEO{"reta",  1, b - a - c,   a,    a + c});
	retas.insert(GEO{"reta", -1, a + b - c, a - c, 		a});
	return retas;
}

vector<pair<int,int>> construirPontos(const GEO &reta) {
	vector<pair<int,int>> pontos;
	if(reta.type == "ponto") {
		pontos.emplace_back(reta.a, reta.b);
	} else if(reta.type == "reta") {
		for (int x = reta.l; x <= reta.r; x++) {
			int y = x * reta.a + reta.b;
			pontos.emplace_back(x, y);
		}
	}
	return pontos;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin>>n;
	int a, b, c; cin>>a>>b>>c;
	set<GEO> retas = construirRetas(a, b, c);
	
	for (int k = 1; k < n; k++){
		cin>>a>>b>>c;
		set<GEO> novasRetas = construirRetas(a, b, c);
		set<GEO> interRetas;
		for (const auto &r1 : retas) {
			for (const auto &r2 : novasRetas) {
				auto inter = intersect(r1, r2);
				if(inter.type != ""){
					interRetas.insert(inter);
				}
			}
		}
		retas.clear();
		retas.insert(interRetas.begin(), interRetas.end());
	}
	
	set<pair<int,int>> pontos;
	for (const auto &r : retas) {
		vector<pair<int,int>> pts = construirPontos(r);
		for(auto &p: pts) {
			pontos.insert(p);
		}
	}
	for(auto &p : pontos) {
		cout<<p.first<<" "<<p.second<<"\n";
	}
//lkasjdflçkasjlçfkdazjçklsd
	
	return 0;
}