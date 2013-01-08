#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define sz(x) ((int) (x).size())
using namespace std;
typedef pair<int, int> ii;

vector<int> readints() {
	vector<int> res;
	char c = '\n';
	int t = 0;
	while (c == '\n') c = getchar(); // strip new lines
	while (c != '\n' && c != 0) {
		t = 0;
		while(c != ' ' && c != '\n' && c!=0) {
			t = t * 10 + (c-'0');
			c = getchar();
		}
		res.push_back(t);
		if (c != 0 && c != '\n') c = getchar();
	}
	return res;
} 

char board[2005][2005];
bool seen[2005][2005];

struct bfs_node {
	int x, y, d;
	bfs_node(int a, int b, int c) : x(a), y(b), d(c) {}
};

void bfs(vector<ii> &Apts) {
	memset(seen, false, sizeof(seen));
	queue<bfs_node> Q;
	int res = -1;
	for(int i=0; i < sz(Apts); i++)	Q.push(bfs_node(Apts[i].first, Apts[i].second, 0));

	while(!Q.empty()) {
		bfs_node curr = Q.front();
		Q.pop();
		if (seen[curr.x][curr.y]) continue;
		seen[curr.x][curr.y] = 1;

		if (board[curr.x][curr.y] == 'B') {
			res = curr.d;
			break;
		}

		for(int dx=-1; dx <= 1; dx++)
			for(int dy=-1; dy <= 1; dy++)
				if (abs(dx) + abs(dy) == 1)
				if (curr.x + dx >= 0 && curr.x + dx < 2005 && curr.y+dy >= 0 && curr.y + dy < 2005)
				if (!seen[curr.x + dx][curr.y + dy])
					Q.push(bfs_node(curr.x+dx, curr.y+dy, curr.d+1));
	}

	printf("%d\n", res);
}


int main() {
	vector<int> line = readints();
	while(line.size() > 0 && line[0] != 0) {
		vector<int> Aseq, Bseq;
		memset(board, 0, sizeof(board));

		do {
			line = readints();
			if (line.size() > 1) 
				Aseq.insert(Aseq.end(), line.begin(), line.end());
		} while(line.size() > 1);

		do {
			line = readints();
			if (line.size() > 1) 
				Bseq.insert(Bseq.end(), line.begin(), line.end());
		} while(line.size() > 1);

		vector<ii> Apts, Bpts;
		
		for(int i=0; i < sz(Aseq); i+=2) { 
			Apts.push_back(ii(Aseq[i], Aseq[i+1]));
			board[Aseq[i]][Aseq[i+1]] = 'A';
		}

		for(int i=0; i < sz(Bseq); i+=2) {
			Bpts.push_back(ii(Bseq[i], Bseq[i+1]));
			board[Bseq[i]][Bseq[i+1]] = 'B';
		}

		bfs(Apts);
		
	}
	return 0;
}