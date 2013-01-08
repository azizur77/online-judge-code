// 10921 - Telephone
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

int main() {
	char map[256];
	map['-'] = '-';
	map['1'] = '1';
	map['0'] = '0';
	map['A'] = map['B'] = map['C'] = '2';
	map['D'] = map['E'] = map['F'] = '3';
	map['G'] = map['H'] = map['I'] = '4';
	map['J'] = map['K'] = map['L'] = '5';
	map['M'] = map['N'] = map['O'] = '6';
	map['P'] = map['Q'] = map['R']  = map['S'] = '7';
	map['T'] = map['U'] = map['V'] = '8';
	map['X'] = map['Y'] = map['Z'] = map['W'] = '9';

	char s[50];
	while (scanf("%s", s) > 0) {
		REP(i, strlen(s)) s[i] = map[s[i]];
		printf("%s\n", s);
	}
	return 0;
}