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
	int n, k;
	cin >> n >> k;

	if (k >= ((n * (n - 1)) / 2)) {
		puts("no solution");
	} else {
		int a=-INF, b=-INF, delta=0, ydelta;

		if (n < 10)
			ydelta = n * (n+1) / 2 + 1;
		else {
			int half = n / 2;
			ydelta = half * (half-1) / 2 + 1;
		}
		
		for(int i=0; i < n; i++) {
			cout << a << " " << b << endl;
			if (i % 2) {
				delta++;
				a += delta;
			}
			b += ydelta;
			assert(abs(a) <= INF && abs(b) <= INF);
		}
	}

}