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
	void push(string s) {
		strcpy(data[ptr], s.substr(0,2).c_str());
		data[ptr][2] = '\0';
		ptr++;
	}
	void pop() {
		ptr--;
	}
	string top() {
		return data[ptr-1];
	}
	bool empty() {
		return ptr == 0;
	}
	int size() {
		return ptr;
	}
};

int last;

void reduce(vector< Stack > &piles) {
	for(vector< Stack >::iterator it = piles.begin(); it != piles.end(); it++) {
		int index = it - piles.begin();
		if (index > 2 && !it->empty()) {
			string curr = it->top();
			string prev = (it - 3)->top();
			if (curr[0] == prev[0] || curr[1] == prev[1]) {
				(it-3)->push(string(curr));
				it->pop();
				if (it->empty()) piles.erase(it);
				reduce(piles);
				return;
			}
		}
		if (index > 0 && !it->empty()) {
			string curr = it->top();
			string prev = (it-1)->top();
			if (curr[0] == prev[0] || curr[1] == prev[1]) {
				(it-1)->push(string(curr));
				it->pop();
				if (it->empty()) piles.erase(it);
				reduce(piles);
				return;
			}
		}
	}
}

void reduce2(vector< Stack > &piles) {
	for(int index=0; index < last; index++) {
		if (index > 2 && !piles[index].empty()) {
			string curr = piles[index].top();
			string prev = piles[index-3].top();
			if (curr[0] == prev[0] || curr[1] == prev[1]) {
				piles[index-3].push((curr));
				piles[index].pop();
				if (piles[index].empty()) {
					for(int i = index+1; i < last; i++) 
						piles[i-1] = piles[i];
					last--;
				}
				reduce2(piles);
				return;
			}
		}
		if (index > 0 && !piles[index].empty()) {
			string curr = piles[index].top();
			string prev = piles[index-1].top();
			if (curr[0] == prev[0] || curr[1] == prev[1]) {
				piles[index-1].push((curr));
				piles[index].pop();
				if (piles[index].empty()) {
					for(int i = index+1; i < last; i++) 
						piles[i-1] = piles[i];
					last--;
				}
				reduce2(piles);
				return;
			}
		}
	}
}

int main() {
	char buf[5];
	string card;
	scanf("%s", buf);
	card = buf;
	while (card != "#") {
		vector< Stack > piles(52);
		piles[0].push(card);
		last = 1;

		for(int i=0; i < 52; i++) {
			reduce2(piles);
			scanf("%s", buf);
			card = buf;
			if (i < 51)	{
				piles[last++].push(card);
			}
		}
		if (last == 1) printf("1 pile remaining: 52\n");
		else {
			printf("%d piles remaining: ", last);
			for(int i=0; i < last-1; i++) printf("%d ", sz(piles[i]));
			printf("%d\n", sz(piles[last-1]));
		}
	}
	return 0;
}