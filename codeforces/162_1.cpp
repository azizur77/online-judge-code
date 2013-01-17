#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a[5][5];
	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) {
				printf("%d\n", abs(i-2) + abs(j-2));
				return 0;
			}
		}
	return 0;
}