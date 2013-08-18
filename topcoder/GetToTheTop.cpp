#line 2 "GetToTheTop.cpp"
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
#define EPS 1e-9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sqr(x) ((x) * (x))
#define sz(x)    ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

bool canjump[55][55], same_height[55][55];
vi _sweets;
int n;

int memo[55], level_sum[55];

class GetToTheTop {
	public:
	double euclid(double x1, double y1, double x2, double y2) {
		return sqrt(sqr(x1-x2) + sqr(y1-y2));
	}

	int solve(int stair) {
		if (stair > n) return 0;
		if (memo[stair] != -1) return memo[stair];

		int ret = (stair > 0) ? level_sum[stair-1] : 0;
		int add = 0;

		for(int i=0; i <= n; i++)
			if (canjump[stair][i])
				add = max(add, solve(i));
		return (memo[stair]=ret+add);
	}

	int collectSweets(int K, vector <int> sweets, vector <int> x, vector <int> y, vector <int> stairLength) {
		fill(canjump, 0);
		fill(memo, -1);
		_sweets = sweets;
		n = sz(sweets);
		fill(level_sum, 0);
		fill(same_height, 0);


		for(int i=0; i < n; i++)
			canjump[0][i+1] = y[i] <= K;

		for(int i=0; i < n; i++)
			for(int j=0; j < n; j++)
				if (i != j && y[j] > y[i]) {
					canjump[i+1][j+1] = min(
						euclid(x[i]+stairLength[i], y[i], x[j], y[j]),
						euclid(x[i], y[i], x[j]+stairLength[j], y[j])
						) < double(K+EPS);
					if ((x[i] + stairLength[i] >= x[j] && x[j] + stairLength[j] >= x[i])
						|| (x[j] + stairLength[j] >= x[i] && x[i] + stairLength[i] >= x[j]))
						canjump[i+1][j+1] |= abs(y[i] - y[j]) <= K;
				}

		for(int i=0; i < n; i++)
			for(int j=0; j < n; j++)
				if (y[i] == y[j] && (
					euclid(x[i] + stairLength[i], y[i], x[j], y[j]) <= (EPS + K) ||
					euclid(x[i], y[i], x[j] + stairLength[j], y[j]) <= (EPS + K) ||
					i == j
					)) {
						same_height[i][j] = 1;
					}

		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j) 
				for (int k = 0; k < n; ++k) 
					same_height[j][k] |= same_height[j][i] & same_height[i][k]; 
				
		for(int i=0; i < n; i++)
			for(int j=0; j < n; j++)
				if (same_height[i][j] == 1) {
						level_sum[i] += sweets[j];
					for(int k=0; k < n; k++) {
						canjump[i+1][k+1] = canjump[i+1][k+1] || canjump[j+1][k+1];
						canjump[j+1][k+1] = canjump[j+1][k+1] || canjump[i+1][k+1];
					}
				}	
		

		return solve(0);
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
		cout << "Testing GetToTheTop (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362666377;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GetToTheTop _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 4;
				int sweets[] = {1, 2, 3, 4, 5};
				int x[] = {1, 2, 3, 4, 5};
				int y[] = {1, 2, 3, 4, 5};
				int stairLength[] = {1, 2, 3, 4, 5};
				_expected = 15;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 1:
			{
				int K = 4;
				int sweets[] = {2, 8, 7, 4, 1, 4, 7, 5, 11, 4};
				int x[] = {2, 9, 4, 6, 10, 5, 2, 8, 1, 10};
				int y[] = {1, 1, 3, 3, 3, 5, 6, 6, 8, 9};
				int stairLength[] = {2, 2, 1, 2, 2, 2, 4, 3, 2, 2};
				_expected = 47;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 2:
			{
				int K = 10;
				int sweets[] = {1, 3, 5, 7};
				int x[] = {1, 6, 2, 8};
				int y[] = {2, 4, 1, 2};
				int stairLength[] = {4, 1, 7, 4};
				_expected = 16;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 3:
			{
				int K = 3;
				int sweets[] = {80, 20, 15, 13, 10, 7, 8, 9, 1, 4, 3, 15, 14, 19, 22, 12, 6, 15, 10, 30, 1, 1};
				int x[] = {2, 8, 11, 17, 20, 14, 10, 16, 8, 14, 19, 6, 6, 6, 6, 15, 15, 15, 14, 20, 20, 20};
				int y[] = {1, 2, 3, 2, 1, 4, 6, 7, 8, 8, 8, 9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11};
				int stairLength[] = {2, 2, 2, 2, 2, 2, 3, 2, 3, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 129;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 4:
			{
				int K = 10;
				int sweets[] = {0, 10, 11, 2, 0};
				int x[] = {1, 26, 29, 22, 3};
				int y[] = {1, 83, 88, 22, 5};
				int stairLength[] = {11, 1, 23, 15, 8};
				_expected = 0;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 5:
			{
				int K = 5;
				int sweets[] = {2, 0, 5};
				int x[] = {1, 8, 9};
				int y[] = {6, 6, 1};
				int stairLength[] = {3, 6, 3};
				_expected = 7;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 6:
			{
				int K = 2;
				int sweets[] = {2, 9, 9, 1, 9, 9, 8};
				int x[] = {10, 8, 6, 6, 8, 7, 3};
				int y[] = {6, 7, 5, 4, 5, 2, 5};
				int stairLength[] = {1, 1, 1, 1, 1, 1, 1};
				_expected = 47;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 7:
			{
				//,}

				int K = 20;
				int sweets[] = {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999};
				int x[] = {2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 70, 74, 78, 82, 86, 90, 94, 98, 102, 106, 110, 114, 118, 122, 126, 130, 134, 138, 142, 146, 150, 154, 158, 162, 166, 170, 174, 178, 182, 186, 190, 194, 198};
				int y[] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
				int stairLength[] =  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
				_expected = 499950;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			/*case 8:
			{
				int K = ;
				int sweets[] = ;
				int x[] = ;
				int y[] = ;
				int stairLength[] = ;
				_expected = ;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int K = ;
				int sweets[] = ;
				int x[] = ;
				int y[] = ;
				int stairLength[] = ;
				_expected = ;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
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
