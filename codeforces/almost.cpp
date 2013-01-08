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
#include <map>
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
#define min(x, y) (((x) < (y)) ? (x) : (y))
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int A[4005], n, longest = 0, counts[4005] = {0};
bool isfirst[4005] = {0};
map< int, deque<int> > positions;

void check(int i, int j) {
	if (2 * (min(counts[i], counts[j])) + 1 > longest) {
		int len = 2;
		int l=0, r=0, pos = j;
		if (!(isfirst[i] || isfirst[j])) return;
		while(pos < n) {
			while(l < sz(positions[A[i]]) && positions[A[i]][l] <= pos) l++;
			if (l >= sz(positions[A[i]])) break;
			pos = positions[A[i]][l];
			len++;
			while(r < sz(positions[A[j]]) && positions[A[j]][r] <= pos) r++;
			if (r >= sz(positions[A[j]])) break;
			len++;
			pos = positions[A[j]][r];
		}
		longest = max(len, longest);
	}
}


int main() {
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	REP(i, n) cin >> A[i];
	REP(i, n) REP(j, n) if (A[i] == A[j]) counts[i]++;
	REP(i, n) {
		if (positions.find(A[i]) == positions.end())
			isfirst[i] = 1;
		positions[A[i]].push_back(i);
	}
	// for(map<int, deque<int> >::iterator it = positions.begin(); it != positions.end(); it++) {
	// 	printf("%d: ", (*it).X);
	// 	for(int i=0; i < sz((*it).Y); i++) printf("%d ", (*it).Y[i]);
	// 	printf("\n");
	// }
	REP(i, n) for(int j=i+1; j < n; j++) check(i, j);
	cout << longest << endl;
	return 0;
}