#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tr;

void read(vector<string> &order) {
	tr.resize(order.size());
	for(int i=0; i < order.size(); i++) tr[i] = order[i][1] - '1';
}

int index(string assign) {
	vector<int> remap(assign.size());
	for(int i=0; i < assign.size(); i++) remap[i] = assign[tr[i]] - '0';
	int idx = 0;
	for(int i=0; i < assign.size(); i++) idx = idx * 2 + remap[i];
	return idx;
}

int main() {
	int N, t=0, M;
	while((cin >> N) > 0 && N > 0) {
		t++;
		vector<string> order(N);
		for(int i=0; i < N; i++) cin >> order[i];
		read(order);

		string seq(1<<N, '0');
		cin >> seq;

		cin >> M;
		string result(M, ' ');
		for(int i=0; i < M; i++) {
			string assign;
			cin >> assign;
			result[i] = seq[index(assign)];
		}
		printf("S-Tree #%d:\n%s\n\n", t, result.c_str());
	}
	return 0;
}