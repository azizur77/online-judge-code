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
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	for(int i=0; i < N; i++) cin >> arr[i];
	int changes = N-1, i = N-1;
	while (i > 0 && arr[i] > arr[i-1]) {
		changes--;
		i--;
	} 
	cout << changes << endl;
	return 0;
}