#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()

int main() {
	int k;
	cin >> k;
	string s;
	cin >> s;
	int moves = 0;

	for(int i=0; i < s.size() - 1;) {
		int next = i+1;
		while(s[next] == s[i]) {
			next++;
			moves++;
		}
		i = next;
	}

	cout << moves << endl;

	return 0;
}