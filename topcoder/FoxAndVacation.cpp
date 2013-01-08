#line 2 "FoxAndVacation.cpp"
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


class FoxAndVacation {
	public:
	int maxCities(int total, vector <int> d) {
		sort(all(d));
		int i = 0, days=0;
		while (total > 0 && i < sz(d)) {
			total -= d[i];
			if (total >= 0) days++;
			i++;
		}
		return days;
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
		cout << "Testing FoxAndVacation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1353427806;
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
		FoxAndVacation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int total = 5;
				int d[] = {2,2,2};
				_expected = 2;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int total = 5;
				int d[] = {5,6,1};
				_expected = 1;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int total = 5;
				int d[] = {6,6,6};
				_expected = 0;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int total = 6;
				int d[] = {1,1,1,1,1};
				_expected = 5;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int total = 10;
				int d[] = {7,1,5,6,1,3,4};
				_expected = 4;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 5:
			{
				int total = 50;
				int d[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
				_expected = 9;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 6:
			{
				int total = 21;
				int d[] = {14,2,16,9,9,5,5,23,25,20,8,25,6,12,3,2,4,5,10,14,19,12,25,15,14};
				_expected = 6;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 7:
			{
				int total = ;
				int d[] = ;
				_expected = ;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int total = ;
				int d[] = ;
				_expected = ;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int total = ;
				int d[] = ;
				_expected = ;
				_received = _obj.maxCities(total, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
