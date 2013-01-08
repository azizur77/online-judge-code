#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#define x first.first
#define y first.second
#define z second
using namespace std;
typedef pair<int, int> ii;
typedef pair< pair<int, int>, int> iii;

int main() {
	int M;
	char graph[200][200];
	while(scanf("%d", &M) > 0) {
		int max_dist = 0;
		for(int i=0; i < M; i++) scanf("%s\n", graph[i]);
		for(int i=0; i < M; i++) 
			for(int j=0; j < M; j++) 
				if (graph[i][j] == '1') {
					queue<iii> Q;
					Q.push(iii(ii(i, j), 0));
					bool seen[M][M];
					memset(seen, 0, sizeof(seen));
					while(Q.size()) {
						iii curr = Q.front();
						Q.pop();
						if (seen[curr.x][curr.y]) continue;
						seen[curr.x][curr.y] = 1;

						if (graph[curr.x][curr.y] == '3') {
							max_dist = max(curr.z, max_dist);
							break;
						}

						for(int di = -1; di <= 1; di++)	for(int dj=-1; dj <= 1; dj++)
							if ((abs(di) + abs(dj) == 1) && (curr.x+di) >= 0 && (curr.x+di) < M
							 && (curr.y+dj) < M && (curr.y+dj) >= 0) {
								Q.push(iii(ii(curr.x+di, curr.y+dj), curr.z+1));
							}
					}
				}
		printf("%d\n", max_dist); 
	}
	return 0;
}