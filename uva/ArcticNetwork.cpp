// 10369 - Arctic Network
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

struct edge {
	int x1, y1, x2, y2;
	edge(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}
	const double dist() const {
		return (double) sqrt(pow((double) x1 - x2, 2.0) + pow((double) y1 - y2, 2.0));
	}
	const bool operator<(const edge &rhs) const {
		if (dist() != rhs.dist()) return dist() > rhs.dist();
		if (x1 != rhs.x1) return x1 > rhs.x1;
		if (x2 != rhs.x2) return x2 > rhs.x2;
		if (y1 != rhs.y1) return y1 > rhs.y1;
		return y2 > rhs.y2;
	}
};

double find_spanning_tree(vector<ii> &points, int S) {
	set<ii> seen;
	priority_queue<edge> heap;
	set<edge> tree;
	heap.push(edge(points[0].X, points[0].Y, points[0].X, points[0].Y));

	while(!heap.empty()) {
		edge curr = heap.top();
		heap.pop();
		if (seen.find(mp(curr.x2, curr.y2)) != seen.end()) continue;
		seen.insert(mp(curr.x2, curr.y2));
		tree.insert(curr);
		for(int i=0; i < points.size(); i++)
			heap.push(edge(curr.x2, curr.y2, points[i].X, points[i].Y));
	}

	set<ii> satellite;
	while(S > 0) {
		edge curr = *tree.begin();
		if(satellite.find(mp(curr.x1, curr.y1)) == satellite.end()) {
			satellite.insert(mp(curr.x1, curr.y1));
			S--;
		}
		if(satellite.find(mp(curr.x2, curr.y2)) == satellite.end()) {
			satellite.insert(mp(curr.x2, curr.y2));
			S--;
		}
		if (S < 0) break;
		tree.erase(curr);
	}
	return (*tree.begin()).dist();
}

int main() { 
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		int S, P;
		scanf("%d %d", &S, &P);
		vector<ii> points;
		for(int i=0; i < P; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points.push_back(ii(x, y));
		}
		double ans = find_spanning_tree(points, S);
		printf("%.2lf\n", ans);
	}
	return 0;
}