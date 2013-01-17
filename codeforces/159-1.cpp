#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> sockets(n);
	for(int i=0; i < n; i++) cin >> sockets[i];
	sort(sockets.begin(), sockets.end());
	reverse(sockets.begin(), sockets.end());
	if (k >= m) {
		printf("0\n");
		return 0;
	}
	for(int i=0; i < n; i++) {
		k += sockets[i] - 1;
		if (k >= m) {
			printf("%d\n", i+1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}