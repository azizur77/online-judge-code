#line 2 "TheArray.cpp"
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


class TheArray {
	public:
	int find(int n, int d, int first, int last) {
		int a = min(first, last);
		int b = max(first, last);
		
		int ans = a;
		int MAX = a;

		for(int i=0; i < n-2; i++) {
			if (abs(b - (ans + d)) <= (n-2-i) * d) ans += d;
			else {
				while(abs(b - ans) < (n-2-i) * d) ans++;
			}
			MAX = max(MAX, ans);
		}
		MAX = max(MAX, b);
		return MAX;
		
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
		cout << "Testing TheArray (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362849012;
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
		TheArray _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int d = 5;
				int first = 2;
				int last = 4;
				_expected = 7;
				_received = _obj.find(n, d, first, last); break;
			}
			case 1:
			{
				int n = 10;
				int d = 100;
				int first = 999;
				int last = 100;
				_expected = 999;
				_received = _obj.find(n, d, first, last); break;
			}
			case 2:
			{
				int n = 1000000;
				int d = 0;
				int first = 474;
				int last = 474;
				_expected = 474;
				_received = _obj.find(n, d, first, last); break;
			}
			case 3:
			{
				int n = 97;
				int d = 53;
				int first = -92;
				int last = 441;
				_expected = 2717;
				_received = _obj.find(n, d, first, last); break;
			}
			case 4:
			{
				int n = 99;
				int d = 3;
				int first = -743;
				int last = -619;
				_expected = -535;
				_received = _obj.find(n, d, first, last); break;
			}
			/*case 5:
			{
				int n = ;
				int d = ;
				int first = ;
				int last = ;
				_expected = ;
				_received = _obj.find(n, d, first, last); break;
			}*/
			/*case 6:
			{
				int n = ;
				int d = ;
				int first = ;
				int last = ;
				_expected = ;
				_received = _obj.find(n, d, first, last); break;
			}*/
			/*case 7:
			{
				int n = ;
				int d = ;
				int first = ;
				int last = ;
				_expected = ;
				_received = _obj.find(n, d, first, last); break;
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
