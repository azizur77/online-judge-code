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

int main() {
	int n;
	cin >> n;
	if (n == 2) { puts("-1"); return 0; }
	else if (n == 1) { puts("1"); return 0; }

	vector<int> perm(n+1, 0);

	perm[1] = 2;
	int pos = 2, store = n;

	while(perm[pos] == 0) {
		perm[pos] = store;
		pos = store;
		store = n - pos + 1;
	}

	for(int i=1; i < n; i++) cout << perm[i] << " ";
	cout << perm[n] << endl;
	return 0;
}