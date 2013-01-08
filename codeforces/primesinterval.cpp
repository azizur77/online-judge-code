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

bool P[1000001];
int pi[1000001];

void sieve() {
	fill(P, true);
	P[0] = P[1] = false;
	REP(i, 1000001) 
		if (P[i]) 
			for(int step = 2*i; step < 1000001; step+=i) 
				P[step] = false;
	fill(pi, 0);
	FOR(i, 1, 1000001) 
		pi[i] = pi[i-1] + P[i];
}
int a, b, k;

bool check(int l) {
	for(int x=a; x <= b-l+1; x++)
		if (pi[x+l-1] - pi[x-1] < k)
			return false;
	return true;
}


int main() {
	sieve();
	cin >> a >> b >> k;
	int lo = 1, hi = b-a+1, curr = -1;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			curr = mid;
			hi = mid-1;
		}
		else {
			lo = mid+1;
		}
	}
	cout << curr << endl;

	return 0;
}