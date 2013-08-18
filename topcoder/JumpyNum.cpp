#line 2 "JumpyNum.cpp"
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
#include <map>
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

map<ii, int> M;

int solve(int bound, int last) {
	if (bound == 0 || last > bound) return 0;
	if (M.find(ii(bound, last)) != M.end()) 
		return M[ii(bound, last)];
	int ans = (last != 0);

	for(int i=0; i <= 9; i++)
		if (abs(i - last) >= 2) {
			ans += solve((bound - last) / 10, i);
		}
	M[ii(bound, last)] = ans;
	return ans;
}

int calc(int num) {
	int ans = 0;
	for(int i=0; i <= 9; i++) {
		ans += solve(num, i);
	}
	return ans;
}

class JumpyNum {
	public:
	int howMany(int low, int high) {
		return calc(high) - calc(low-1);
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
		cout << "Testing JumpyNum (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1373128409;
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
		JumpyNum _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int low = 1;
				int high = 10;
				_expected = 9;
				_received = _obj.howMany(low, high); break;
			}
			case 1:
			{
				int low = 9;
				int high = 23;
				_expected = 9;
				_received = _obj.howMany(low, high); break;
			}
			case 2:
			{
				int low = 2000000000;
				int high = 2000000000;
				_expected = 0;
				_received = _obj.howMany(low, high); break;
			}
			case 3:
			{
				int low = 8000;
				int high = 20934;
				_expected = 3766;
				_received = _obj.howMany(low, high); break;
			}
			/*case 4:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.howMany(low, high); break;
			}*/
			/*case 5:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.howMany(low, high); break;
			}*/
			/*case 6:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.howMany(low, high); break;
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
