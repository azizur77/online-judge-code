#line 2 "TheOlympiadInInformatics.cpp"
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

vi S;
int _k;

ll solve(int mid) {
	ll res = 0;
	for(int i=0; i < sz(S); i++) 
		res += ll(S[i]) / (mid+1);
	return res;
}

class TheOlympiadInInformatics {
	public:
	int find(vector <int> sums, int k) {
		S = sums;
		ll low = -1, high, p, mm, k1 = k;

		high = (mm = *max_element(all(sums))) + 1;

		// Invariant A[x >= hi] < k

		while ( high - low > 1 ) 
		{
			p = (low + high) / 2;
			if (solve(p) > k1) low = p;
			else high = p;
		}

		// if ( low == -1 || solve(low) != k )
			// return high;

		return high;

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
		cout << "Testing TheOlympiadInInformatics (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362850595;
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
		TheOlympiadInInformatics _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sums[] = {67, 36, 0, 39, 55};
				int k = 7;
				_expected = 19;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}
			case 1:
			{
				int sums[] = {4, 7};
				int k = 2;
				_expected = 3;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}
			case 2:
			{
				int sums[] = {1000000000, 1000000000, 1000000000};
				int k = 1000000000;
				_expected = 0;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}
			case 3:
			{
				int sums[] = {95, 23, 87, 23, 82, 78, 59, 44, 12};
				int k = 70;
				_expected = 6;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}
			/*case 4:
			{
				int sums[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}*/
			/*case 5:
			{
				int sums[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int sums[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
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
