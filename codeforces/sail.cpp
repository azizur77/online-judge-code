#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <string>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int main() {
	int t, sx, sy, ex, ey;
	cin >> t >> sx >> sy >> ex >> ey;

	int east, west, north, south, cEast=0, cNorth=0, cWest=0, cSouth=0;
	east = (ex > sx) ? ex - sx : 0;
	west = (ex < sx) ? sx - ex : 0;
	north = (ey > sy) ? ey - sy : 0;
	south = (ey < sy) ? sy - ey : 0;

	string directions;
	cin >> directions;
	bool flag = false;

	for(int i=0; i < t; i++) {
		switch(directions[i]) {
			case 'N' : cNorth++; break;
			case 'E' : cEast++; break;
			case 'W' : cWest++; break;
			case 'S' : cSouth++; break;
		}
		if (cNorth >= north && cEast >= east && cWest >= west && cSouth >= south) {
			cout << i+1 << endl;
			flag = true;
			break;
		}
	}

	if (!flag) {
		puts("-1");
	}

	return 0;


}