#line 2 "ColorfulBoxesAndBalls.cpp"
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


class ColorfulBoxesAndBalls {
	public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
		
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
		cout << "Testing ColorfulBoxesAndBalls (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356017448;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ColorfulBoxesAndBalls _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numRed = 2;
				int numBlue = 3;
				int onlyRed = 100;
				int onlyBlue = 400;
				int bothColors = 200;
				_expected = 1400;
				_received = _obj.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors); break;
			}
			case 1:
			{
				int numRed = 2;
				int numBlue = 3;
				int onlyRed = 100;
				int onlyBlue = 400;
				int bothColors = 300;
				_expected = 1600;
				_received = _obj.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors); break;
			}
			case 2:
			{
				int numRed = 5;
				int numBlue = 5;
				int onlyRed = 464;
				int onlyBlue = 464;
				int bothColors = 464;
				_expected = 4640;
				_received = _obj.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors); break;
			}
			case 3:
			{
				int numRed = 1;
				int numBlue = 4;
				int onlyRed = 20;
				int onlyBlue = -30;
				int bothColors = -10;
				_expected = -100;
				_received = _obj.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors); break;
			}
			case 4:
			{
				int numRed = 9;
				int numBlue = 1;
				int onlyRed = -1;
				int onlyBlue = -10;
				int bothColors = 4;
				_expected = 0;
				_received = _obj.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors); break;
			}
			/*case 5:
			{
				int numRed = ;
				int numBlue = ;
				int onlyRed = ;
				int onlyBlue = ;
				int bothColors = ;
				_expected = ;
				_received = _obj.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors); break;
			}*/
			/*case 6:
			{
				int numRed = ;
				int numBlue = ;
				int onlyRed = ;
				int onlyBlue = ;
				int bothColors = ;
				_expected = ;
				_received = _obj.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors); break;
			}*/
			/*case 7:
			{
				int numRed = ;
				int numBlue = ;
				int onlyRed = ;
				int onlyBlue = ;
				int bothColors = ;
				_expected = ;
				_received = _obj.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors); break;
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
