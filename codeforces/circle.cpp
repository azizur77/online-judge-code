#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <assert.h>
using namespace std;

vector<int> edges[100005];
bool seen[100005], used[100005][4];

struct conn {
	int ll, l, r, rr;
} nodes[100005];

int idx;

bool check(int a, int b) {
	idx = -1;
	for(int i=0; i < 4; i++)
		if (!used[a][i] && edges[a][i] == b)
			{ idx = i; return true; }
	return false;
}


int main() {
	int N;
	scanf("%d", &N);
	for(int i=0; i < 2*N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	for(int i=1; i <= N; i++)
		if (edges[i].size() != 4) {
			puts("-1a");
			return 0;
		}

	int perm[4] = {1, 2, 3, 4};
	bool flag;

	do {
		for(int i=1; i <= N; i++) { nodes[i].ll = nodes[i].l = nodes[i].r = nodes[i].rr = -1; seen[i] = false; 
			for(int j=0; j < 4; j++) used[i][j] = false;}
		nodes[1].ll = edges[1][perm[0]];
		nodes[1].l = edges[1][perm[1]];
		nodes[1].r = edges[1][perm[2]];
		nodes[1].rr = edges[1][perm[3]];
		for(int i=0; i < 4; i++) used[0][i] = true;

		queue<int> Q;
		Q.push(1);

		flag = true;
		int ctr = 0;

		while(Q.size() > 0) {
			++ctr;
			int curr = Q.front();
			Q.pop();
			if (seen[curr]) continue;
			bool flag_int = true;

			if (nodes[curr].ll != -1) {
				flag_int &= check(nodes[curr].ll, curr);
				nodes[nodes[curr].ll].rr = curr;
				used[nodes[curr].ll][idx] = true;
				Q.push(nodes[curr].ll);
			}
			if (nodes[curr].rr != -1) {
				flag_int &= check(nodes[curr].rr, curr);
				nodes[nodes[curr].rr].ll = curr;
				used[nodes[curr].rr][idx] = true;
				Q.push(nodes[curr].rr);
			}
			if (nodes[curr].l != -1) {
				flag_int &= check(nodes[curr].l, curr);
				nodes[nodes[curr].l].r = curr;
				used[nodes[curr].l][idx] = true;
				Q.push(nodes[curr].l);
			}
			if (nodes[curr].r != -1) {
				flag_int &= check(nodes[curr].r, curr);
				nodes[nodes[curr].r].l = curr;
				used[nodes[curr].r][idx] = true;
				Q.push(nodes[curr].r);
			}

			if (!flag_int) {flag = false; break;}
			if (nodes[curr].l != -1 && nodes[curr].r != -1 && nodes[curr].ll != -1 && nodes[curr].rr != -1)
				seen[curr] = true;
		}
		printf("%d\n", ctr);
		if (flag) break;

	} while(next_permutation(perm, perm + 4));

	if (!flag) {
		puts("-1b");
		return 0;
	}

	else {
		vector<int> res;
		int x = 1;
		do {
			res.push_back(x);
			x = nodes[x].l;
		} while(x != 1);
		assert(res.size() == N);
		for(int i=0; i < N-1; i++) printf("%d ", res[i]);
		printf("%d\n", res[N-1]); 
	}

	return 0;
}