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

int largest(vector<string> matrix) {
	bool dp[26][26][26][26];
	fill(dp, 0);
	int N = sz(matrix);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			if (matrix[i][j] == '1')
				dp[i][j][i][j] = 1;

	int maxsize = 0;
	for(int a=0; a < N; a++)
		for(int b=0; b < N; b++)
			for(int c=a; c < N; c++)
				for(int d=b; d < N; d++) {
					// if (a == c && b == d) continue;
					dp[a][b][c][d] = dp[c][d][c][d];
					if (c-1 >= a)
						dp[a][b][c][d] = dp[a][b][c][d] && dp[a][b][c-1][d];
					if (d-1 >= b)
						dp[a][b][c][d] = dp[a][b][c][d] && dp[a][b][c][d-1];
					if (c-1 >= a && d-1 >=b)
						dp[a][b][c][d] = dp[a][b][c][d] && dp[a][b][c-1][d-1];
					if (dp[a][b][c][d])
						maxsize = max(maxsize, (c-a+1) * (d-b+1));
					// printf("%d %d %d %d: %d\n", a, b, c, d, dp[a][b][c][d]);
				}
	return maxsize;
}

int main() {
	int T;
	cin >> T;
	for(int t=0; t < T; t++) {
		vector<string> matrix;
		string buf;
		cin >> buf;
		matrix.push_back(buf);
		int limit = sz(buf) - 1;
		for(int j=0; j < limit; j++) {
			cin >> buf;
			matrix.push_back(buf);
		}
		cout << largest(matrix) << endl;
		if (t < T-1) cout << endl;
	}
	return 0;
}