#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char curset[30];
int n;
bool lessthan[30][30];

void print_orderings() {
	// Warshall Closure
	for(int k=0; k < 26; k++) for(int i=0; i < 26; i++) for(int j=0; j < 26; j++)
		lessthan[i][j] = lessthan[i][j] || (lessthan[i][k] && lessthan[k][j]);
	
	vector<string> stack, result;
	stack.push_back("");

	while(stack.size()) {
		string curr = stack.back();
		stack.pop_back();

		if (curr.size() == n) 
			result.push_back(curr);
		else {
			for(int i=0; i < n; i++) {
				char c = curset[i];
				int flag = 0;
				for(int j=0; j < curr.size(); j++) {
					if (c == curr[j] || lessthan[c-'A'][curr[j]-'A']) {
						flag = 1;
						break;
					}
				}
				if (flag) continue;
				stack.push_back(curr + c);
			}
		}
	}
	sort(result.begin(), result.end());
	for(int i=0; i < result.size(); i++) {
		string buffer;
		for(int j=0; j < result[i].size(); j++) {
			buffer += result[i][j];
			if (j < result[i].size() - 1) buffer += ' ';
		}
		puts(buffer.c_str());
	}
	if (result.size() == 0) puts("NO");
	// printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);

	for(int t=0; t < T; t++) {
		n = 0;
		memset(lessthan, 0, sizeof(lessthan));

		char c = getchar();
		while (c == '\n') c = getchar();

		while (c != '\n') {
			if (c != ' ') curset[n++] = c;
			c = getchar();
		}

		int flag = 1, f2 = 0;
		while((c != '\n' && c != 0) || flag) {
			flag = 0;
			int l = getchar();
			if (l < 'A' || l > 'Z') break;
			getchar();
			int r = getchar();
			if (l == r) f2 = 1;
			c = getchar();
			lessthan[l - 'A'][r - 'A'] = 1;
		}
		if (f2) printf("NO\n");
		else print_orderings();
		if (t < T-1) printf("\n");
	}

	return 0;
}