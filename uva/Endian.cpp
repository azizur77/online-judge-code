// 541 - little and big endians
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
	int sc;
	while(scanf("%d", &sc) > 0) {
		unsigned char d[4];
		unsigned x = sc;
		for(int i=0; i < 4; i++) {
			d[i] = x & 0xffffffff;
			x >>= 8;
		}
		unsigned out = (d[0] << 24) + (d[1] << 16) + (d[2] << 8) + d[3];
		printf("%d converts to %d\n", sc, out);
	}
	return 0;
}