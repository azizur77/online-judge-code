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


void task() {
	int n, arr[105];
	scanf("%d", &n);
	REP(i, n) scanf("%d", &arr[i]);

	int ginv = 0, linv = 0;

	for(int i=0; i < n; i++)
		for(int j=i+1; j < n; j++) {
				if (arr[i] > arr[j]) {
					ginv++;
					if (j == i+1)
						linv++;
				}
			}
	if (ginv == linv) printf("YES\n");
	else printf("NO\n");
}


int main() {
	int t;
	scanf("%d", &t);
	REP(i, t) task();
	return 0;
}