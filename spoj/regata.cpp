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

Point start, finish;
int nVertices;
vector<pair<Point, Point>> obstacles;

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

vector<vector<pair<double, int>>> adj;
vector<Point> vertices;
vector<double> dist;

void addVertice(Point a){
	int u = adj.size();
	adj.push_back({});
	dist.push_back(1e9);

	for (int v = 0; v < u; v++) {
		Point b = vertices[v];
		int intersects = 0;
		for (pair<Point, Point> obstacle: obstacles) {
			if (a == obstacle.first || a == obstacle.second) {
				continue;
			}

			if (b == obstacle.first || b == obstacle.second) {
				continue;
			}

			if (doIntersect(a, b, obstacle.first, obstacle.second)) {
				intersects = 1;
				break;
			}	
		}

		if (intersects) {
			continue;
		}

		adj[u].push_back({distance(a, b), v});
		adj[v].push_back({distance(a, b), u});
	}

	vertices.push_back(a);
}

int main() {
	while (cin>>start.x>>start.y>>finish.x>>finish.y>>nVertices) {
		if (start.x == 0 && start.y == 0 && finish.x == 0 && finish.y == 0 && nVertices == 0) {
			break;
		}

		adj.clear();
		dist.clear();
		obstacles.clear();
		vertices.clear();

		for (int i = 0; i < nVertices; i++) {
			Point a, b; cin>>a.x>>a.y>>b.x>>b.y;
			obstacles.push_back({a, b});
		}

		addVertice(start);
		addVertice(finish);
		for (pair<Point, Point> obstacle: obstacles) {
			addVertice(obstacle.first);
			addVertice(obstacle.second);
		}
		
		priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
		q.push({0, 0});
		dist[0] = 0;

		while (!q.empty()) {
			pair<double, int> current = q.top(); q.pop();
			int u = current.second;
			double d = current.first;

			if (d == dist[u]) {
				for (pair<double, int> next: adj[u]) {
					int v = next.second;
					double w = next.first;

					if (d + w < dist[v]) {
						dist[v] = d + w;
						q.push({dist[v], v});
					}
				}
			}
		}

		cout<<fixed<<setprecision(2)<<dist[1]<<endl;
	}

    return 0;
}