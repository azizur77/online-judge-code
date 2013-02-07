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

int arr[100005];

int main() {
	int N, moves = 0;
	cin >> N;
	for(int i=0; i < N; i++) cin >> arr[i];
	int curr = 0;

	for(int i=0; i < N-1; i++) {
		moves += (arr[i] - curr);
		curr = arr[i];
		if (i < N-1 && arr[i] >= arr[i+1]) {
			curr = arr[i+1];
			moves += arr[i] - arr[i+1];
		}
	}
	moves += (arr[N-1] - curr);
	moves += 2*N - 1;
	cout << moves << endl;
	return 0;
}