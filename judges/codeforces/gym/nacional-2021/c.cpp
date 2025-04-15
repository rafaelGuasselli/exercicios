#include<bits/stdc++.h>
//#define int long long
using namespace std;

struct Point{
	int x, y;

	bool operator ==(Point p){
		return x == p.x && y == p.y;
	}

	bool operator !=(Point p){
		return x != p.x && y != p.y;
	}

	bool operator<(const Point &p) const {
		return (x != p.x) ? (x < p.x) : (y < p.y);
	}
};


int mod(int i, int m) {
	return (((i%m)+m)%m);
}


int lattices[605][205][205] = {0};
int visited[605][205][205] = {0};
int parent[605][205][205][3] = {0};

map<char, pair<int, int>> direction = {{'E', {1, 0}}, {'W', {-1, 0}}, {'S', {0, -1}}, {'N', {0, 1}}, {'P', {0, 0}}}; 



vector<Point> vertices;
vector<Point> insidePoints;
set<Point> borderPoints;

void buildCloud() {
	char d; cin>>d;
	int v; cin>>v;

	pair<int, int> move = direction[d];
	insidePoints.clear();
	borderPoints.clear();
	vertices.clear();
	vertices.assign(v, {});

	int minY = 1e9;
	int maxY = 0;
	int minX = 1e9;
	int maxX = 0;

	for (int i = 0; i < v;  i++) {
		cin>>vertices[i].x>>vertices[i].y;
		vertices[i].x *= 2;
		vertices[i].y *= 2;
	
		minY = min(minY, vertices[i].y);
		maxY = max(maxY, vertices[i].y);
		minX = min(minX, vertices[i].x);
		maxX = max(maxX, vertices[i].x);
	}

	for (int i = 0; i < v; i++) {
		Point A = vertices[i];
		Point B = vertices[mod(i + 1, v)];
		if (A.x == B.x) {
			int start = min(A.y, B.y);
			int end = max(A.y, B.y);
			for (int y = start; y <= end; y++) {
				borderPoints.insert({A.x, y});
			}
		} else { 
			int start = min(A.x, B.x);
			int end = max(A.x, B.x);
			for (int x = start; x <= end; x++) {
				borderPoints.insert({x, A.y});
			}
		}
	}

	
	for (int y = minY; y <= maxY; y++) {
		for (int x = minX; x <= maxX; x++) {
			if (borderPoints.find({x, y}) != borderPoints.end()) {
				continue;
			}

			bool inside = false;
			for (int i = 0; i < v; i++) {
				Point A = vertices[i];
				Point B = vertices[mod(i + 1, v)];
				bool cond1 = (A.y > y) != (B.y > y);
				if (cond1) {
					double intersectX = A.x + (double)(B.x - A.x) * (y - A.y) / (B.y - A.y);
					if (x < intersectX) {
						inside = !inside;
					}
				}
			}

			if (inside) {
				insidePoints.push_back({x, y});
			}
		}
	}
	

	for (int z = 0; z <= 600; z++) {
		for (Point p: insidePoints) {
			int y = p.y + z * move.second;
			int x = p.x + z * move.first;

			if (y < 0 || x < 0 || x >= 205 || y >= 205) {
				continue;
			}
			
			lattices[z][y][x] = 1;
		}
	}

}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int xi, yi, xf, yf; cin>>xi>>yi>>xf>>yf;
	xi *= 2;  
	yi *= 2;  
	xf *= 2; 
	yf *= 2; 

	int n; cin>>n;

	for (int i = 0; i < n; i++) {
		buildCloud();
	}	

	queue<array<int, 3>> q;
	q.push({0, yi, xi});

	while (!q.empty()) {
		int z = q.front()[0];
		int y = q.front()[1];
		int x = q.front()[2];
		q.pop();

		if (x == xf && y == yf) {
			cout<<ceil((double)z/2.0)<<endl;
			break;
		}

		for (pair<char, pair<int, int>> d: direction) {
			int ny = y + d.second.second;
			int nx = x + d.second.first;
			int nny = y + 2*d.second.second;
			int nnx = x + 2*d.second.first;
			

			if (z >= 605 || ny < 0 || ny >= 205 || nx < 0 || nx >= 205) {
				continue;
			}

			if (visited[z+2][nny][nnx]) {
				continue;
			}

			if ((lattices[z][ny][nx] == 0 && lattices[z+1][ny][nx] == 0 && lattices[z+1][nny][nnx] == 0 && lattices[z+2][nny][nnx] == 0) || d.first == 'P') {
				visited[z+2][nny][nnx] = 1;
				parent[z+2][nny][nnx][0] = z;
				parent[z+2][nny][nnx][1] = y;
				parent[z+2][nny][nnx][2] = x; 
				
				q.push({z+2, nny, nnx});
			}
		} 
	}

	return 0;

	int final_z = -1;
	for (int z = 0; z < 605; z++) {
		if (visited[z][yf][xf]) {
			final_z = z;
			break;
		}
	}

	if (final_z != -1) {
		int cur_z = final_z, cur_y = yf, cur_x = xf;
		while (!(cur_z == 0 && cur_y == yi && cur_x == xi)) {
			lattices[cur_z][cur_y][cur_x] = 2;
			int pz = parent[cur_z][cur_y][cur_x][0];
			int py = parent[cur_z][cur_y][cur_x][1];
			int px = parent[cur_z][cur_y][cur_x][2];
			cur_z = pz;
			cur_y = py;
			cur_x = px;
			cout<<cur_z<<" "<<cur_y<<" "<<cur_x<<endl;
		}
		lattices[0][yi][xi] = 2;
	}

	int size = 40;
	for (int z = 0; z <= 10; z++) {
		cout<<z<<endl;
		for (int y = size; y >= 0; y--) {
			for (int x = 0; x <= size; x++) {
				if (x == xf && y == yf) {
					if (lattices[z][y][x]) {
						cout<<"b ";
					} else {
						cout<<"f ";
					}

					continue;
				} 
				
				cout<<lattices[z][y][x]<<" ";
				
			}
			cout<<endl;
		}

		cout<<endl;
	}


	cout<<"fim"<<endl;


	return 0;
}