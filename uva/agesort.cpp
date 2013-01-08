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
	int T, x;
	scanf("%d", &T);
	while(T != 0) {
		int count[101] = {0};
		for(int i=0; i < T; i++) {
			scanf("%d", &x);
			count[x]++;
		}
		for(int i=0; i <= 100; i++) {
			for(int j=0; j < count[i]; j++) {
				T--;
				if (T == 0) printf("%d\n", i);
				else printf("%d ", i);
			}
		}
		scanf("%d", &T);
	}
	return 0;
}