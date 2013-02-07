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
#define EPS (1e15)

struct node {
	double len, lik;
	node(double a=0.0, double b=0.0) : len(a), lik(b/100.0) {}
	const bool operator<(const node &rhs) const {
		if (fabsl(lik * len) - (rhs.lik * rhs.len) > EPS) return (lik * len) > (rhs.len * rhs.lik);
		return lik > rhs.lik;
	}
};

int main() {
	int n, a, b;
	cin >> n;
	vector<node> songs;
	double explik = 0.0, wait = 0.0;
	for(int i=0; i < n; i++) { 
		cin >> a >> b;
		node nd(a, b);
		if (b == 100) {
			wait += a;
			explik += a;
		} 
		else
			songs.push_back(nd);
	}
	sort(all(songs));
	for(int i=0; i < songs.size(); i++) {
		wait += songs[i].len;
		wait += (1.0 - songs[i].lik) * explik;
		explik += songs[i].lik * songs[i].len;
	}
	printf("%.10lf\n", wait);
	return 0;
}