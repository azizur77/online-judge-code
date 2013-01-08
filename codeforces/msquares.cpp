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
	int s[3][3];
	REP(i, 3) REP(j, 3) cin >> s[i][j];
	for(int i=1; i <= 100000; i++) {
		int sum = i + s[0][1] + s[0][2];
		s[0][0] = i;
		s[1][1] = sum - s[1][0] - s[1][2];
		s[2][2] = sum - s[2][1] - s[2][0];
		int col1 = s[0][0] + s[1][0] + s[2][0];
		int col2 = s[0][1] + s[1][1] + s[2][1];
		int col3 = s[0][2] + s[1][2] + s[2][2];
		int diag1 = s[0][0] + s[1][1] + s[2][2];
		int diag2 = s[0][2] + s[1][1] + s[2][0];
		if (s[1][1] < 0 || s[2][2] < 0 || s[1][1] > 100000 || s[2][2] > 100000 || col1 != sum
			|| col2 != sum || col3 != sum || diag1 != sum || diag2 != sum) continue;
		break;
	}
	REP(i, 3) {
		printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
	}
	return 0;
}