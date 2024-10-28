#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Point { 
    int x; 
    int y; 

	bool operator == (Point b) {
		return x == b.x && y == b.y;
	}
}; 

bool onSegment(Point p, Point q, Point r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
int orientation(Point p, Point q, Point r)  {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
} 
  
bool doIntersect(Point p1, Point q1, Point p2, Point q2)  {
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false; 
} 

double distance(Point a, Point b){
	return sqrt((double)pow((double)(a.x-b.x), 2)+(double)pow((double)(a.y-b.y), 2));
}





int parent[1005];
vector<pair<Point, Point>> vertices;
int find(int u) {
	if (parent[u] == u) {
		return u;
	}

	parent[u] = find(parent[u]);
	return parent[u];
}

void join(int u, int v) {
	u = find(u);
	v = find(v);
	parent[v] = u;
}

int main() {
	int t; cin>>t;

	while (t--)	 {
		int nSticks, nQueries; cin>>nSticks>>nQueries;
		for (int i = 0; i < nSticks; i++) {
			parent[i] = i;
		}
		vertices.clear();
		for (int i = 0; i < nSticks; i++) {
			Point a, b; cin>>a.x>>a.y>>b.x>>b.y;

			for (int j = 0; j < vertices.size(); j++) {
				pair<Point, Point> anterior = vertices[j];
				if (doIntersect(a, b, anterior.first, anterior.second)) {
					join(i, j);
				}
			}

			vertices.push_back({a, b});
		}

		for (int i = 0; i < nQueries; i++) {
			int x, y; cin>>x>>y; x--; y--;
			if (find(x) == find(y)) {
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}
		}
	}

    return 0;
}