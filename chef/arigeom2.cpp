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
#define EPS 1e-9
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

int F[10005], N, maxel = -INF, nomatch;
bool check[100005], match[100005];

inline bool is_int(double a) { return abs(round(a) - a) < EPS; }

deque<int> longest_ap(int start, bool maxcover=false) {
	deque<int> best, curr;
	set<int> seen;
	int bestcover = -1;
	for(int i=start+1; i < N; i++) {
		int diff = F[i] - F[start];
		int cover = 0;
		if (seen.find(diff) != seen.end()) continue;
		seen.insert(diff);
		curr.clear();
		curr.push_back(F[start]);
		int val = F[i];
		while(val <= maxel && check[val]) {
			curr.push_back(val);
			if (maxcover && !match[val]) cover++;
			val += diff;
		}
		val = F[start] - diff;
		while(val > 0 && check[val]) {
			curr.push_front(val);
			if (maxcover && !match[val]) cover++;
			val -= diff;
		}
		if (maxcover && cover > bestcover) {
			best = curr;
			bestcover = cover;	
			if (sz(best) > 0.5 * N) break;
		} 
		else if (sz(curr) > sz(best)) {
			best = curr;
			if (sz(best) > 0.5 * N) break;
		}

	}
	if (sz(best) < 2 && start == N-1) {
		best.clear();
		best.push_front(F[start]);
		best.push_front(F[0]);
	}
	return best;
}

deque<int> longest_gp(int start, bool maxcover=false) {
	deque<int> best, curr;
	set<double> seen;
	int bestcover = -1;
	for(int i=start+1; i < N; i++) {
		double ratio = 1.0 * F[i] / F[start];
		if (seen.find(ratio) != seen.end()) continue;
		seen.insert(ratio);
		int cover = 0;
		curr.clear();
		curr.push_back(F[start]);
		double val = F[i];
		while(val <= maxel && is_int(val) && check[(int) round(val)]) {
			curr.push_back(round(val));
			if (maxcover && !match[(int)round(val)]) cover++;
			val *= ratio;
		}
		val = F[start] / ratio;
		while(round(val) > 0 && is_int(val) && check[(int) round(val)]) {
			curr.push_front(round(val));
			if (maxcover && !match[(int)round(val)]) cover++;
			val /= ratio;
		}
		if (maxcover && cover > bestcover) {
			best = curr;
			bestcover = cover;	
			if (sz(best) > 0.5 * N) break;
		} 
		else if (sz(curr) > sz(best)) {
			best = curr;
			if (sz(best) > 0.5 * N) break;
		}
	}
	if (sz(best) < 2 && start == N-1) {
		best.clear();
		best.push_front(F[start]);
		best.push_front(F[0]);
	}
	return best;
}

bool check_union(deque<int> &first, deque<int> &second) {
	set<int> checker;
	checker.insert(all(first));
	checker.insert(all(second));
	for(int i=0; i < N; i++)
		if (checker.find(F[i]) == checker.end()) {
			nomatch = i;
			break;
		}
	// printf("(dbg) %d\n", sz(checker));
	return sz(checker) == N;
}

void matchup(deque <int> & A) {
	for(int i=0; i < sz(A); i++) {
		match[A[i]] = 1;
	}
}

void display(deque<int> &ap, deque<int> &gp) {
	for(int i=0; i < sz(ap) - 1; i++) printf("%d ", ap[i]);
	printf("%d\n", ap[sz(ap) - 1]);
	for(int j=0; j < sz(gp) - 1; j++) printf("%d ", gp[j]);
	printf("%d\n", gp[sz(gp) - 1]);
}

void task() {
	scanf("%d", &N);
	fill(check, 0);
	maxel = -INF;
	REP(i, N) {
		scanf("%d", &F[i]);
		check[F[i]] = 1;
		maxel = max(maxel, F[i]);
	}
	deque<int> apfromfirst = longest_ap(0);
	deque<int> gpfromfirst = longest_gp(0);
	if (check_union(apfromfirst, gpfromfirst)) {
		display(apfromfirst, gpfromfirst);
		return;
	}
	deque<int> apfromnomatch = longest_ap(nomatch);
	deque<int> gpfromnomatch = longest_gp(nomatch);
	
	fill(match, 0);
	matchup(apfromnomatch);
	matchup(gpfromnomatch);
	deque<int> apfromfirst1 = longest_ap(0, true);
	deque<int> gpfromfirst1 = longest_gp(0, true);
	if (check_union(apfromfirst1, gpfromnomatch)) {
		display(apfromfirst1, gpfromnomatch);
	}
	else if (check_union(gpfromfirst1, apfromnomatch)) {
		display(apfromnomatch, gpfromfirst1);
	}
	else {
		fill(match, 0);
		matchup(apfromfirst);
		matchup(gpfromfirst);
		check_union(apfromfirst, gpfromfirst);
		apfromnomatch = longest_ap(nomatch, true);
		gpfromnomatch = longest_gp(nomatch, true);
		if (check_union(apfromfirst, gpfromnomatch)) {
			display(apfromfirst, gpfromnomatch);
		}
		else if (check_union(gpfromfirst, apfromnomatch)) {
			display(apfromnomatch, gpfromfirst);
		}
		else {
			assert(0);
		}
	}
}


int main() {
	int T;
	scanf("%d", &T);
	while(T--) task();
}