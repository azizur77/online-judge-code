// Arctic Network 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int parent[505];

void setup() {
	for(int i=0; i < 505; i++) parent[i] = i;
}

int find(int x) {
	if (parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

void link(int x, int y) {
	if (find(x) != find(y)) parent[find(x)] = find(y);
}

double euclid(int x1, int y1, int x2, int y2) {
	return sqrt(pow((double) x1 - x2, 2.0) + pow((double) y1-y2, 2.0));
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		setup();
		int S, P;
		scanf("%d %d", &S, &P);
		vector<ii> points;
		for(int i=0; i < P; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points.push_back(ii(x, y));
		}
		
		deque< pair<double, ii> > edges;
		for(int i=0; i < P; i++)
			for(int j=i+1; j < P; j++)
				edges.push_back(mp(euclid(points[i].X, points[i].Y, points[j].X, points[j].Y), mp(i, j)));

		sort(all(edges));
		double maxedge = 0.0;
		int numcomps = P;
		while(numcomps > S) {
			pair< double, ii > curr = edges.front();
			if (find(curr.Y.X) != find(curr.Y.Y)) {
				numcomps--;
				link(curr.Y.X, curr.Y.Y);
				maxedge = max(maxedge, curr.X);
			}
			edges.pop_front();
		}

		printf("%.2lf\n", maxedge);
	}
	return 0;
}