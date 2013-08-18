#line 2 "MarblesInABag.cpp"
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


class MarblesInABag {
	public:
	double getProbability(int redCount, int blueCount) {
		double rp[4005], rc[4005];
		for(int i=0; i <= blueCount; i++) rp[i] = i & 1;

		for(int r=1; r <= redCount; r++) {
			for(int b=0; b <= blueCount; b+=1) 
				if ((r+b) % 2 == 1) 
					rc[b] = ((b > 0 ) ? (1.0*r/(r+b))*rp[b-1] : 0) + (b>1?(1.0*b/(r+b))*rc[b-2]:0.0);
				else
					rc[b] = 0.0;
			REP(i, blueCount+1) rp[i] = rc[i];
		}

		return rp[blueCount];
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
		cout << "Testing MarblesInABag (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362798054;
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
		MarblesInABag _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int redCount = 1;
				int blueCount = 2;
				_expected = 0.3333333333333333;
				_received = _obj.getProbability(redCount, blueCount); break;
			}
			case 1:
			{
				int redCount = 2;
				int blueCount = 3;
				_expected = 0.13333333333333333;
				_received = _obj.getProbability(redCount, blueCount); break;
			}
			case 2:
			{
				int redCount = 2;
				int blueCount = 5;
				_expected = 0.22857142857142856;
				_received = _obj.getProbability(redCount, blueCount); break;
			}
			case 3:
			{
				int redCount = 11;
				int blueCount = 6;
				_expected = 0.0;
				_received = _obj.getProbability(redCount, blueCount); break;
			}
			case 4:
			{
				int redCount = 4;
				int blueCount = 11;
				_expected = 0.12183372183372182;
				_received = _obj.getProbability(redCount, blueCount); break;
			}
			/*case 5:
			{
				int redCount = ;
				int blueCount = ;
				_expected = ;
				_received = _obj.getProbability(redCount, blueCount); break;
			}*/
			/*case 6:
			{
				int redCount = ;
				int blueCount = ;
				_expected = ;
				_received = _obj.getProbability(redCount, blueCount); break;
			}*/
			/*case 7:
			{
				int redCount = ;
				int blueCount = ;
				_expected = ;
				_received = _obj.getProbability(redCount, blueCount); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
