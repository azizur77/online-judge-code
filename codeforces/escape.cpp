#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()

int S[1000005];
char cs[1000005];

int main() {
	int i = 0, j = 0, k=0;
	vector<int> res(1000005, 0);
	scanf("%s", cs);
	int l = strlen(cs);
	for(int u=0; u < l; u++){
		char c = cs[u];
		if (c == 'l') {
			S[j++] = i;
			i++;
		}
		else if (c == 'r') {
			res[k++] = i;
			i++;
		}
	}
	for(int x=j-1; x >= 0; x--) {
		res[k++] = S[x];
	}
	for(int j=0; j < k; j++)
		printf("%d\n", res[j]+1);
	return 0;
}