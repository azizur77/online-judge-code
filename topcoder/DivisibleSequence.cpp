#line 2 "DivisibleSequence.cpp"
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
#define INF ((int)1e9)
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

int MOD = INF + 9;

ll ffp(ll H, ll fk) {
	ll res = 1;
	for(ll i = H; i >= (H-fk) && i > 0; i--)
		res = (res * i) % MOD;
	return res;
}

int count_subfactors(int N) {
	set<int> factors;
	for(int i=1; i <= sqrt(N); i++) {
		if (N % i == 0) {
			factors.insert(i);
			factors.insert(N/i);
		}
	}
	return sz(factors);
}

ll choose(ll N, ll R) {
	ll res = 1;
	for(ll i=1; i <= R; i++)
		res = res * ((N-i+1) / i);
	return res % MOD;
}

class DivisibleSequence {
	public:
	int count(int N, int H) {
		set<int> factors;
		for(int i=1; i <= sqrt(N); i++)	
			if (N % i == 0) {
				factors.insert(i);
				factors.insert(N/i);
			}
		set<int>::iterator it;
		ll nways = 0;
		for(it = factors.begin(); it != factors.end(); it++) {
			int fk = count_subfactors((*it));
			if (H > fk) {
				nways = (nways + ffp(H, fk)) % MOD;
			}
			else {
				nways = (nways + ffp(H, fk) * choose(fk, H)) % MOD;
			}
		}

		return (int) (nways % MOD);
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
		cout << "Testing DivisibleSequence (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356020821;
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
		DivisibleSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int H = 3;
				_expected = 3;
				_received = _obj.count(N, H); break;
			}
			case 1:
			{
				int N = 6;
				int H = 3;
				_expected = 9;
				_received = _obj.count(N, H); break;
			}
			case 2:
			{
				int N = 10;
				int H = 2;
				_expected = 4;
				_received = _obj.count(N, H); break;
			}
			case 3:
			{
				int N = 1;
				int H = 10000;
				_expected = 1;
				_received = _obj.count(N, H); break;
			}
			case 4:
			{
				int N = 30;
				int H = 4;
				_expected = 64;
				_received = _obj.count(N, H); break;
			}
			case 5:
			{
				int N = 25883;
				int H = 100000;
				_expected = 991000009;
				_received = _obj.count(N, H); break;
			}
			/*case 6:
			{
				int N = ;
				int H = ;
				_expected = ;
				_received = _obj.count(N, H); break;
			}*/
			/*case 7:
			{
				int N = ;
				int H = ;
				_expected = ;
				_received = _obj.count(N, H); break;
			}*/
			/*case 8:
			{
				int N = ;
				int H = ;
				_expected = ;
				_received = _obj.count(N, H); break;
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
