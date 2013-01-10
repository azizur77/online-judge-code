// UVa 423
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, weights[105][105];

struct node {
	int to, finish;
	node(int b, int c) : to(b), finish(c) {}
	const bool operator<(node const &rhs) const {
		return finish > rhs.finish;
	}
};


int main() {
	scanf("%d", &N);
	char a;
	
	memset(weights, 0, sizeof(weights));

	for(int i=1; i < N; i++) {
		a = getchar();
		int j = 0;
		while (a == '\n') a = getchar();
		while (a != '\n') {
			while (a != ' ' && a != '\n') {
				if (a == 'x') {
					weights[i][j] = -1;
					a = getchar();
				 	break;
				}
				weights[i][j] = weights[i][j] * 10 + (a - '0');
				a = getchar();
			}
			weights[j][i] = weights[i][j];
			j++;
			if (a == '\n') break;
			a = getchar();
		}
			
	}
	// for(int i=0; i < N; i++) { for(int j=0; j < N; j++) printf("%4d ", weights[i][j]); printf("\n"); };
	priority_queue<node> heap;
	bool seen[105] = {false};
	seen[0] = 1;
	for(int i=0; i < N; i++) 
		if (weights[0][i] != -1)
			heap.push(node(i, weights[0][i]));

	int last = 0;
	while(heap.size() > 0) {
		node curr = heap.top();
		heap.pop();
		if (seen[curr.to]) continue;
		seen[curr.to] = 1;
		last = curr.finish;
		for(int i=0; i < N; i++)
			if (weights[curr.to][i] != -1 && !seen[i])
				heap.push(node(i, curr.finish + weights[curr.to][i]));
	}

	printf("%d\n", last);
	return 0;
}