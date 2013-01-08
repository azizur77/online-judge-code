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

ii get(string pos) {
	return mp(pos[0] - 'a', pos[1] - '1');
}

int main() {
	bool board[8][8] = {0}, pieces[8][8] = {0};
	string rook1, rook2, wking, bking;
	cin >> rook1 >> rook2 >> wking >> bking;
	
	pieces[get(rook1).X][get(rook1).Y] = 1;
	pieces[get(rook2).X][get(rook2).Y] = 1;
	pieces[get(wking).X][get(wking).Y] = 1;
	pieces[get(bking).X][get(bking).Y] = 1;


	int row1 = get(rook1).X, col1 = get(rook1).Y;
	int idx = 1;
	while(row1 + idx < 8 && !pieces[row1 + idx][col1]) {
		idx++;
		board[row1 + idx][col1] = 1;
	}
	idx =1 ;
	while(col1 + idx < 8 && !pieces[row1][col1 + idx]) {
		idx++;
		board[row1][col1+ idx] = 1;
	}
	idx =1 ;
	while(col1 - idx >= 0 && !pieces[row1][col1 + idx]) {
		idx++;
		board[row1][col1- idx] = 1;
	}
	idx = 1;
	while(row1 - idx >= 0 && !pieces[row1][col1 + idx]) {
		idx++;
		board[row1-idx][col1] = 1;
	}
	row1 = get(rook2).X;
	col1 = get(rook2).Y;
	while(row1 + idx < 8 && !pieces[row1 + idx][col1]) {
		idx++;
		board[row1 + idx][col1] = 1;
	}
	idx =1 ;
	while(col1 + idx < 8 && !pieces[row1][col1 + idx]) {
		idx++;
		board[row1][col1+ idx] = 1;
	}
	idx =1 ;
	while(col1 - idx >= 0 && !pieces[row1][col1 + idx]) {
		idx++;
		board[row1][col1- idx] = 1;
	}
	idx = 1;
	while(row1 - idx >= 0 && !pieces[row1][col1 + idx]) {
		idx++;
		board[row1-idx][col1] = 1;
	}
	row1 = get(wking).X;
	col1 = get(wking).Y;
	int d[] = {1, -1, 0, 1, -1, 0, -1, 1, 0};
	int e[] = {1, 1, 1, 0, 0, -1, -1, -1, 0};
	for(int i=0; i < 8; i++)
		if (row1 + d[i] >= 0 && row1 + d[i] < 8 && col1 + e[i] >=0 && col1+e[i] < 8)
			board[row1+d[i]][col1+e[i]] = 1;
	bool checkmate = 1;
	row1 = get(bking).X;
	col1 = get(bking).Y;
	for(int i=0; i < 9; i++)
		if (row1 + d[i] >= 0 && row1 + d[i] < 8 && col1 + e[i] >= 0 && col1+e[i] < 8)
			if (!board[row1 + d[i]][col1 + e[i]]) {
				checkmate = false;
				break;
			}
	if (checkmate) cout << "CHECKMATE" << endl;
	else cout << "OTHER" << endl;
	return 0;
}