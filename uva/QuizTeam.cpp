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
#include <bitset>
#include <map>
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

double dist[16][16];
int N;
double memo[65536];

int toint(bitset<16> mask) {
	int k = 0;
	for(int i=0; i < 16; i++) {
		k = (k<<1) + mask[i];
	}
	return k;
}

double solve(bitset<16> chosen) {
	if (chosen.count() == N) return 0.0;
	if (memo[(toint(chosen))] > 0) return memo[toint(chosen)];
	double mins = 1e9;
	for(int i=0; i < N; i++)
		for(int j=i+1; j < N; j++)
			if (!chosen[i] && !chosen[j]) {
				chosen[i] = chosen[j] = 1;
				mins = min(mins, dist[i][j] + solve(chosen));
				chosen[i] = chosen[j] = 0;
			}
	return memo[toint(chosen)] = mins;
}

int main() {
	int k, cno = 0;
	ii coords[16];
	scanf("%d", &k);
	while(k > 0) {
		N = 2 * k;
		char temp[50];
		REP(i, 65536) memo[i] = -1.0;
		for(int i=0; i < N; i++) {
			int x, y;
			scanf("%s %d %d", temp, &x, &y);
			coords[i] = ii(x, y);
		}
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				dist[i][j] = sqrt(pow((double) coords[i].X - coords[j].X, 2.0) +
					pow((double) coords[j].Y - coords[i].Y, 2.0));
		bitset<16> chosen;
		double ans = solve(chosen);
		printf("Case %d: %.2lf\n", ++cno, ans);
		scanf("%d", &k);
	}
	return 0;
}