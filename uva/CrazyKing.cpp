#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N;
char board[205][205];
bool blocked[205][205];

void check_blocks() {
	memset(blocked, 0, sizeof(blocked));

	for(int i=0; i < M; i++)
		for(int j=0; j < N; j++) 
			if (board[i][j] != 'A' && board[i][j] != 'B') {
				if (board[i][j] == 'Z') {
					blocked[i][j] = 1;
					continue;
				}
				for(int x=-2; x <= 2; x++)
					for(int y=-2; y <=2; y++)
						if (abs(y) + abs(x) == 3)
						if (i+x>=0 && i+x<M && j+y>=0 && j+y<N && board[i+x][j+y] == 'Z')
							blocked[i][j] = 1;
			}
}

struct item {
	int x, y, len;
	item(int a, int b, int c) : x(a), y(b), len(c) {}
};

void bfs() {
	queue<item> Q;
	item start(0,0,0);
	int tx, ty;
	for(int i=0; i < M; i++) for(int j=0; j < N; j++) if (board[i][j] == 'A') {
		start.x = i; start.y = j; 
	}
	for(int i=0; i < M; i++) for(int j=0; j < N; j++) if (board[i][j] == 'B') { tx = i; ty = j; }
	Q.push(start);
	bool seen[205][205] = {{false}};
	while(Q.size()) {
		item curr = Q.front();
		Q.pop();
		if (seen[curr.x][curr.y]) continue;
		seen[curr.x][curr.y] = 1;
		if (curr.x == tx && curr.y == ty) {
			printf("Minimal possible length of a trip is %d\n", curr.len);
			return;
		}
		for(int x=-1; x <= 1; x++)
		for(int y=-1; y <= 1; y++)
		if (abs(x) || abs(y)) 
		if (curr.x+x>=0 && curr.x+x<M && curr.y+y>=0 && curr.y+y<N && !blocked[curr.x+x][curr.y+y])
			Q.push(item(curr.x+x, curr.y+y, curr.len+1));
				
	}
	puts("King Peter, you can't go now!");
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		scanf("%d %d", &M, &N);
		for(int i=0; i < M; i++) scanf("%s", board[i]);
		check_blocks();
		bfs();
	}
	return 0;
}