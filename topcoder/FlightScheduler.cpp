#line 2 "FlightScheduler.cpp"
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


class FlightScheduler {
	public:
	double minimizeFuel(int distance, int K, int emptyMass, int takeoffFuel) {
		
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
		cout << "Testing FlightScheduler (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361462878;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FlightScheduler _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int distance = 40000;
				int K = 100000;
				int emptyMass = 150000;
				int takeoffFuel = 5000;
				_expected = 76420.82744805096;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			case 1:
			{
				int distance = 40000;
				int K = 55000;
				int emptyMass = 150000;
				int takeoffFuel = 5000;
				_expected = 138450.61724934017;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			case 2:
			{
				int distance = 1000;
				int K = 500;
				int emptyMass = 1000;
				int takeoffFuel = 50;
				_expected = 2664.9853821314487;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			case 3:
			{
				int distance = 10000;
				int K = 100;
				int emptyMass = 200;
				int takeoffFuel = 5;
				_expected = 24635.869665316768;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			case 4:
			{
				int distance = 140000;
				int K = 4;
				int emptyMass = 10000;
				int takeoffFuel = 10;
				_expected = 3.6576871282155204E8;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}
			/*case 5:
			{
				int distance = ;
				int K = ;
				int emptyMass = ;
				int takeoffFuel = ;
				_expected = ;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}*/
			/*case 6:
			{
				int distance = ;
				int K = ;
				int emptyMass = ;
				int takeoffFuel = ;
				_expected = ;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
			}*/
			/*case 7:
			{
				int distance = ;
				int K = ;
				int emptyMass = ;
				int takeoffFuel = ;
				_expected = ;
				_received = _obj.minimizeFuel(distance, K, emptyMass, takeoffFuel); break;
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
