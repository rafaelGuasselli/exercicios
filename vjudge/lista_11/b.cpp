#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;
pii firstPoint;

int sign(ll val) {
	if (val==0) {
		return 0;
	} else if (val < 0) {
		return -1;
	} else {
		return 1;
	}
}

ll cross(pii a, pii b) {
	return a.second*b.first - a.first*b.second;
}

ll crossRelative(pii a, pii b, pii c) {
	return cross({b.first-a.first, b.second-a.second}, {c.first-a.first, c.second-a.second});
}

bool lessThan(pii &a, pii &b){
	if (a == firstPoint) return 1;
	int side = sign(crossRelative(firstPoint, a, b));
	return side == 1;
}

pii nextToTop(stack<pii> &S){
	pii p = S.top();
    S.pop();
    pii res = S.top();
    S.push(p);
    return res;
}

int main() {
	while (1) {
		int n; cin>>n;
		if (n == 0) {
			break;
		}

		vector<pii> points;
		set<pii> p;
			
		for (int i = 0; i < n; i++) {
			int x, y; cin>>x>>y;
			p.insert({y, x});
		}

		for (pii point:p) {
			points.push_back(point);
		}

		sort(points.begin(), points.end());
		firstPoint = points[0];
		sort(points.begin(), points.end(), lessThan);

		stack<pii> pilha;
		for (int i = 0; i < min(3, (int)points.size()); i++) {
			pilha.push(points[i]);
		}

		for (int i = 3; i < points.size(); i++) {
			while (pilha.size() > 1 && sign(crossRelative(nextToTop(pilha), pilha.top(), points[i])) != 1) {
				pilha.pop();
			}

			pilha.push(points[i]);
		}	

		vector<pii> pointsToPrint;
		while (!pilha.empty()) {
			pii point = pilha.top(); pilha.pop();
			pointsToPrint.push_back(point);
		}

		firstPoint = {0,0};
		sort(pointsToPrint.begin(), pointsToPrint.end(), lessThan);
	
		cout<<pointsToPrint.size()<<endl;
		for (pii point:pointsToPrint) {
			cout<<point.second<<" "<<point.first<<endl;
		}
	}
    return 0;
}