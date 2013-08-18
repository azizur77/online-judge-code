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

int mem[1000005];

int solve(int k) {
	if (k < 0) return 0;
	if (k == 0) return 1;
	if (mem[k] != -1) return mem[k];

	mem[k] = 0;
	mem[k] = solve(k-4) | solve(k-7);

	return mem[k];
}

int main() {
	int n, flag = 0;
	cin >> n;
	fill(mem, -1);

	if (! solve(n)) {
		puts("-1");
		return 0;
	}


	while (n % 7 != 0) {
		printf("4");
		n -= 4;
	}
	for(int i=0; i < n; i += 7) printf("7");
	printf("\n");

	return 0;
}