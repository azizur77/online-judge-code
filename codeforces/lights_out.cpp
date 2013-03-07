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
	int input[3][3], lights[3][3];
	fill(input, 0);
	fill(lights, 0);
	for(int i=0; i < 3; i++) for(int j=0; j < 3; j++) cin >> input[i][j];
	for(int i=0; i < 3; i++)
		for(int j=0; j < 3; j++) {
			int k = input[i][j];
			lights[i][j] += k;
			if (i > 0) lights[i-1][j] += k;
			if (j < 2) lights[i][j+1] += k;
			if (i < 2) lights[i+1][j] += k;
			if (j > 0) lights[i][j-1] += k;
		}	
	for(int i=0; i < 3; i++) {
		for(int j=0; j < 3; j++) printf("%d", (lights[i][j] % 2) ^ 1);
		printf("\n");
	}
	return 0;
}