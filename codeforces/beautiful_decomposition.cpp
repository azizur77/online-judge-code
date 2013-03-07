#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))
#define EPS 1e-6

int memo[4000005];

int solve(int n) {
	if (n == 0) return 0;
	if (memo[n] != -1) return memo[n];

	int pow2 = -1;

	int copy = n;

	while(copy > 0) {
		pow2++;
		copy >>= 1;
	}

	if ((1 << pow2) == n) return 1;

	int f = pow2;
	int c = pow2+1;

	memo[n] = min(solve(1<<f) + solve(n-(1<<f)), solve(1 << c) + solve((1<<c)-n));
	return memo[n];
}

int parse(string s) {
	int ret = 0;

	for(int i=0; i < sz(s); i++)
		ret = (s[i] - '0') + 2*ret;
	return ret;
}

int main() {
	fill(memo, -1);
	string s;
	cin >> s;
	cout << solve(parse(s)) << endl;
	return 0;
}