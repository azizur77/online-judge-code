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

int memo[22505][51], sum=0, N, arr[105];
bool can_use[101];

int search(int val, int depth) {
	if (memo[val][depth] != -1) return memo[val][depth];
	if (val == 0 && depth == 0) return 1;
	memo[val][depth] = 0;

	if (depth > 0)
	for(int i=0; i < N && arr[i] <= val; i++) 
		if (can_use[i]) {
			can_use[i] = false;
			memo[val][depth] |= search(val - arr[i], depth-1);
			can_use[i] = true;
			if (memo[val][depth] == 1) break;
		}
	return memo[val][depth];
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		if (t > 0) printf("\n");
		fill(memo, -1);
		scanf("%d", &N);
		for(int i=0; i < N; i++) scanf("%d", &arr[i]);
		sort(arr, arr+N);
		int size = N/2;
		sum = 0;
		for(int i=0; i < N; i++) sum += arr[i];
		for(int i=sum/2; i >= 0; i--) {	
			fill(can_use, true);
			search(i, size);
		}

		int best, mindiff = (1<<30);
		for(int i=sum/2; i >=0; i--) 
			if (memo[i][size] == 1 && abs(sum - 2*i) < mindiff) {
				mindiff = abs(sum - 2*i);
				best = i;
			}
		int a[] = {best, sum-best};
		sort(a, a+2);
		printf("%d %d\n", a[0], a[1]);
	}
}
