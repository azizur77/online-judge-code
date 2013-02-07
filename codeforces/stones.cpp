#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()

int main() {
	string a, b;
	cin >> a >> b;
	int pos = 0;
	for(int i=0; i < b.size(); i++) 
		if (a[pos] == b[i]) pos++;
	cout << pos + 1 << endl;
	return 0;
}