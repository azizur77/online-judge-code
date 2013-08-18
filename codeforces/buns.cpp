#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define INF (1<<30)
#define fill(c, v)	memset((c), (v), sizeof((c)))

int dough[11], max_buns[11], profit[11], num_types;
long long memo[1001][12];

long long solve (int dough_left, int j) {
	if (j == -1 || dough_left < 0) return 0LL;
	if (memo[dough_left][j] != -1) return memo[dough_left][j];

	long long &ret = memo[dough_left][j] = 0;

	for(int buns=0; buns <= max_buns[j] && dough_left >= buns * dough[j]; buns++) {
		ret = max(ret, buns * profit[j] + solve(dough_left - buns * dough[j], j-1));
	}

	return ret;
}

int main() {
	max_buns[0] = INF;
	fill(memo, -1);
	int dough_left;
	cin >> dough_left >> num_types >> dough[0] >> profit[0];
	int tugriks = 0;
	for(int i=0; i < num_types; i++) {
		int x, y;
		cin >> x >> y >> dough[i+1] >> profit[i+1];
		max_buns[i+1] = x / y;
	}

	cout << solve(dough_left, num_types) << endl;

	return 0;
}