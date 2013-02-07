#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()

bool is_int(double x) {
	return x == floor(x);
}

double euclid(ii p, ii q) {
	return sqrt((p.X-q.X) * (p.X-q.X) + (p.Y - q.Y) * (p.Y - q.Y));
}

int main() {
	int n, m;
	cin >> n >> m;

	set<ii> best;
	for(int i=1; i <= min(m, n); i++) {
		set<ii> work;
		work.insert(ii(0, i));
		for(int a=0; a <= min(m, n); a++)
			for(int b=0; b <= min(m, n); b++)
				if (!(a == 0 && b == 0) && work.find(ii(a, b)) == work.end()) {
					set<ii>::iterator it;
					bool flag = true;
					for(it = work.begin(); it != work.end(); it++) {
						ii curr = *it;
						if (is_int(euclid(curr, ii(a, b)))) {
							flag = false;
							break;
						}
					}
					if (flag) work.insert(ii(a, b));
				}
		if (work.size() > best.size()) best = work;
		if (best.size() == min(m, n) + 1) break;
	} 
	// cout << best.size() << endl;
	printf("%d\n", best.size());
	set<ii>::iterator it;
	for(it = best.begin(); it != best.end(); it++)
		printf("%d %d\n", (*it).X, (*it).Y);
		// cout << (*it).X << " " << (*it).Y << endl;
	return 0;
}