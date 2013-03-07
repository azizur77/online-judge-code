#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
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
	int tx, ty;
	cin >> tx >> ty;

	int x = 0, y = 0, ctr = 0, step = 0;
	if (tx == 0 && ty == 0) {
		printf("0\n");
		return 0;
	}

	while (1) {
		bool flag = false;
		switch(ctr % 4) {
			case 0: {
				step++;
				while (x < step) {
					x++;
					if (x == tx && y == ty) {
						flag = true;
						break;
					}
				}
				break;
			}
			case 1: {
				while (y < step) {
					y++;
					if (x == tx && y == ty) {
						flag = true;
						break;
					}
				}
				break;
			}
			case 2: {
				while (x > -step) {
					x--;
					if (x == tx && y == ty) {
						flag = true;
						break;
					}
				}
				break;
			}
			case 3: {
				while (y > -step) {
					y--;
					if (x == tx && y == ty) {
						flag = true;
						break;
					}
				}
				break;
			}
		}
		if (flag) break;
		ctr++;
	}
	cout << ctr << endl;
	return 0;
}