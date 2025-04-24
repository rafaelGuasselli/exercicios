#include<bits/stdc++.h>
using namespace std;


struct Point{
	int x, y, id;
};

int n; 
int w, h; 
stack<int> s;
int used[100005] = {0};

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>w>>h;
	cin>>n;
	vector<Point> points, bottom, top, left, right;
	for (int i = 0; i < n; i++) {
		int xi, yi, xf, yf; cin>>xi>>yi>>xf>>yf;
		int addI = yi == 0 || xi == w || yi == h || xi == 0;
		int addF = yf == 0 || xf == w || yf == h || xf == 0;
		
		if (addI&&addF) {
			if (yi == 0) {
				bottom.push_back({xi, yi, i});
			} else if (xi == w) {
				right.push_back({xi, yi, i});
			} else if (yi == h) {
				top.push_back({xi, yi, i});
			} else if (xi == 0) {
				left.push_back({xi, yi, i});
			}

			if (yf == 0) {
				bottom.push_back({xf, yf, i});
			} else if (xf == w) {
				right.push_back({xf, yf, i});
			} else if (yf == h) {
				top.push_back({xf, yf, i});
			} else if (xf == 0) {
				left.push_back({xf, yf, i});
			}
		}
	}

	sort(bottom.begin(), bottom.end(), [](const Point&a, const Point&b) {
		return a.x<b.x;
	});

	sort(right.begin(), right.end(), [](const Point&a, const Point&b) {
		return a.y<b.y;
	});

	sort(top.begin(), top.end(), [](const Point&a, const Point&b) {
		return a.x>b.x;
	});

	sort(left.begin(), left.end(), [](const Point&a, const Point&b) {
		return a.y>b.y;
	});

	points.insert(points.end(), bottom.begin(), bottom.end());
	points.insert(points.end(), right.begin(), right.end());
	points.insert(points.end(), top.begin(), top.end());
	points.insert(points.end(), left.begin(), left.end());

	int possivel = 1;
	for (Point p: points) {
		if (!used[p.id]) {
			used[p.id] = 1;
			s.push(p.id);
		} else if (s.top() == p.id) {
			s.pop();
		} else {
			possivel = 0;
		}
	}

	cout<<(possivel?"Y":"N")<<endl;
	return 0;
}