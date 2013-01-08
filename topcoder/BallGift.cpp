#line 2 "BallGift.cpp"
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

inline int mod(int a, int m) {int p = a % m; return (a < 0) ? p+m : p; }

int solve(int players, int green, int red, int black) {
	if (red+green+black == 0) {
		return 0;
	}
	// assert(players);
	int best = 0;
	int cgreen=0, cblack=0, cred=0;

	if (green) cgreen = mod((1 + solve(players, green-1, red, black)), players);
	if(red) cred = mod((-1 - solve(players, green, red-1, black)), players);
	if(black) cblack = mod((1 + solve(players-1, green, red, black-1)), players);

	if (green && green > red && green > black) best = cgreen;
	else if (red && red > green && red > black) best = cred; 
	else if (black && black > green && black > red) best = cblack;
	else if (red == green && red > black) best = min(cgreen, cred);
	else if (red == black && red > green) best = min(cblack, cred);
	else if (black == green && black > red) best = min(cblack, cgreen);
	else best = min(min(cblack, cgreen), cred);
	return best;
}


class BallGift {
	public:
	int bestPosition(int players, int green, int red, int black) {
		return solve(players, green, red, black);
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
		cout << "Testing BallGift (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352274067;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BallGift _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int players = 4;
				int green = 3;
				int red = 0;
				int black = 0;
				_expected = 3;
				_received = _obj.bestPosition(players, green, red, black); break;
			}
			case 1:
			{
				int players = 4;
				int green = 0;
				int red = 1;
				int black = 0;
				_expected = 3;
				_received = _obj.bestPosition(players, green, red, black); break;
			}
			case 2:
			{
				int players = 4;
				int green = 1;
				int red = 1;
				int black = 0;
				_expected = 0;
				_received = _obj.bestPosition(players, green, red, black); break;
			}
			case 3:
			{
				int players = 4;
				int green = 1;
				int red = 1;
				int black = 1;
				_expected = 1;
				_received = _obj.bestPosition(players, green, red, black); break;
			}
			case 4:
			{
				int players = 4;
				int green = 2;
				int red = 2;
				int black = 2;
				_expected = 0;
				_received = _obj.bestPosition(players, green, red, black); break;
			}
			/*case 5:
			{
				int players = ;
				int green = ;
				int red = ;
				int black = ;
				_expected = ;
				_received = _obj.bestPosition(players, green, red, black); break;
			}*/
			/*case 6:
			{
				int players = ;
				int green = ;
				int red = ;
				int black = ;
				_expected = ;
				_received = _obj.bestPosition(players, green, red, black); break;
			}*/
			/*case 7:
			{
				int players = ;
				int green = ;
				int red = ;
				int black = ;
				_expected = ;
				_received = _obj.bestPosition(players, green, red, black); break;
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
