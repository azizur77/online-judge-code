#line 2 "GrabbingTaxi.cpp"
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


class GrabbingTaxi {
	public:
	int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime) {
		vector<int> times;
		times.push_back(abs(gX)*walkTime + abs(gY)*walkTime);
		for(int i=0; i < sz(tXs); i++)
			times.push_back(walkTime*(abs(tXs[i]) + abs(tYs[i])) + 
				taxiTime*(abs(gX - tXs[i]) + abs(gY - tYs[i])) );
		return *min_element(all(times));
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
		cout << "Testing GrabbingTaxi (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362585610;
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
		GrabbingTaxi _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int tXs[] = {};
				int tYs[] = {};
				int gX = 3;
				int gY = 2;
				int walkTime = 10;
				int taxiTime = 2;
				_expected = 50;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			case 1:
			{
				int tXs[] = {-2, -2};
				int tYs[] = {0, -2};
				int gX = -4;
				int gY = -2;
				int walkTime = 15;
				int taxiTime = 3;
				_expected = 42;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			case 2:
			{
				int tXs[] = {3};
				int tYs[] = {0};
				int gX = 5;
				int gY = 0;
				int walkTime = 10;
				int taxiTime = 20;
				_expected = 50;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			case 3:
			{
				int tXs[] = {34, -12, 1, 0, 21, -43, -98, 11, 86, -31};
				int tYs[] = {11, 5, -68, 69, -78, -49, -36, -2, 1, 70};
				int gX = -97;
				int gY = -39;
				int walkTime = 47;
				int taxiTime = 13;
				_expected = 2476;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			case 4:
			{
				int tXs[] = {82, -60, 57, 98, 30, -67, 84, -42, -100, 62};
				int tYs[] = {-7, 90, 53, -56, -15, -87, 22, -3, -61, -30};
				int gX = 21;
				int gY = 15;
				int walkTime = 53;
				int taxiTime = 2;
				_expected = 1908;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}
			/*case 5:
			{
				int tXs[] = ;
				int tYs[] = ;
				int gX = ;
				int gY = ;
				int walkTime = ;
				int taxiTime = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}*/
			/*case 6:
			{
				int tXs[] = ;
				int tYs[] = ;
				int gX = ;
				int gY = ;
				int walkTime = ;
				int taxiTime = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
			}*/
			/*case 7:
			{
				int tXs[] = ;
				int tYs[] = ;
				int gX = ;
				int gY = ;
				int walkTime = ;
				int taxiTime = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(tXs, tXs+sizeof(tXs)/sizeof(int)), vector <int>(tYs, tYs+sizeof(tYs)/sizeof(int)), gX, gY, walkTime, taxiTime); break;
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
