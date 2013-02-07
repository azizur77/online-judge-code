#include <stdio.h>
#include <string.h>
typedef long long ll;

bool blocked[35][35][2];
int N, fx, fy, sx, sy;
ll memo[35][35];

ll solve(int x, int y) {
	if (memo[x][y] != -1) return memo[x][y];
	if (x==fx && y==fy) return 1LL;
	ll &ret = memo[x][y];
	ret = 0;

	if (x+1 <= N && !blocked[x][y][0]) ret += solve(x+1, y);
	if (y+1 <= N && !blocked[x][y][1]) ret += solve(x, y+1);

	return ret;
}

int main() {
	int C, W, a, b;
	char s[5];
	scanf("%d", &C);
	for(int c=0; c < C; c++) {
		memset(memo, -1, sizeof(memo));
		memset(blocked, 0, sizeof(blocked));

		scanf("%d", &N);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &fx, &fy);
		scanf("%d", &W);
		for(int i=0; i < W; i++) {
			scanf("%d %d %s", &a, &b, s);
			switch(s[0]) {
			case 'N': blocked[a][b][1] = 1; break;
			case 'E': blocked[a][b][0] = 1; break;
			case 'W': blocked[a-1][b][0] = 1; break;
			case 'S': blocked[a][b-1][1] = 1; 
			}
		}
		printf("%lld\n", solve(sx, sy));
	}
	return 0;
}