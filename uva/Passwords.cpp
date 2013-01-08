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

vector<string> solve(vector<string> &dictionary, string pattern) {
	if (pattern == "") return vector<string> (1, "");
	vector<string> toappend = solve(dictionary, pattern.substr(1));
	vector<string> result;
	
	if (pattern[0] == '#') 
	for(int j=0; j < sz(dictionary); j++) 
		for(int i=0; i < sz(toappend); i++) 
				result.push_back(dictionary[j] + toappend[i]);
	else
	for(char j='0'; j <= '9'; j++)
		for(int i=0; i < sz(toappend); i++)
				result.push_back(j + toappend[i]);

	return result;
}

int main() {
	int n, rules;
	string rule;
	vector<string> dictionary;
	while(scanf("%d", &n) > 0) {
		dictionary.resize(n);
		for(int i=0; i < n; i++) 
			cin >> dictionary[i];
		cin >> rules;
		cout << "--" << endl;
		for(int i=0; i < rules; i++) {
			cin >> rule;
			vector<string> ans = solve(dictionary, rule);
			for(int j=0; j < sz(ans); j++) cout << ans[j] << endl;
		}
	}
	return 0;
}