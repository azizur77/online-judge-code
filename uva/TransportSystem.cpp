#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, double> edge;

int n;
double r;
vector<ii> points;

inline double euclid(int i, int j) {
	return sqrt(pow((double) points[i].first - points[j].first, 2.0) +
		pow((double) points[i].second - points[j].second, 2.0));
}

struct heap_item {
	int a, b;
	heap_item(int x, int y) : a(x), b(y) {}
	const bool operator<(heap_item const &rhs) const {
		return euclid(a, b) > euclid(rhs.a, rhs.b);
	}
};


void build_mst(int t) {
	vector<edge> edges[n];
	priority_queue<heap_item> heap;
	for(int i=1; i < n; i++) heap.push(heap_item(0, i));
	bool seen[1005] = {false};
	seen[0] = 1;

	while(heap.size() > 0) {
		heap_item curr = heap.top();
		heap.pop();
		if (seen[curr.b]) continue;
		seen[curr.b] = 1;

		edges[curr.a].push_back(edge(curr.b, euclid(curr.a, curr.b)));
		edges[curr.b].push_back(edge(curr.a, euclid(curr.a, curr.b)));

		for(int i=0; i < n; i++)
			if (!seen[i]) 
				heap.push(heap_item(curr.b, i));
	}
	vector<int> states(n, -1);
	vector< vector<int> > slist (n);
	double road=0.0, rail=0.0;
	int state_cnt = 1;
	// for(int i=0; i < n; i++) 
	// 	for(int st=0; st < n; st++) {
	// 		state_cnt = max(st+1, state_cnt);
	// 		bool flag = 1;
	// 		for(int j=0; j < slist[st].size(); j++) {
	// 			if (euclid(i, slist[st][j]) > r) {
	// 				flag = 0;
	// 				break;
	// 			}
	// 		}
	// 		if (flag) {
	// 			states[i] = st;
	// 			slist[st].push_back(i);
	// 			break;
	// 		}
	// 	}
	

	for(int i=0; i < n; i++)
		for(int j=0; j < edges[i].size(); j++)
			if (edges[i][j].first > i) {
				if (euclid(i, edges[i][j].first) > r) {
					rail += euclid(i, edges[i][j].first);
					state_cnt++;
				}
				else road += euclid(i, edges[i][j].first);
			}

	rail = ((rail - floor(rail)) >= 0.5) ? ceil(rail) : floor(rail);
	road = ((road - floor(road)) >= 0.5) ? ceil(road) : floor(road);
	printf("Case #%d: %d %d %d\n", t, state_cnt, (int) road, (int) rail);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		scanf("%d %lf", &n, &r);
		points.clear();

		for(int i=0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points.push_back(ii(x, y));
		}

		build_mst(t+1);
	}
	return 0;
}

