// 154 - Recycling

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

vector<string> split(string str, char delim) {
	vector<string> results;
	string buffer;
	for(int i=0; i < str.size(); i++) {
		if (str[i] == delim) {
			results.push_back(buffer);
			buffer = "";
		}
		else 
			buffer += str[i];
	}
	if (buffer.size()) results.push_back(buffer);
	sort(all(results));
	assert(sz(results) == 5);
	return results;
}

void solve(vector<string> block) {
	int maxmatch = -1, matchcnt = 0;
	for(int i=0; i < block.size(); i++) {
		vector<string> b1 = split(block[i], ',');
		int cnt = 0;
		for(int j=0; j < block.size(); j++) {
			vector<string> b2 = split(block[j], ',');
			for(int k=0; k < min(sz(b1), sz(b2)); k++) 
				if (b1[k] == b2[k]) cnt++;
		}
		if (cnt > matchcnt) {
			matchcnt = cnt;
			maxmatch = i;
		}
	}
	printf("%d\n", maxmatch+1);
}

int main() {
	string buf;
	vector<string> block;
	while (1) {
		cin >> buf;
		if (buf[0] == '#') {
			if (block.size()) solve(block);
			break;
		}
		else if (buf[0] == 'e') {
			solve(block);
			block.clear();
		}
		else {
			block.push_back(buf);
		}
	}
	return 0;
}