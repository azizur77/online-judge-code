// Team Selection
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

bool table[23000][101];
int N, SUM, arr[105];

void fill_table() {
	for(int i=0; i <= SUM/2; i++)
		for(int j=0; j <= N; j++)
			table[i][j] = false;
	table[0][0] = true;
	for(int i=0; i <= SUM/2; i++)
		for(int j=1; j <= N; j++) {
			if (i - arr[j] >= 0)
				table[i][j] = table[i-arr[j]][j-1] || table[i][j-1];
		}
}

bool search(int target, int maxi, int aleft) {
	if (!table[target][maxi]) return false;
	if (target == 0 && maxi == 0) return true;
	bool res = false;
	for(int i=aleft; i <= maxi; i++) {
		res = res || search(target, i, aleft-1);
	} 
	return res;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int i=0; i < T; i++) {
		scanf("%d", &N);
		for(int j=1; j <= N; j++) scanf("%d", &arr[j]);
		sort(arr+1, arr+N+1);
		SUM = 0;
		for(int j=1; j <= N; j++) SUM += arr[j];	
		fill_table();
		bool flag = N % 2;
		int minsum;
		for(minsum=SUM/2; minsum >= 0; minsum--) {
			if (flag) {
				if (search(minsum, N, N/2+1) || search(minsum, N, N/2))
					break;
			}
			else if (search(minsum, N, N/2)) break;
		}
		printf("%d\n%d\n", minsum, SUM - minsum);
		if (i < N-1) printf("\n");
	}
	return 0;
}