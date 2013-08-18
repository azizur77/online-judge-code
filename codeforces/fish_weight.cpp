#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <map>
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
	int n, m, k, x;
	map<int, ii> M;
	cin >> n >> m >> k;

	for(int i=0; i < n; i++) {
		cin >> x;
		M[x].X++;
	}
	for(int i=0; i < m; i++) {
		cin >> x;
		M[x].Y++;
	}

	int flag = 0;

	map<int, ii>::reverse_iterator rit;
	int diff = 0;
	for(rit = M.rbegin(); rit != M.rend(); rit++) {
		ii curr = (*rit).Y;
		diff += curr.X - curr.Y;
		if (diff >= 0) {
			puts("YES");
			flag = 1;
			break;
		}
	}
	if (!flag) {
		puts("NO");
	}
	return 0;
}