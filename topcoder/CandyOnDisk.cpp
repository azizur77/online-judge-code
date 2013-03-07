#line 2 "CandyOnDisk.cpp"
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


class CandyOnDisk {
	public:
	string ableToAchieve(vector <int> x, vector <int> y, vector <int> r, int sx, int sy, int tx, int ty) {
		
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
		cout << "Testing CandyOnDisk (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361293809;
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
		CandyOnDisk _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 4};
				int y[] = {0, 0};
				int r[] = {3, 3};
				int sx = -1;
				int sy = -2;
				int tx = 6;
				int ty = 1;
				_expected = "YES";
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
			}
			case 1:
			{
				int x[] = {0, 3};
				int y[] = {0, 0};
				int r[] = {5, 3};
				int sx = -4;
				int sy = 0;
				int tx = -2;
				int ty = 0;
				_expected = "YES";
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
			}
			case 2:
			{
				int x[] = {0};
				int y[] = {0};
				int r[] = {1};
				int sx = 0;
				int sy = 0;
				int tx = 571;
				int ty = 571;
				_expected = "NO";
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
			}
			case 3:
			{
				int x[] = {0};
				int y[] = {0};
				int r[] = {1};
				int sx = 571;
				int sy = 571;
				int tx = 571;
				int ty = 571;
				_expected = "YES";
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
			}
			case 4:
			{
				int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
				int y[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
				int r[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
				int sx = 2;
				int sy = 2;
				int tx = 19;
				int ty = 19;
				_expected = "YES";
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
			}
			case 5:
			{
				int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
				int y[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
				int r[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int sx = 2;
				int sy = 2;
				int tx = 19;
				int ty = 19;
				_expected = "NO";
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
			}
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int r[] = ;
				int sx = ;
				int sy = ;
				int tx = ;
				int ty = ;
				_expected = ;
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int r[] = ;
				int sx = ;
				int sy = ;
				int tx = ;
				int ty = ;
				_expected = ;
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int y[] = ;
				int r[] = ;
				int sx = ;
				int sy = ;
				int tx = ;
				int ty = ;
				_expected = ;
				_received = _obj.ableToAchieve(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int)), sx, sy, tx, ty); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
