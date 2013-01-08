#line 2 "BadNeighbors.cpp"
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

vi don;
int N, memo[2][2][55];

int solve(bool first, bool prev, int idx) {
	if (idx == N-1) {
		return (first || prev) ? 0 : don[idx];
	}

	if (memo[first][prev][idx] != -1) return memo[first][prev][idx];

	int ret;

	if (prev) {
		ret = solve(first, false, idx+1);
	} else {
		ret = max(solve(first, false, idx+1), 
			don[idx] + solve((idx == 0) || first, true, idx+1)); 
	}

	return memo[first][prev][idx] = ret;
}

class BadNeighbors {
	public:
	int maxDonations(vector <int> donations) {
		don = donations;
		fill(memo, -1);
		N = sz(don);
		return solve(false, false, 0);
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
		cout << "Testing BadNeighbors (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352660140;
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
		BadNeighbors _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int donations[] =  { 10, 3, 2, 5, 7, 8 };
				_expected = 19;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			case 1:
			{
				int donations[] = { 11, 15 };
				_expected = 15;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			case 2:
			{
				int donations[] = { 7, 7, 7, 7, 7, 7, 7 };
				_expected = 21;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			case 3:
			{
				int donations[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
				_expected = 16;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			case 4:
			{
				int donations[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
				                    6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
				                    52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
				_expected = 2926;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}
			/*case 5:
			{
				int donations[] = ;
				_expected = ;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int donations[] = ;
				_expected = ;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int donations[] = ;
				_expected = ;
				_received = _obj.maxDonations(vector <int>(donations, donations+sizeof(donations)/sizeof(int))); break;
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
