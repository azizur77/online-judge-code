#line 2 "TheDeviceDiv2.cpp"
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


class TheDeviceDiv2 {
	public:
	string identify(vector <string> plates) {
		if (sz(plates) < 3) return "NO";

		bool flag = true;
		for(int j=0; j < sz(plates[0]); j++) {
			int ones=0, zeros=0;
			for(int i=0; i < sz(plates); i++) {
				if (plates[i][j] == '0') zeros++;
				else if (plates[i][j] == '1') ones++;
			}
			if (zeros < 1 || ones < 2) {
				flag = false;
				break;
			}
		}
		return (flag) ? "YES" : "NO";
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
		cout << "Testing TheDeviceDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1360203574;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheDeviceDiv2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string plates[] = {"010",
				                   "011",
				                   "000"};
				_expected = "NO";
				_received = _obj.identify(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			case 1:
			{
				string plates[] = {"1",
				                   "0",
				                   "1",
				                   "0"};
				_expected = "YES";
				_received = _obj.identify(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			case 2:
			{
				string plates[] = {"11111"};
				_expected = "NO";
				_received = _obj.identify(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			case 3:
			{
				string plates[] = {"0110011",
				                   "0101001",
				                   "1111010",
				                   "1010010"};
				_expected = "NO";
				_received = _obj.identify(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			case 4:
			{
				string plates[] = {"101001011",
				                   "011011010",
				                   "010110010",
				                   "111010100",
				                   "111111111"};
				_expected = "YES";
				_received = _obj.identify(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}
			/*case 5:
			{
				string plates[] = ;
				_expected = ;
				_received = _obj.identify(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string plates[] = ;
				_expected = ;
				_received = _obj.identify(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string plates[] = ;
				_expected = ;
				_received = _obj.identify(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
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
