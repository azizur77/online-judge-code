#line 2 "ContiguousCacheEasy.cpp"
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


class ContiguousCacheEasy {
	public:
	int bytesRead(int n, int k, vector <int> addresses) {
		int currentRange = 0, bytes = 0;
		for(int i=0; i < sz(addresses); i++) {
			int oldRange = currentRange;
			if (addresses[i] >= currentRange + k) {
				currentRange = max(0, addresses[i] - k + 1);
			} else if (addresses[i] < currentRange) {
				currentRange = addresses[i];
			}
			bytes += min(k, abs(currentRange - oldRange));
		}
		return bytes;
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
		cout << "Testing ContiguousCacheEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362973744;
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
		ContiguousCacheEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 100;
				int k = 5;
				int addresses[] = {6, 0, 3, 20, 22, 16};
				_expected = 13;
				_received = _obj.bytesRead(n, k, vector <int>(addresses, addresses+sizeof(addresses)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 100;
				int k = 1;
				int addresses[] = {0, 4, 6, 6, 4, 10};
				_expected = 4;
				_received = _obj.bytesRead(n, k, vector <int>(addresses, addresses+sizeof(addresses)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 1000;
				int k = 999;
				int addresses[] = {0, 4, 123, 987, 999, 500, 0};
				_expected = 2;
				_received = _obj.bytesRead(n, k, vector <int>(addresses, addresses+sizeof(addresses)/sizeof(int))); break;
			}
			/*case 3:
			{
				int n = ;
				int k = ;
				int addresses[] = ;
				_expected = ;
				_received = _obj.bytesRead(n, k, vector <int>(addresses, addresses+sizeof(addresses)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int n = ;
				int k = ;
				int addresses[] = ;
				_expected = ;
				_received = _obj.bytesRead(n, k, vector <int>(addresses, addresses+sizeof(addresses)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int k = ;
				int addresses[] = ;
				_expected = ;
				_received = _obj.bytesRead(n, k, vector <int>(addresses, addresses+sizeof(addresses)/sizeof(int))); break;
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
