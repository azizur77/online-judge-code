// 11504 - Dominos(Tarjan)
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edges[200005], incoming[200005], incnew[200005];
int label[200005], ctr=1, idx[200005], lowlink[200005], N;
bool seen[200005], instack[200005], completed[200005];
vector<int> S, counter;

void tarjan(int node) {
	if (seen[node]) return;
	seen[node] = instack[node] = true;
	lowlink[node] = idx[node] = ctr++;
	S.push_back(node);
	for(int i=0; i < (int) edges[node].size(); i++) {
		if (!seen[edges[node][i]]) {
			tarjan(edges[node][i]);
			lowlink[node] = min(lowlink[node], lowlink[edges[node][i]]);
		}
		else if (instack[edges[node][i]])
			lowlink[node] = min(lowlink[node], idx[edges[node][i]]);
	}

	if (lowlink[node] == idx[node])
	while(S.size()) {
		int t = S.back(); S.pop_back();
		instack[t] = false;
		label[t] = node;
		if (t == node) break;
	}
}

struct stack_item {
	int node, caller, ret, entry;
	stack_item(int n, int c, int r=-1, int e=0) : node(n), caller(c), ret(r), entry(e) {}
};

vector<stack_item> personal_stack[200005];

void tarjan_iter(int node) {
	vector<stack_item> _stack; // global stack
	_stack.push_back(stack_item(node, node));

	while(_stack.size() > 0) {
		stack_item curr = _stack.back();
		_stack.pop_back();

		if (completed[curr.node]) continue;

		if (curr.ret != -1)
			personal_stack[curr.node].push_back(stack_item(curr.caller, curr.node, -1, curr.ret));

		if (!seen[curr.node]) {
			seen[curr.node] = instack[curr.node] = true;
			S.push_back(curr.node);
			lowlink[curr.node] = idx[curr.node] = ctr++;
		}
		else {
			lowlink[curr.node] = min(lowlink[curr.node], lowlink[curr.caller]);
		}

		int flag = 0;
		for(int i=curr.entry; i < (int) edges[curr.node].size(); i++) {
			if (!seen[edges[curr.node][i]]) {
				_stack.push_back(stack_item(edges[curr.node][i], curr.node, i+1));
				flag = 1;
				break;
			}
			else if (instack[edges[curr.node][i]]) {
				lowlink[curr.node] = min(lowlink[curr.node], idx[edges[curr.node][i]]);
			}
		}
		if (flag) continue; 

		if (idx[curr.node] == lowlink[curr.node])
		while(1) {
			int temp = S.back();
			S.pop_back();
			label[temp] = curr.node;
			instack[temp] = false;
			if (temp == curr.node) break;
		}
		completed[curr.node] = 1;
		while(personal_stack[curr.node].size()) {
			_stack.push_back(personal_stack[curr.node].back());
			personal_stack[curr.node].pop_back();
		}
	}

}

void compress_solve() {
	int ans = 0;
	for(int i=1; i <= N; i++) {
		for(int j=0; j < (int) incoming[i].size(); j++)
			if (label[incoming[i][j]] != label[i]) {
				if (label[i] > N) while(1);
				incnew[label[i]].push_back(incoming[i][j]);
			}
	}
	for(int i=1; i <= N; i++)
		if (label[i] == i && incnew[i].size() == 0)
			ans++;
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		int m;
		scanf("%d %d", &N, &m);
		ctr = 1;
		S.clear();
		for(int i=1; i <= N; i++) {
			completed[i] = idx[i] = seen[i] = instack[i] = 0;
			lowlink[i] = (int) 1e9;
			edges[i].clear();
			incoming[i].clear();
			incnew[i].clear();
			personal_stack[i].clear();
			label[i] = i;
		}

		for(int j=0; j < m; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			edges[x].push_back(y);
			incoming[y].push_back(x);
		}
		counter.resize(N);
		for(int i=1; i <= N; i++) tarjan_iter(i);
		compress_solve();
	}
	return 0;
}
