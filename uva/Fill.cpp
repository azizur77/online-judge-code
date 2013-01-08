#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool seen[205][205][205] = {false};

struct heap_item {
	int a, b, c, cost;
	heap_item(int x, int y, int z, int w) : a(x), b(y), c(z), cost(w) {}
	const bool operator<(const heap_item &rhs) const {
		return cost > rhs.cost;
	}
};

void solve(int a, int b, int c, int d) {
	priority_queue<heap_item> heap;
	heap.push(heap_item(0, 0, c, 0));
	int dprime = -1, dcost = -1;
	memset(seen, false, sizeof(seen));

	while(heap.size() > 0) {
		heap_item curr = heap.top();
		heap.pop();
		if (seen[curr.a][curr.b][curr.c]) continue;
		seen[curr.a][curr.b][curr.c] = 1;

		if (curr.c == d || curr.b == d || curr.a == d) {
			dprime = d;
			dcost = curr.cost;
			break;
		}

		if (curr.a < d && curr.a > dprime) { dprime = curr.a; dcost = curr.cost; } 
		if (curr.b < d && curr.b > dprime) { dprime = curr.b; dcost = curr.cost; } 
		if (curr.c < d && curr.c > dprime) { dprime = curr.c; dcost = curr.cost; } 

		int pour;
		// 1->2
		pour = min(curr.a, b - curr.b);
		if (pour) heap.push(heap_item(curr.a - pour, curr.b + pour, curr.c, curr.cost + pour));
		// 2->3
		pour = min(curr.b, c - curr.c);
		if (pour) heap.push(heap_item(curr.a , curr.b - pour, curr.c + pour, curr.cost + pour));
		// 3->1
		pour = min(curr.c, a - curr.a);
		if (pour) heap.push(heap_item(curr.a + pour, curr.b, curr.c - pour, curr.cost + pour));
		// 2->1
		pour = min(curr.b, a - curr.a);
		if (pour) heap.push(heap_item(curr.a + pour, curr.b - pour, curr.c, curr.cost + pour));
		// 3->2
		pour = min(curr.c, b - curr.b);
		if (pour) heap.push(heap_item(curr.a , curr.b + pour, curr.c - pour, curr.cost + pour));
		// 1->3
		pour = min(curr.a, c - curr.c);
		if (pour) heap.push(heap_item(curr.a - pour, curr.b, curr.c + pour, curr.cost + pour));
	}
	printf("%d %d\n", dcost, dprime);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		solve(a, b, c, d);
	}
	return 0;
}