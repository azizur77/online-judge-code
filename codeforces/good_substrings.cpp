#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int dp[1505][1505];

int main() {
	string s;
	string table;
	int k;
	cin >> s >> table >> k;
	int n = sz(s);
	bool alpha[26];
	for(int i=0; i < 26; i++) alpha[i] = table[i] == '1';

	fill(dp, 0);
	ll res = 0;

	set<string> SS;

	for(int i=0; i < n; i++) {
		string temp;
		for(int j=i; j < n; j++) {
			char c = s[j];
			temp+=c;
			dp[i][j] = (alpha[c-'a'] == '0')  + (j > 0 ? dp[i][j-1] : 0);
			if (dp[i][j] <= k) 
				SS.insert(temp);
			else
				break;
		}
	}

	cout << sz(SS) << endl;
	return 0;
}