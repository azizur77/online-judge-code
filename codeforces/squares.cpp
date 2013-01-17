#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k, arr[55];
	scanf("%d %d", &n, &k);
	arr[0] = 0;
	for(int i=1; i <= n; i++) scanf("%d", &arr[i]);

	if (k > n) {
		puts("-1");
		return 0;
	}

	sort(arr, arr+n+1);

	int a = arr[n-k], b = arr[n-k+1];
	bool flag = true;
	if (a >= b) {
		puts("-1");
		return 0;
	}
	if (k == n) printf("0 0\n");
	else printf("%d %d\n", a+1, a+1);
	return 0;
}