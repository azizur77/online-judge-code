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
#define MAXN 100010

int nextindex[MAXN], C4[MAXN], C7[MAXN];

ll ipow(int a, int x) {
	return (ll) pow((ll) a, x);
}

void task() {
	fill(C4, 0);
	fill(C7, 0);
	fill(nextindex, -1);
	int n;
	scanf("%d", &n);
	FOR(i, 1, n+1) {
		int x, y;
		scanf("%d", &x);
		y = x;
		while (y > 0) {
			if (y % 10 == 7) C7[i]++;
			else if (y % 10 == 4) C4[i]++;
			y /= 10;
		}
	}
	int i=0;
	ll nways = 0;
	while (i < n+1) {
		int j = i+1;
		while (j < n+1 && !(C4[j] > C4[i] || C7[j] > C7[i])) {
			j++;
		}
		if (j != n+1)
			FOR(k, i, j) 
				nextindex[k] = j;
		i = j; 
	}

	for(int i=1; i < n+1; i++) {
		int j = i+1;
		while (j < n+1) {
			ll pg = ipow(C4[j] - C4[i-1], C7[j] - C7[i-1]);
			if ( pg > n) break;
			if (C4[j] - C4[i-1] != 2 && C7[j] - C7[i-1] != 2) {
				if (pg <= j-i+1) {
					nways++;
				}
			}
			int k = nextindex[j];
			if (k == -1) {
				nways += (ll) max(0, n - j - 1);
				break;
			}
			else {
				nways += (ll) k - j - 1;
				j = k;
			}
		}
	}
	printf("%lld\n", nways);
}

int main() {
	int t;
	scanf("%d", &t);
	REP(i, t) task();
	return 0;	
}