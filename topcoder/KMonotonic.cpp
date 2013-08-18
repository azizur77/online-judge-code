#line 2 "KMonotonic.cpp"
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

int N;
vi seq;
map<int, int> dp[55][55][2];

int solve(int pos, int kleft, int last, int lval) {
	if (N < 5) printf("%d %d %d %d\n", pos, kleft, last, lval);
	if (pos == N && kleft == 0) return 0;
	else if (pos == N) return INF;

	if (dp[pos][kleft][last].find(lval) != dp[pos][kleft][last].end()) {
		return dp[pos][kleft][last][lval];
	}

	int res = INF;

	// try continuing prev sequence
	if (last == 0 && seq[pos] > lval )
		res = min(res, solve(pos+1, kleft, last, seq[pos]));
	else if (last == 1 && seq[pos] < lval )
		res = min(res, solve(pos+1, kleft, last, seq[pos]));

	// change ele to continue seq
	if (last == 0 && seq[pos] <= lval )
		res = min(res, lval+1 - seq[pos] + solve(pos+1, kleft, last, lval+1));
	else if (last == 1 && seq[pos] >= lval )
		res = min(res, seq[pos] - lval + 1 + solve(pos+1, kleft, last, lval-1));
	
	if (kleft > 0) {
		// start inc seq
		if (last == 0 && seq[pos] > lval) FOR(i, 1, N)
			res = min(res, seq[pos] - lval + i + solve(pos+1, kleft-1, 0, lval-i));
		else if (last == 1 && seq[pos] < lval) FOR(i, 1, N)
			res = min(res, lval+i - seq[pos] + solve(pos+1, kleft-1, 0, lval+i));
		else FOR(i, -N, N)
			res = min(res, abs(i) + solve(pos+1, kleft-1, 0, seq[pos]-i));
		// start dec seq
		if (last == 0 && seq[pos] > lval) FOR(i, 1, N)
			res = min(res, seq[pos] - lval + i + solve(pos+1, kleft-1, 1, lval-i));
		else if (last == 1 && seq[pos] < lval) FOR(i, 1, N)
			res = min(res, lval+i - seq[pos] + solve(pos+1, kleft-1, 1, lval+i));
		else FOR(i, -N, N)
			res = min(res, abs(i) + solve(pos+1, kleft-1, 1, seq[pos]+i));
	}

	dp[pos][kleft][last][lval] = res;

	return res;

}

class KMonotonic {
	public:
	int transform(vector <int> sequence, int k) {
		N = sz(sequence);
		seq = sequence;
		int res = solve(0, k, -1, 0);
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
		cout << "Testing KMonotonic (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1376811706;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		KMonotonic _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sequence[] = {1,1,1,1};
				int k = 1;
				_expected = 4;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}
			case 1:
			{
				int sequence[] = {1,1,1,1};
				int k = 2;
				_expected = 2;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}
			case 2:
			{
				int sequence[] = {1,1,1,1};
				int k = 4;
				_expected = 0;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}
			case 3:
			{
				int sequence[] = {1,2,3,3,2,1};
				int k = 1;
				_expected = 9;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}
			case 4:
			{
				int sequence[] = {1,3,2,3,2,4};
				int k = 1;
				_expected = 6;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}
			case 5:
			{
				int sequence[] = {1,10,4,2,5,1,3,2,4,6,1};
				int k = 3;
				_expected = 11;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}
			case 6:
			{
				int sequence[] = {-913,-4158,-146,-2625,-2926,3071,297,4049,-4566,3581,-2070,-1794,1953,4434,4351,-710,-3124,2148,1192,1802,644};
				int k = 8;
				_expected = 611;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}
			/*case 7:
			{
				int sequence[] = ;
				int k = ;
				_expected = ;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}*/
			/*case 8:
			{
				int sequence[] = ;
				int k = ;
				_expected = ;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
			}*/
			/*case 9:
			{
				int sequence[] = ;
				int k = ;
				_expected = ;
				_received = _obj.transform(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int)), k); break;
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
