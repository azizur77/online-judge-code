#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int assignment[1000005];

int main() {
	srand(time(0));
	fill(assignment, -1);
	int n, k, filled = 0, lim;

	cin >> n >> k;

	if (3*k > n || n < 6 || k == 1) {
		printf("-1\n");
		return 0;
	}

	for(int i=0; i < n-5; i++) 
		if (assignment[i] == -1 && assignment[i+2] == -1 && assignment[i+5] == -1) {
			assignment[i] = assignment[i+2] = assignment[i+5] = filled;
			if (filled < k-1)
				filled++;
		}
	
	vi ins, posns;


	for(int i=0; i < n; i++)
		if (assignment[i] == -1)
			posns.push_back(i);

	for(int i=filled; i < k; i++)
		for(int j=0; j < 3; j++)
			ins.push_back(i);
	// cout << sz(ins) << endl;
	for(int i=0; i < n - 3*k; i++)
		ins.push_back(k-1);

	bool flag = false;

	while(!flag && filled < k-1	) {
		flag = true;
		for(int i=2; i < sz(ins); i++)
			if (posns[i]+1 == posns[i+1] && posns[i+1]+1 == posns[i+2] && ins[i] == ins[i-1] && ins[i-1] == ins[i-2]) {
				flag = false;
				break;
			}
		random_shuffle(all(ins));
	}

	int idx = 0;

	for(int i=0; i < n; i++)
		if (assignment[i] == -1)
			assignment[i] = ins[idx++];



	for(int i=0; i < n-1; i++)
		printf("%d ", assignment[i] + 1);
	printf("%d\n", assignment[n-1] + 1);
	return 0;
}