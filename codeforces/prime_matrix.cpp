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

vi primes;
bool check[1000000];
int matrix[501][501];

void sieve() {
	fill(check, 1);
	for(int i=2; i < 1000000; i++)
		if (check[i])
			for(int j=2*i; j < 1000000; j += i)
				check[j] = false;
	for(int i=2; i < 1000000; i++)
		if (check[i])
			primes.push_back(i);
}

int next_prime(int m) {
	int idx = lower_bound(all(primes), m) - primes.begin();
	assert(primes[idx] >= m);
	return primes[idx];
}

int main() {
	sieve();


	assert(next_prime(4) == 5);
	assert(next_prime(3) == 3);

	int minmoves = (1<<30);

	int n, m;
	cin >> n >> m;



	for(int i=0; i < n; i++)
		for(int j=0; j < m; j++)
			cin >> matrix[i][j];

	for(int i=0; i < n; i++) {
		int score = 0;
		for(int j=0; j < m; j++) score += (next_prime(matrix[i][j]) - matrix[i][j]);
		minmoves = min(minmoves, score);
	}

	for(int i=0; i < m; i++) {
		int score = 0;
		for(int j=0; j < n; j++) score += (next_prime(matrix[j][i]) - matrix[j][i]);
		minmoves = min(minmoves, score);
	}

	cout << minmoves << endl;

	return 0;
}