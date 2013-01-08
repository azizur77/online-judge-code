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

double f[10005];
bool seen[100005], mark[100005];


inline bool equals(double a, double b) {
	return abs(a-b) <= EPS;
}

double round(double xx) {
	if (xx > floor(xx) + 0.5) return ceil(xx);
	return floor(xx);
}

void task() {
	fill(seen, 0);
	fill(mark, 0);
	int N;
	scanf("%d", &N);
	for(int i=0; i < N; i++) {
		scanf("%lf", &f[i]);
		seen[(int) f[i]] = true;
	}
	int maxel = *max_element(f, f+N);
	deque<int> apfinal, gpfinal;
	bool gpflag = false;
	// Check if first element is in GP / AP
	for(int i=1; i < N; i++) {
		double ratio = f[i] / f[0];
		double diff = f[i] - f[0];

		deque<int> apq, gpq;
		apq.push_back(f[0]);
		gpq.push_back(f[0]);

		int curr = f[i];
		while(curr <= maxel && seen[curr]) {
			apq.push_back(curr);
			// printf("%d added on iter %d\n", curr, i);
			curr += diff;
		}
		gpflag = false;
		if (sz(apq) >= N/2) {
			apfinal = apq;
			// printf("%d made final\n", sz(apfinal));
			for(int j=0; j < sz(apq); j++) mark[apq[j]] = 1;
			break;
		}

		double curg = f[i];
		while(1) {
			if (curg <= maxel && equals(round(curg), curg) && seen[(int) round(curg)]) {
				gpq.push_back(round(curg));
				curg *= ratio;
			}
			else break;
		}
		for(int i=0; i < sz(gpq); i++) mark[gpq[i]] = 1;
		gpfinal = gpq;
		gpflag = true;
	} 

	if (gpflag) {
		int start = 0;
		while(start < N && mark[(int) round(f[start])]) start++;
		int next = start+1;
		while(next < N && mark[(int) round(f[next])]) next++;


		int diff = f[next] - f[start];
		deque<int> apq;
		int curr = f[start];

		while(curr <= maxel && seen[curr]) {
			apq.push_back(curr);
			curr += diff;
		}
		apfinal = apq;
		for(int j=0; j < sz(apq); j++) mark[apq[j]] = 1;
	}

	else {
		int start = 0;
		while(start < N && mark[(int) round(f[start])]) start++;
		int next = start+1;
		while(next < N && mark[(int) round(f[next])]) next++;
		double ratio = f[next] / f[start];
		if (start == N) {
			start = 0;
			ratio = f[1] / f[0];
		}
		deque<int> gpq;
		double curg = f[start];
		while(1) {
			if (curg <= maxel && equals(round(curg), curg) && seen[(int) round(curg)]) {
				gpq.push_back(round(curg));
				curg *= ratio;
			}
			else break;
		}
		curg = f[start] / ratio;
		while(1) {
			if (curg <= maxel && equals(round(curg), curg) && seen[(int) round(curg)]) {
				gpq.push_front(round(curg));
				curg /= ratio;
			}
			else break;
		}
		for(int i=0; i < sz(gpq); i++) mark[gpq[i]] = 1;
		gpfinal = gpq;
	}

	if (sz(gpfinal) == 1) {
		if (gpfinal[0] == f[0]) {
			gpfinal.push_back(f[1]);
		}
		else {
			gpfinal.push_front(f[0]);
		}
	}

	else if (gpfinal.size() == 0) {
		gpfinal.push_front(f[1]);
		gpfinal.push_front(f[0]);
	}

	if (sz(apfinal) == 1) {
		if (apfinal[0] == f[0]) {
			apfinal.push_back(f[1]);
		}
		else {
			apfinal.push_front(f[0]);
		}
	}
if (sz(gpfinal) == 1) {
		if (gpfinal[0] == f[0]) {
			gpfinal.push_back(f[1]);
		}
		else {
			gpfinal.push_front(f[0]);
		}
	}

	else if (gpfinal.size() == 0) {
		gpfinal.push_front(f[1]);
		gpfinal.push_front(f[0]);
	}
	else if (apfinal.size() == 0) {
		apfinal.push_front(f[1]);
		apfinal.push_front(f[0]);
	}

	for(int i=0; i < sz(apfinal) - 1; i++) printf("%d ", apfinal[i]);
	printf("%d\n", apfinal[sz(apfinal) - 1]);
	for(int i=0; i < sz(gpfinal) - 1; i++) printf("%d ", gpfinal[i]);
	printf("%d\n", gpfinal[sz(gpfinal) - 1]);

}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) task();
}