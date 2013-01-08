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


int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int search(int x) {
	for(int i=2; i <= sqrt(x) + 1; i++) {
		if (x % i == 0) return i;
	}
	return x;
}

int main() {
	int t, n;
	scanf("%d", &t);
	REP(i, t) {
		scanf("%d", &n);
		int x, y;
		REP(j, n) {
			scanf("%d", &x);
			if (j == 0) 
				y = x;
			else 
				y = gcd(y, x);
		}
		if (y == 1) y = -1;
		else y = search(y);
		printf("%d\n", y);
	}
	return 0;
}