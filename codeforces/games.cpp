#include <stdio.h>
#include <iostream>
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
	int colors[40][2];
	int n, host = 0;
	cin >> n;

	for(int i=0; i < n; i++) 
		scanf("%d %d", &colors[i][0], &colors[i][1]);

	for(int i=0; i < n; i++)
		for(int j=i+1; j < n; j++) {
			if (colors[i][0] == colors[j][1]) host++;
			if (colors[i][1] == colors[j][0]) host++;
		}
	cout << host << endl; 
	return 0;
}