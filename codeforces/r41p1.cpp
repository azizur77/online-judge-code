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
#define INF ((int)1e9)
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

int main() {
	int n, V, ratios[105], available[105];
	cin >> n >> V;
	REP(i, n) cin >> ratios[i];
	REP(i, n) cin >> available[i];
	int mini = -1;
	double minprod = 1e9;
	REP(i, n) {
		if (1.0 * available[i] / ratios[i] < minprod) {
			minprod = 1.0 * available[i] / ratios[i];
			mini = i;
		}
	}
	double sum = accumulate(ratios, ratios+n, 0.0);
	double soup = min((double) V, 1.0 * available[mini] / ratios[mini] * sum);
	cout << soup << endl;
	return 0;
}