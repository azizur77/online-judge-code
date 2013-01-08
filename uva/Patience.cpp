// 127 - Accordian Patience
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

class Stack {
	char data[55][3];
	int ptr;
public:
	Stack() {
		ptr = 0;
	}
	void push(char *s) {
		strcpy(data[ptr], s);
		data[ptr][2] = '\0';
		ptr++;
	}
	void pop() {
		ptr--;
	}
	void top(char *dest) {
		strcpy(dest, data[ptr-1]);
	}
	bool empty() {
		return ptr == 0;
	}
	int size() {
		return ptr;
	}
};

void reduce(vector< Stack > &piles) {
	for(vector< Stack >::iterator it = piles.begin(); it != piles.end(); it++) {
		int index = it - piles.begin();
		if (index > 2 && !it->empty()) {
			char curr[3], prev[3]; 
			it->top(curr);
			(it - 3)->top(prev);
			if (curr[0] == prev[0] || curr[1] == prev[1]) {
				(it-3)->push(curr);
				it->pop();
				if (it->empty()) piles.erase(it);
				reduce(piles);
				return;
			}
		}
		if (index > 0 && !it->empty()) {
			char curr[3], prev[3];
			it->top(curr);
			(it-1)->top(prev);
			if (curr[0] == prev[0] || curr[1] == prev[1]) {
				(it-1)->push(curr);
				it->pop();
				if (it->empty()) piles.erase(it);
				reduce(piles);
				return;
			}
		}
	}
}

int main() {
	char buf[5];
	string card;
	scanf("%s", buf);
	while (buf[0] != '#') {
		vector< Stack > piles;
		piles.push_back(Stack());
		piles[0].push(buf);
		for(int i=0; i < 52; i++) {
			reduce(piles);
			scanf("%s", buf);
			if (i < 51)	{
				piles.push_back(Stack());
				piles[sz(piles) - 1].push(buf);
			}
		}
		int last = sz(piles);
		if (last == 1) printf("1 pile remaining: 52\n");
		else {
			printf("%d piles remaining: ", last);
			for(int i=0; i < last-1; i++) printf("%d ", sz(piles[i]));
			printf("%d\n", sz(piles[last-1]));
		}
	}
	return 0;
}