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

int N, Q, A[10005], x;

void binsearch(int x) {
	int found = -1;
	int mid, a = 0, b = N-1;
	while(a <= b) {
		mid = (a+b)/2;
		if (A[mid] == x) {
			found = mid;
			b = mid-1;
		}
		else if (A[mid] < x)
			a = mid+1;
		else
			b = mid-1;
	}
	if (found != -1) printf("%d found at %d\n", x, found+1);
	else printf("%d not found\n", x);
}

int main() {
	scanf("%d %d", &N, &Q);
	int caseno=0;
	while(!(N==0 && Q==0)) {
		printf("CASE# %d:\n", ++caseno);
		for(int i=0; i < N; i++) scanf("%d", &A[i]);
		sort(A, A+N);
		for(int i=0; i < Q; i++) {
			scanf("%d", &x);
			binsearch(x);
		}

		scanf("%d %d", &N, &Q);
	}
	return 0;
}