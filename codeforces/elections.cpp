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
typedef vector<ii> mask;
#define MOD 1000000007

vector<mask> getMasks(string pattern) {
	vector<mask> results;

	for(int j = sz(pattern) - 1; j >= 0; j--) {
		mask curpat;
		bool flag = false;
		for(int k=0; k < j; k++) {
			int dig = pattern[k] - '0';
			curpat.push_back(ii(dig, dig));
		}
		if (pattern[j] == '0') {
			flag = true;
			continue;
		}
		int dig = pattern[j] - '1';
		curpat.push_back(ii(0, dig));
		for(int k = j+1; k < sz(pattern); k++)
			curpat.push_back(ii(0, 9));
		if (curpat[0].X == 0 && curpat[0].Y == 0) curpat.erase(curpat.begin());
		bool flag2 = true;
		// for(int i=0; i < sz(curpat); i++)
		// 	if (curpat[i].X != 0)
		// 		flag2 = false;
		// if (flag2) curpat[sz(curpat) - 1].X = 1;

		results.push_back(curpat);
	}
	mask curpat;
	for(int i=0; i < sz(pattern); i++) {
		int dig = pattern[i] - '0';
		curpat.push_back(ii(dig, dig));
	}
	results.push_back(curpat);
	return results;
} 

ll countways(mask &pat, int pos, int luckleft) {
	if (pos == sz(pat) && luckleft == 0) return 1LL;
	else if (pos == sz(pat)) return 0LL;
	ll digs = (ll) pat[pos].Y - pat[pos].X + 1;
	ll ldigs = 0LL;
	if (pat[pos].X <= 4 && pat[pos].Y >= 4) ldigs++;
	if (pat[pos].X <= 7 && pat[pos].Y >= 7) ldigs++;
	ll res = 0LL;
	if (luckleft > 0)
		res = ((ll) ldigs * countways(pat, pos+1, luckleft-1)) % MOD;
	res = (res + (((ll) (digs - ldigs) * countways(pat, pos+1, luckleft)) % MOD)) % MOD;
	return res;
}

ll nways[10];

ll count2(vi counts, int limit, int left) {
	int sum = accumulate(all(counts), 0);
	// printf("(dbg) %d %d %d\n", sum, limit, left);
	if (sum == 6) return 1LL;
	ll res = 0LL;
	for(int i=0; i < limit && left >= i; i++) {
		vi copy(counts);
		copy[i]++;
		res = (res + (((ll) nways[i] - counts[i]) * count2(copy, limit, left-i)) % MOD) % MOD;
	}
	return res;
}



int main() {
	// vector<mask> test = getMasks("1000");
	// for(int i=0; i < sz(test); i++) {
	// 	for(int j=0; j < sz(test[i]); j++)
	// 		printf("(%d, %d) ", test[i][j].X, test[i][j].Y);
	// 	printf("\n");
	// }
	string pattern;
	cin >> pattern;
	vector<mask> masks = getMasks(pattern);
	fill(nways, 0LL);
	for(int i=0; i < 10; i++) {
		for(int j=0; j < sz(masks); j++) {
			nways[i] = (nways[i] + countways(masks[j], 0, i)) % MOD;
		}
		// cout << nways[i] << endl;
	}
	nways[0]--;

	ll finalresult = 0LL;

	for(int i=1; i < 10; i++) {
		// if (nways[i] == 0) break;
		vi seed(i, 0);
		finalresult = (finalresult + (nways[i] * count2(seed, i, i-1)) % MOD) % MOD;
	}	
	cout << finalresult << endl;
	return 0;
}
