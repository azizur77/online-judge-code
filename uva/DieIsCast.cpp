// 657 - A die is cast
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

int H, W, color[55][55], color2[55][55];
char grid[55][55];

bool connect(int i, int j, int c) {
	if (color[i][j] != -1) return false;
	color[i][j] = c;
	for(int di=-1; di <= 1; di++)
		for(int dj=-1; dj <= 1; dj++)
			if (abs(di) + abs(dj) == 1)
			if ((i+di) >= 0 && (j+dj) >= 0 && (i+di) < H && (j+dj) < W)
				if (grid[i+di][j+dj] == '*' || grid[i+di][j+dj] == 'X')
					connect(i+di, j+dj, c);
	return true;
}

bool connect2(int i, int j, int c) {
	if (color2[i][j] != -1) return false;
	color2[i][j] = c;
	for(int di=-1; di <= 1; di++)
		for(int dj=-1; dj <= 1; dj++)
			if ((abs(di) + abs(dj) == 1) && (i+di) >= 0 && (j+dj) >= 0
			&& (i+di) < H && (j+dj) < W) 
				if (grid[i+di][j+dj] == 'X')
					connect2(i+di, j+dj, c);
	return true;
}

int main() {
	scanf("%d %d", &W, &H);
	int thr = 1;
	while(H > 0 && W > 0) {
		fill(grid, '.');
		for(int i=0; i < H; i++) scanf("%s", grid[i]);
		fill(color, -1);
		int c = 0;

		for(int i=0; i < H; i++)
			for(int j=0; j < W; j++)
				if (grid[i][j] == '*' || grid[i][j] == 'X')
					if (connect(i, j, c))
						c++;
		vi answers;
		for(int q=0; q < c; q++) {
			int ctr = 0;
			fill(color2, -1);
			for(int i=0; i < H; i++)
				for(int j=0; j < W; j++)
					if (grid[i][j] == 'X' && color[i][j] == q) 
						if (connect2(i, j, ctr))
							ctr++;
			answers.push_back(ctr);
		}
		sort(all(answers));
		printf("Throw %d\n", thr++);
		for(int i=0; i < sz(answers) - 1; i++) printf("%d ", answers[i]);
		printf("%d\n", answers[sz(answers) - 1]);
		printf("\n");
		scanf("%d %d", &W, &H);
	}
	return 0;
}