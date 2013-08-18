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

int main() {
	double sum = 0, m, R;
	cin >> m >> R;

	for(double i=0; i < m; i++)
		sum += R * (i * (i+1) + (m - i - 1) * (m-i));
	sum -= (m*m - m) * (2 - sqrt(2)) * R;
	sum += m * m * 2 * R;

	for(double i=0; i < m; i++)
		sum -= (max(0.0, i-1) + max(0.0, m-i-2)) * (2 - sqrt(2)) * R;

	printf("%.10lf\n", sum / m / m);
	return 0; 
}