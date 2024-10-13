#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Point{
	ll x, y, z, w;
};

vector<Point> points;

ll x = 0;
ll y = 0;
ll z = 0;

ll dist(Point a, Point b){
	return pow(a.x-b.x, 2) + pow(a.y-b.y, 2) + pow(a.z-b.z, 2);
}

ll calc(Point main) {
	ll total = 0;
	for (Point p: points) {
		total += p.w * dist(main, p);
	}

	return total;
}

int main() {
	int n; cin>>n;
	
	ll leftX = 1e9;
	ll rightX = 0;

	ll leftY = 1e9;
	ll rightY = 0;

	ll leftZ = 1e9;
	ll rightZ = 0;

	points.assign(n, {});
	for (int i = 0; i < n; i++) {
		cin>>points[i].x>>points[i].y>>points[i].z>>points[i].w;
		leftX = min(leftX, points[i].x);
		rightX = max(rightX, points[i].x);
		leftY = min(leftY, points[i].y);
		rightY = max(rightY, points[i].y);
		leftZ = min(leftZ, points[i].z);
		rightZ = max(rightZ, points[i].z);
	}

	while (leftX <= rightX) {
		ll mid1 = leftX + (rightX-leftX)/3;
		ll mid2 = rightX - (rightX-leftX)/3;
		
		ll val1 = calc({mid1, y, z});
		ll val2 = calc({mid2, y, z});
		
		if (val1 == val2) {
			leftX = mid1+1;
			rightX = mid2-1;
			x = mid1;
		} else if (val1 < val2) {
			rightX = mid2-1;
			x = mid1;
		} else {
			leftX = mid1+1;
			x = mid2;
		}
	}

	while (leftY <= rightY) {
		ll mid1 = leftY + (rightY-leftY)/3;
		ll mid2 = rightY - (rightY-leftY)/3;
		
		ll val1 = calc({x, mid1, z});
		ll val2 = calc({x, mid2, z});
		
		if (val1 == val2) {
			leftY = mid1+1;
			rightY = mid2-1;
			y = mid1;
		} else if (val1 < val2) {
			rightY = mid2-1;
			y = mid1;
		} else {
			leftY = mid1+1;
			y = mid2;
		}
	}

	while (leftZ <= rightZ) {
		ll mid1 = leftZ + (rightZ-leftZ)/3;
		ll mid2 = rightZ - (rightZ-leftZ)/3;
		
		ll val1 = calc({x, y, mid1});
		ll val2 = calc({x, y, mid2});
		
		if (val1 == val2) {
			leftZ = mid1+1;
			rightZ = mid2-1;
			z = mid1;
		} else if (val1 < val2) {
			rightZ = mid2-1;
			z = mid1;
		} else {
			leftZ = mid1+1;
			z = mid2;
		}
	}

	cout<<x<<" "<<y<<" "<<z<<endl;
	return 0;
}