#include<bits/stdc++.h>
#include<math.h>
#define MAX(a, b) (a < b) ? b : a
#define PI 3.14159265

using namespace std;

struct Point{
	int y, x;
};

vector<pair<double, pair<double, int>>> lines;
double derivada(double x1, double x2, double y1, double y2){
	return (y2-y1)/(x2-x1);
}

double acharB(double derivada, double y, double x){
	return y - derivada * x;
}

vector<Point> points;
int main(){
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int nPoints; cin>>nPoints;

		lines.clear();
		points.clear(); 
		points.assign(nPoints, {});
		
		for (int i = 0; i < nPoints; i++) {
			cin>>points[i].x;
			cin>>points[i].y;
		}

		for (int i = 0; i < nPoints; i++) {
			for (int j = i+1; j < nPoints; j++) {
				int x1 = points[i].x;
				int x2 = points[j].x;
				int y1 = points[i].y;
				int y2 = points[j].y;

				if (x1 == x2) {
					lines.push_back({90, {x1, i}});
					lines.push_back({90, {x1, j}});
				} else if(y1 == y2){
					lines.push_back({0, {y1, i}});
					lines.push_back({0, {y1, j}});
				} else {
					double a = derivada(x1, x2, y1, y2);
					double b = acharB(a, y1, x1);
					double angle = atan(a)*180/PI;
					lines.push_back({angle, {b, i}});
					lines.push_back({angle, {b, j}});
				}
			}
		}
	

		sort(lines.begin(), lines.end());

		int maximum = 0;
		double previousB = 0;
		double previousAngle = 0;

		set<int> points;
		for (int i = 0; i < lines.size(); i++) {
			double angle = lines[i].first;
			double b = lines[i].second.first;
			int point = lines[i].second.second;

			if (previousAngle != angle || previousB != b) {
				points.clear();
			}

			previousB = b;
			previousAngle = angle;
			points.insert(point);
		
			maximum = MAX(maximum, points.size());
		}

		cout<<maximum<<endl;
	}

	return 0;
}