#line 2 "FIELDDiagrams.cpp"
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


ll memo[31][31];

class FIELDDiagrams {
	public:
	ll solve(ll f, ll k) {
		if (f == 0 || k == 1) return 1ll;
		if (memo[f][k] != -1) return memo[f][k];

		memo[f][k] = 0;
		for(int i=0; i <= min(f, k-1); i++) memo[f][k] += solve(i, k-1);
		return memo[f][k];	
	}
	long long countDiagrams(int fieldOrder) {
		fill(memo, -1);
		ll res = 0;
		for(int i=1; i <= fieldOrder; i++) {
			res += solve(i, fieldOrder);
		}
		return res;
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
		cout << "Testing FIELDDiagrams (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362623597;
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
		FIELDDiagrams _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int fieldOrder = 2;
				_expected = 4LL;
				_received = _obj.countDiagrams(fieldOrder); break;
			}
			case 1:
			{
				int fieldOrder = 3;
				_expected = 13LL;
				_received = _obj.countDiagrams(fieldOrder); break;
			}
			case 2:
			{
				int fieldOrder = 5;
				_expected = 131LL;
				_received = _obj.countDiagrams(fieldOrder); break;
			}
			/*case 3:
			{
				int fieldOrder = ;
				_expected = LL;
				_received = _obj.countDiagrams(fieldOrder); break;
			}*/
			/*case 4:
			{
				int fieldOrder = ;
				_expected = LL;
				_received = _obj.countDiagrams(fieldOrder); break;
			}*/
			/*case 5:
			{
				int fieldOrder = ;
				_expected = LL;
				_received = _obj.countDiagrams(fieldOrder); break;
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
