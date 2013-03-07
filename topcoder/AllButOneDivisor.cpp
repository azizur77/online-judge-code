#line 2 "AllButOneDivisor.cpp"
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


class AllButOneDivisor {
	public:
	int getMinimum(vector <int> divisors) {
		sort(all(divisors));
		int k = sz(divisors);
		if (k == 1) return -1;

		vector<int> flags(k, 1);
		vector<int> prod;

		for (int i = 0; i < k; ++i) {
			if (flags[i] == 1) {
				for (int j = i+1; j < k; ++j) 
					if (divisors[j] % divisors[i] == 0)
						flags[j] = 0;
				prod.push_back(divisors[i]);
			}
		}

		sort(all(prod));
		int p = 1;
		for(int i=0; i < sz(prod) - 1; i++) {
			p *= divisors[i];
		}
		
		return p;
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
		cout << "Testing AllButOneDivisor (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362502179;
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
		AllButOneDivisor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int divisors[] = {2,3,5};
				_expected = 6;
				_received = _obj.getMinimum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int))); break;
			}
			case 1:
			{
				int divisors[] = {2,4,3,9};
				_expected = 12;
				_received = _obj.getMinimum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int))); break;
			}
			case 2:
			{
				int divisors[] = {3,2,6};
				_expected = -1;
				_received = _obj.getMinimum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int))); break;
			}
			case 3:
			{
				int divisors[] = {6,7,8,9,10};
				_expected = 360;
				_received = _obj.getMinimum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int))); break;
			}
			case 4:
			{
				int divisors[] = {10,6,15};
				_expected = -1;
				_received = _obj.getMinimum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int))); break;
			}
			/*case 5:
			{
				int divisors[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int divisors[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int divisors[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int))); break;
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
