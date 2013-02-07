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
	int n, t;
	string s, s2;
	cin >> n >> t >> s;
	for(int i=0; i < t; i++) {
		s2 = s;
		for(int j=0; j < s.size() - 1; j++) 
			if (s[j] == 'B' && s[j+1] == 'G')
				swap(s2[j], s2[j+1]);
		s = s2;
	}
	cout << s << endl;

	return 0;

}