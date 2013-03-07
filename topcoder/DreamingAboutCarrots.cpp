#line 2 "DreamingAboutCarrots.cpp"
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


class DreamingAboutCarrots {
	public:
	int carrotsBetweenCarrots(int x1, int y1, int x2, int y2) {
		int points = 0;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		if (x1 != x2) {
			double slope = 1.0 * (y2 - y1) / (x2 - x1);
			double c = 1.0 * y2 - slope * x2;
			for(int x = x1+1; x < x2; x++) {
				double y = slope * x + c;
				if (abs(round(y) - y) < 1e-5)
					points++;
			}
		} else {
			points = y2 - y1 - 1;
		} 
		return points;
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
		cout << "Testing DreamingAboutCarrots (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362622680;
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
		DreamingAboutCarrots _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1 = 1;
				int y1 = 1;
				int x2 = 5;
				int y2 = 5;
				_expected = 3;
				_received = _obj.carrotsBetweenCarrots(x1, y1, x2, y2); break;
			}
			case 1:
			{
				int x1 = 0;
				int y1 = 0;
				int x2 = 1;
				int y2 = 1;
				_expected = 0;
				_received = _obj.carrotsBetweenCarrots(x1, y1, x2, y2); break;
			}
			case 2:
			{
				int x1 = 50;
				int y1 = 48;
				int x2 = 0;
				int y2 = 0;
				_expected = 1;
				_received = _obj.carrotsBetweenCarrots(x1, y1, x2, y2); break;
			}
			case 3:
			{
				int x1 = 0;
				int y1 = 0;
				int x2 = 42;
				int y2 = 36;
				_expected = 5;
				_received = _obj.carrotsBetweenCarrots(x1, y1, x2, y2); break;
			}
			/*case 4:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				_expected = ;
				_received = _obj.carrotsBetweenCarrots(x1, y1, x2, y2); break;
			}*/
			/*case 5:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				_expected = ;
				_received = _obj.carrotsBetweenCarrots(x1, y1, x2, y2); break;
			}*/
			/*case 6:
			{
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				_expected = ;
				_received = _obj.carrotsBetweenCarrots(x1, y1, x2, y2); break;
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
