#line 2 "TeleportsNetwork.cpp"
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


class TeleportsNetwork {
	public:
	int distribute(int teleportCount, vector <int> citiesX, vector <int> citiesY) {
		
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
		cout << "Testing TeleportsNetwork (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362821787;
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
		TeleportsNetwork _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int teleportCount = 2;
				int citiesX[] = {0,1,1,1,2,2};
				int citiesY[] = {1,0,1,2,0,2};
				_expected = 1;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			case 1:
			{
				int teleportCount = 1;
				int citiesX[] = {0,1,1,1,2,2};
				int citiesY[] = {1,0,1,2,0,2};
				_expected = 2;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			case 2:
			{
				int teleportCount = 0;
				int citiesX[] = {0,1,1,1,2,3,3,4};
				int citiesY[] = {1,1,2,0,0,0,2,1};
				_expected = 5;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			case 3:
			{
				int teleportCount = 1;
				int citiesX[] = {0,1,2,3,4};
				int citiesY[] = {0,0,0,0,0};
				_expected = 1;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			case 4:
			{
				int teleportCount = 4;
				int citiesX[] = {64,200,384,294,175,107,303,374,224,220,223,99,442};
				int citiesY[] = {79,161,83,281,344,217,184,336,431,262,75,474,257};
				_expected = 1;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			/*case 5:
			{
				int teleportCount = ;
				int citiesX[] = ;
				int citiesY[] = ;
				_expected = ;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int teleportCount = ;
				int citiesX[] = ;
				int citiesY[] = ;
				_expected = ;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int teleportCount = ;
				int citiesX[] = ;
				int citiesY[] = ;
				_expected = ;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
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
