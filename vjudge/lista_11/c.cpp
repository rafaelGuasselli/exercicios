#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

#define EPS 1e-9
#define PI 3.14159265358979323846264338327950

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

double dot(pii a, pii b) { 
	return (a.first * b.first + a.second * b.second); 
}

pii toVector(pii a, pii b) {
	return {b.first-a.first, b.second-a.second};
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

double angle(pii a, pii o, pii b) { 
	pii oa = toVector(o, a); 
	pii ob = toVector(o, b);
	return acos(dot(oa, ob) / sqrt(dot(oa, oa) * dot(ob, ob))); 
}

bool isInside(pii point, vector<pii> &points){
	if (points.size() < 3) return 0;

	double sum = 0;
	for (int i = 0; i < points.size(); i++) {
		pii next;
		
		if (i + 1 == points.size()) {
			next = points[0];
		} else {
			next = points[i+1];
		}

		if (point == points[i]) {
			return 1;
		}

		if (sign(crossRelative(point, points[i], next)) == 1) {
			sum += angle(points[i], point, next);
		} else {
			sum -= angle(points[i], point, next);
		}
	}

	return fabs(fabs(sum) - 2*PI) < EPS; 
}

void hull(vector<pii> &points) {
	if (points.size() == 0) return;

	sort(points.begin(), points.end());
	firstPoint = points[0];
	sort(points.begin(), points.end(), lessThan);

	stack<pii> s;
	for (int i = 0; i < min(3, (int)points.size()); i++) {
		s.push(points[i]);
	}

	for (int i = 3; i < points.size(); i++) {
		while (s.size() > 1 && sign(crossRelative(nextToTop(s), s.top(), points[i])) != 1) {
			s.pop();
		}

		s.push(points[i]);
	}

	points.clear();
	while(!s.empty()) {
		points.push_back(s.top()); s.pop();
	}
}

int main() {
	int count = 1;
	while (1) {
		int nCops, nRobbers, nCitzens; cin>>nCops>>nRobbers>>nCitzens;
		vector<pii> cops(nCops), robbers(nRobbers);
		vector<piii> citzens(nCitzens);

		if (nCops == 0 && nRobbers == 0 && nCitzens == 0) {
			break;
		}

		for (int i = 0; i < nCops; i++) {
			cin>>cops[i].second;
			cin>>cops[i].first;
		}	

		for (int i = 0; i < nRobbers; i++) {
			cin>>robbers[i].second;
			cin>>robbers[i].first;
		}	

		for (int i = 0; i < nCitzens; i++) {
			cin>>citzens[i].second.second;
			cin>>citzens[i].second.first;
			citzens[i].first = 0;
		}

		hull(cops);
		hull(robbers);
		
		for (piii &citzen: citzens) {
			if (isInside(citzen.second, cops)) {
				citzen.first = 1;
			} else if (isInside(citzen.second, robbers)) {
				citzen.first = 2;
			}
		}

		cout<<"Data set "<<count++<<":"<<endl;
		for (piii &citzen: citzens) {
			cout<<"     Citizen at ("<<citzen.second.second<<","<<citzen.second.first<<") is ";
			if (citzen.first == 0) {
				cout<<"neither."<<endl;
			} else if (citzen.first == 1) {
				cout<<"safe."<<endl;
			} else {
				cout<<"robbed."<<endl;
			}
		}
		cout<<endl;
	}

    return 0;
}