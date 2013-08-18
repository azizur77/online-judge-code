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
	int n, m, x, y;
	cin >> n;
	vector<int> wires(n+1, 0);
	for(int i=1; i <= n; i++) cin >> wires[i];
	cin >> m;
	for(int i=0; i < m; i++) {
		cin >> x >> y;
		int l = y-1;
		int r = wires[x] - y;
		if (x > 1) wires[x-1] += l;
		if (x < n) wires[x+1] += r;
		wires[x] = 0; 
	}

	for(int i=1; i <= n; i++)
		cout << wires[i] << endl;
	return 0;
}