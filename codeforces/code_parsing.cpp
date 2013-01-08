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

string input;

bool nochange = false;
int yxseed = 0, xyseed = 0;

void apply() {
	// Find yx
	nochange = false;
	for(int i=yxseed; i < sz(input) - 1; i++) {
		if (input[i] == 'y' && input[i+1] == 'x') {
			swap(input[i], input[i+1]);
			if (i > 0 && input[i-1] == 'y') yxseed--;
			return;
		}
		yxseed++;
	}
	// Find xy
	for(int i=xyseed; i < sz(input) -1; i++) {
		if (input[i] == 'x' && input[i+1] == 'y') {
			input.erase(i, 2); 
			if (i > 0 && input[i-1] == 'y' && input[i+1] == 'x') yxseed = i;
			else if (i > 0 && input[i-1] == 'x' && input[i+1] == 'y') xyseed = i;
			return;
		}
		xyseed++;
	}
	nochange = true;
}

int main() {
	cin >> input;
	while(!nochange) 
		apply();
	cout << input << endl;
	return 0;
}