// 782 - Contour Painting
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

char grid[35][85];
int N, M, color[35][85], len[35];

bool color_grid(int i, int j, int c) {
	if (color[i][j] != 0) return false;
	color[i][j] = c;
	for(int di=-1; di <= 1; di++)
		for(int dj = -1; dj <= 1; dj++)
			if (abs(di) + abs(dj) == 1)
			if ((i+di) >= 0 && (i+di) < N && (j+dj) >= 0 && (j+dj) < M) {
				if (grid[i][j] == grid[i+di][j+dj])
					color_grid(i+di, j+dj, c);
				else if ((grid[i][j] == ' ' && grid[i+di][j+dj] == '*') ||
					(grid[i][j] == '*' && grid[i+di][j+dj] == ' '))
					color_grid(i+di, j+dj, c);
			}
	return true;
}
void paint_box(int i, int j, int c) {
	for(int di=-1; di <= 1; di++)
		for(int dj=-1; dj <= 1; dj++)
			if (abs(di) + abs(dj) == 1)
			if ((i+di) >= 0 && (i+di) < N && (j+dj) >= 0 && (j+dj) < M)
				if (color[i+di][j+dj] == c) {
					if (grid[i+di][j+dj] != '#' && grid[i+di][j+dj] != grid[i][j]) {
						grid[i+di][j+dj] = '#';
					}
				}
}

int main() {
	int T;
	scanf("%d", &T);
	getchar();
	for(int t=0; t < T; t++) {
		fill(grid, 0);
		int row = 0;
		M = 0;
		while(1) {
			fgets(grid[row], 84, stdin);
			len[row] = strlen(grid[row]) - 1;
			// printf("(dbg) %d %d\n", row, len[row]);
			M = max(len[row] + 1, M);
			if (grid[row][0] == '_') {
				N = row;
				break;
			}
			row++;
		}
		if (N < 2) return 0;
		for(int i=0; i <= N; i++)
			for(int j=0; j <= M; j++)
				if (grid[i][j] == 0 || grid[i][j] == '\n')
					grid[i][j] = ' ';
		for(int i=0; i <= N; i++) {
			grid[i][M] = '\n';
			grid[i][M+1] = 0;
		}
		fill(color, 0);
		int col = 1;
		for(int i=0; i < N; i++)
			for(int j=0; j < M; j++)
				if (grid[i][j] == '*' || grid[i][j] == ' ')
					if (color_grid(i, j, col))
						col++;

		// Find color of the star
		int target = -1;
		for(int i=0; i < N; i++)
			for(int j=0; j < M; j++)
				if (grid[i][j] == '*') {
					target = color[i][j];
					grid[i][j] = ' ';
					break;
				}

		// Paint the grid
		for(int i=0; i < N; i++)
			for(int j=0; j < M; j++)
				if (grid[i][j] != '#' && grid[i][j] != ' ')
					paint_box(i, j, target);

		// Remove trailing spaces
		for(int i=0; i <= N; i++) {
			int j = M-1;
			while(grid[i][j] == ' ' || grid[i][j] == '\n') j--;
			j++;
			grid[i][j++] = '\n';
			grid[i][j] = 0;
		}

		// Output
		for(int i=0; i <= N; i++)
			printf("%s", grid[i]);
		// for(int i=0; i < N; i++) {
		// 	for(int j=0; j < len[i]; j++)
		// 		printf("%d", color[i][j]);
		// 	printf("\n");
		// }
	}
	return 0;
}