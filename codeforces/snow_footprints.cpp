#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <string>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int main() {
	int n, rf=-1, rl=-1, lf=-1, ll=-1, rseen=0, lseen=0;
	string s;
	cin >> n;
	cin >> s;

	for(int i=0; i < n; i++) {
		if (s[i] == 'R') {
			if (!rseen) rf = rl = i;
			else rl = i;
			rseen = 1;
		} else if (s[i] == 'L') {
			if (!lseen) lf = ll = i;
			else ll = i;
			lseen = 1;
		}
	}

	if (rseen && lseen) {
		cout << rf+1 << " " << rl+1 << endl;
	} else if (rseen) {
		cout << rf+1 << " " << rl+2 << endl;
	} else if (lseen) {
		cout << ll+1 << " " << lf << endl;
	}

	return 0;
}