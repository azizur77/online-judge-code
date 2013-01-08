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
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		int n;
		cin >> n;
		vi height(n);
		vi width(n);
		REP(j, n) cin >> height[j];
		REP(j, n) cin >> width[j];
		vi lis(width);
		vi lds(width);
		for(int i=0; i < n; i++) {
			int maxel = 0;
			for(int j = i-1; j >= 0; j--) 
				if (height[j] < height[i]) 
					maxel = max(maxel, lis[j]);
			lis[i] += maxel;

			maxel = 0;
			for(int j = i-1; j >= 0; j--) 
				if (height[j] > height[i] && width[j] > 0) 
					maxel = max(maxel, lds[j]);
			lds[i] += maxel;
		}
		int inc = *max_element(all(lis)), dec = *max_element(all(lds));
		if (inc >= dec)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t+1, inc, dec);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t+1, dec, inc);
	}
	return 0;
}