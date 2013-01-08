// The Tourist Guide

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

void task(int scen, int v, int e) {
	int weights [105][105];
	fill(weights, 0);

	REP(i, e) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		weights[x][y] = weights[y][x] = z;
	}
	int S, D, T;
	scanf("%d %d %d", &S, &D, &T);

	for(int k=1; k <= v; k++) 
		for(int i=1; i <= v; i++)
			for(int j=1; j <= v; j++)
				weights[i][j] = max(weights[i][j], min(weights[i][k], weights[k][j]));


	int best_path = weights[S][D] - 1; // To account for the tourist guide
	assert(best_path);
	int trips = T / best_path;
	if (T % best_path) trips++;
	printf("Scenario #%d\n", scen);
	printf("Minimum Number of Trips = %d\n\n", trips);
}

int main() {
	int v, e, i = 0;
	while(scanf("%d %d", &v, &e)) {
		if (v==0 && e ==0) break;
		task(++i, v, e);
	}
	return 0;
}