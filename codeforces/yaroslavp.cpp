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
	int n, x;
	cin >> n;
	vi arr(1001, 0);
	for(int i=0; i < n; i++) {
		cin >> x;
		arr[x]++;
	}
	int req = 0;
	for(int i=0; i < 1001; i++) {
		if (arr[i] > 1) 
			req = max(req, 2*arr[i] - 1);
	}
	if (req <= n) puts("YES");
	else puts("NO");
	return 0;
}