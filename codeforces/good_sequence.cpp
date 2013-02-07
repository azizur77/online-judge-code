#include <stdio.h>
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

int arr[100005], N;
int best[100005];

int main() {
	scanf("%d", &N);

	for(int i=0; i < N; i++) scanf("%d", &arr[i]);

	for(int i=0; i < N; i++) {
		int num = arr[i];
		int l = (int) sqrt(num) + 1;
		int ctr = 0;
		vector<int> cands(l, 0);
		for(int j=2; j <= sqrt(num); j++) {
			bool flag = false;
			while(num % j == 0) {
				flag = true;
				num = num / j;
			}
			if (flag) cands[ctr++] = j;
		}
		if (num > 1) cands[ctr++] = num;
		int b = 0;
		for(int j=0; j < ctr; j++) b = (best[cands[j]] > b) ? best[cands[j]] : b;
		b++;
		best[num] = b;
		for(int j=0; j < ctr; j++) best[cands[j]] = b; 
	}

	printf("%d\n", *max_element(best, best+100005));
	return 0;

}