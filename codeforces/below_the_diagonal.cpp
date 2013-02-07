#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()

int N, matrix[1005][1005];

struct move {
	int a, b, c;
	move(int x, int y, int z) : a(x), b(y), c(z) {}
};

bool inqueue[2005] = {false};

int main() {
	scanf("%d", &N);
	memset(matrix, 0, sizeof(matrix));
	int x, y;

	vector<move> swaps;
	queue<int> Q;

	for(int i=0; i < N-1; i++) {
		scanf("%d %d", &x, &y);
		matrix[x-1][y-1] = 1;

		if (x < y) {
			if (!inqueue[x-1]) Q.push(x-1);
			if (!inqueue[y-1]) Q.push(y-1);
		}
	}

	while(Q.size()) {
		int curr = Q.front();
		Q.pop();
		inqueue[curr] = false;

		// try swapping row
		if (curr != N-1) {
			int cnt = 0;

			for(int i=curr; i < N; i++)
				if (matrix[curr][i] == 1) cnt++;

			if (cnt == 0 && matrix[curr][curr] == 1)
				swaps.push_back(move(1, curr+1, curr+2));
			for(int i=0; i < N; i++)
				swap(matrix[curr][i], matrix[curr+1][i]);
		}
		// try swapping col
		if (curr != 0) {
			int cnt = 0;
			for(int i=curr; i < N; i++)
				if (matrix[curr][i] == 1) cnt++;
			
			if (cnt == 0 && matrix[curr][curr] == 1)
				swaps.push_back(move(2, curr, curr+1));
			for(int i=0; i < N; i++)
				swap(matrix[i][curr-1], matrix[i][curr+1]);
		}

		if(!inqueue[curr])
		for(int i=curr; i < N; i++)
			if (matrix[i][curr] == 1 || matrix[curr][i] == 1) {
				inqueue[curr] = true;
				Q.push(curr);
				break;
			}

		if (!inqueue[curr+1])
		for(int i=curr; i < N; i++)
			if (matrix[i][curr+1] == 1 || matrix[curr][i] == 1) {
				inqueue[curr+1] = true;
				Q.push(curr+1);
				break;
			}
	}

	printf("%d\n", swaps.size());
	for(int i=0; i < swaps.size(); i++)
		printf("%d %d %d\n", swaps[i].a, swaps[i].b, swaps[i].c);

	return 0;
}