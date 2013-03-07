// UVa 11428
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
#define cube(x) ((x)*(x)*(x))

int main() {
	int N;
	while(scanf("%d", &N) > 0 && N > 0) {
		int a=-1, b=-1;

		for(int i=1; cube(i+1) - cube(i) <= N; i++) {
			for(int j=i+1; cube(j) - cube(i) <= N; j++) {
				if ((cube(j) - cube(i)) == N) {
					a = j; b = i; break;
				}
			}
			if (a != -1) break;
		}

		if (a != -1 && b != -1) 
			printf("%d %d\n", a, b);
		else
			puts("No solution");
	}
	return 0;
}