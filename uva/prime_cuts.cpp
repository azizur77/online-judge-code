// UVa 406 - Prime cuts
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

bool prime[1005];

void sieve() {
	fill(prime, 1);

	for(int i=2; i <= 1000; i++)
		if (prime[i] == 1)
			for(int j=2*i; j <= 1000; j+=i)
				prime[j] = 0;
}

vector<int> get_primes(int n) {
	vector<int> ans;
	for(int i=1; i <= n; i++)
		if (prime[i])
			ans.push_back(i);
	return ans;
}

int main() {
	sieve();
	int N, C;
	while(scanf("%d %d", &N, &C) > 0) {
		vector<int> list = get_primes(N);
		int len = sz(list), low, high;

		// printf("%d\n", len);

		low = max(0, len/2 - C);
		if (len % 2) low = max(0, len/2-C+1);
		high = min(len-1, len/2 + C-1);

		printf("%d %d:", N, C);

		for(int i=low; i <= high; i++) 
			printf(" %d", list[i]);

		printf("\n\n");
	}
}