// 10703 - Free Spots
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

int main() {
	int W = -1, N = -1, H = -1;
	cin >> W >> H >> N;
	while(!(W == 0 && N == 0 && H == 0)) {
		bool board[W+1][H+1];
		fill(board, 0);
		for(int i=0; i < N; i++) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			
			if (x2 < x1) swap(x1, x2);
			if (y2 < y1) swap(y1, y2);

			for(int i=x1; i <= x2; i++)
				for(int j=y1; j <= y2; j++)
					board[i][j] = true;
		}
		int empty = 0;
		for(int i = 1; i <= W; i++)
			for(int j = 1; j <= H; j++)
				if (!board[i][j])
					empty++;
		if (!empty) printf("There is no empty spots.\n");
		else if (empty == 1) printf("There is one empty spot.\n");
		else printf("There are %d empty spots.\n", empty);
		cin >> W >> H >> N;
	}
	return 0;
}