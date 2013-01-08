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

int minmoves[1001], numbers[505], n, distances[505];

void search() {
	queue <ii> Q;
	Q.push(mp(0, 0));
	bool seen[1001] = {0};
	while(sz(Q)) {
		ii curr = Q.front();
		Q.pop();
		if (seen[curr.X]) continue;
		seen[curr.X] = 1;
		minmoves[curr.X] = curr.Y;
		for(int i=0; i < n; i++) {
			if (curr.X + numbers[i] <= 1000 && !seen[curr.X + numbers[i]])
				Q.push(mp(curr.X + numbers[i], curr.Y+1));
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		// for(int i=0; i <= 1000; i++) minmoves[i] = INF;
		for(int i=0; i < n; i++) scanf("%d", &distances[i]);
		for(int i=0; i < n; i++) scanf("%d", &numbers[i]);
		search();
		int refuels = 0;
		for(int i=0; i < n; i++) refuels += minmoves[2 * distances[i]];
		printf("%d\n", refuels);
	}
	return 0;
}