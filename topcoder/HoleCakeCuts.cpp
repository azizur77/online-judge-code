#line 2 "HoleCakeCuts.cpp"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define M 105

bool adj[230][230][4];
int comp[230][230], ctr = 0;

// 0123 - NESW
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void connect(int x, int y) {
	if (comp[x][y] != -1) return;
	comp[x][y] = ctr;
	for(int i = 0; i < 4; i++) 
		if (adj[x+dx[i]][y + dy[i]])
			connect(x+dx[i], y+dy[i]);
}

class HoleCakeCuts {
	public:
	int cutTheCake(int cakeLength, int holeLength, vector <int> horizontalCuts, vector <int> verticalCuts) {
		fill (adj, 1);
		fill (comp, -1);

		for(int i = -cakeLength; i <= cakeLength; i++) {
			adj[M+cakeLength-1][M+i][0] = 0;  // Can't go out of boundaries
			adj[M - cakeLength][M + i][2] = 0;
			adj[M + i][M - cakeLength][3] = 0;
			adj[M + i][M + cakeLength-1][1] = 0;
		}

		for(int i=0; i < sz(horizontalCuts); i++) {
			int k = horizontalCuts[i];
			for(int j=-cakeLength; j <= cakeLength; j++) {
				adj[M+k-1][M+j][0] = 0;
				adj[M+k][M+j][2] = 0;
			}
		}

		for(int i=0; i < sz(verticalCuts); i++) {
			int k = verticalCuts[i];
			for(int j=-cakeLength; j <= cakeLength; j++) {
				adj[M+j][M+k][3] = 0;
				adj[M+j][M+k-1][1] = 0;
			}
		}

		for(int i = -holeLength; i<= holeLength-1; i++) {
			adj[M+i][M-holeLength-1][1] = 0;
			adj[M+i][M+holeLength][3] = 0;
			adj[M+holeLength][M+i][2] = 0;
			adj[M-holeLength-1][M+i][0] = 0;
		}

		for(int i=-holeLength; i < holeLength; i++)
			for(int j=-holeLength; j < holeLength; j++) {
				if (abs(i) <= holeLength && abs(j) <= holeLength) continue;
				if (comp[M+i][M+j] == -1) {
					connect(M+i, M+j);
					ctr++;
				}
			}
		return ctr;
	}
};




























// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing HoleCakeCuts (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363165136;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HoleCakeCuts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cakeLength = 5;
				int holeLength = 3;
				int horizontalCuts[] = {1, -4};
				int verticalCuts[] = {1};
				_expected = 6;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 1:
			{
				int cakeLength = 10;
				int holeLength = 5;
				int horizontalCuts[] = {};
				int verticalCuts[] = {-2, 2};
				_expected = 4;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 2:
			{
				int cakeLength = 10;
				int holeLength = 5;
				int horizontalCuts[] = {1};
				int verticalCuts[] = {-5, 5};
				_expected = 6;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 3:
			{
				int cakeLength = 50;
				int holeLength = 5;
				int horizontalCuts[] = {40, -40};
				int verticalCuts[] = {20, 0, -20};
				_expected = 12;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			/*case 4:
			{
				int cakeLength = ;
				int holeLength = ;
				int horizontalCuts[] = ;
				int verticalCuts[] = ;
				_expected = ;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int cakeLength = ;
				int holeLength = ;
				int horizontalCuts[] = ;
				int verticalCuts[] = ;
				_expected = ;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int cakeLength = ;
				int holeLength = ;
				int horizontalCuts[] = ;
				int verticalCuts[] = ;
				_expected = ;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
