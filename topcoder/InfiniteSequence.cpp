#line 2 "InfiniteSequence.cpp"
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
#include <map>
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

map<ll, ll> memo;

int P, Q;

ll solve(ll n) {
	if (n == 0) return 1LL;
	if (memo.find(n) != memo.end()) return memo[n];
	ll ans = solve((n/P)) + solve((n/Q));
	memo[n] = ans;
	return ans;
}

class InfiniteSequence {
	public:
	long long calc(long long n, int p, int q) {
		P = p; Q = q;
		return solve(n);
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
		cout << "Testing InfiniteSequence (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363351812;
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
		InfiniteSequence _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 0LL;
				int p = 2;
				int q = 3;
				_expected = 1LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 1:
			{
				long long n = 7LL;
				int p = 2;
				int q = 3;
				_expected = 7LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 2:
			{
				long long n = 10000000LL;
				int p = 3;
				int q = 3;
				_expected = 32768LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 3:
			{
				long long n = 256LL;
				int p = 2;
				int q = 4;
				_expected = 89LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 4:
			{
				long long n = 1LL;
				int p = 1000000;
				int q = 1000000;
				_expected = 2LL;
				_received = _obj.calc(n, p, q); break;
			}
			/*case 5:
			{
				long long n = LL;
				int p = ;
				int q = ;
				_expected = LL;
				_received = _obj.calc(n, p, q); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				int p = ;
				int q = ;
				_expected = LL;
				_received = _obj.calc(n, p, q); break;
			}*/
			/*case 7:
			{
				long long n = LL;
				int p = ;
				int q = ;
				_expected = LL;
				_received = _obj.calc(n, p, q); break;
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
