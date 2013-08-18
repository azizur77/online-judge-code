#line 2 "Conditional.cpp"
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

double dp[2501][51][2], num_dice, side, lwr, target;

double solve(int sum, int dice_left, int flag) {
	if (dp[sum][dice_left][flag] >= 0) return dp[sum][dice_left][flag];

	double ans = (flag && sum >= target && dice_left == 0);

	if (dice_left > 0) {
		for(int i=1; i <= side; i++) {
			int new_flag = flag || (i == lwr);
			ans += solve(sum + i, dice_left - 1, new_flag);
		}
	}

	dp[sum][dice_left][flag] = ans;

	return ans;
}

class Conditional {
	public:

	double probability(int nDice, int maxSide, int v, int theSum) {
		double denominator = (1.0 - pow((maxSide - 1.0) / maxSide, nDice)) * pow(maxSide, nDice);
		for(int i=0; i < 2501; i++)
			for(int j=0; j < 51; j++)
				for(int k=0; k < 2; k++)
					dp[i][j][k] = -1;

		target = theSum;
		side = maxSide;
		lwr = v;
		num_dice = nDice;

		double numer = solve(0, nDice, 0);

		return numer / denominator;
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
		cout << "Testing Conditional (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1375113578;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Conditional _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int nDice = 2;
				int maxSide = 6;
				int v = 6;
				int theSum = 12;
				_expected = 0.09090909090909091;
				_received = _obj.probability(nDice, maxSide, v, theSum); break;
			}
			case 1:
			{
				int nDice = 2;
				int maxSide = 6;
				int v = 6;
				int theSum = 6;
				_expected = 1.0;
				_received = _obj.probability(nDice, maxSide, v, theSum); break;
			}
			case 2:
			{
				int nDice = 1;
				int maxSide = 9;
				int v = 3;
				int theSum = 3;
				_expected = 1.0;
				_received = _obj.probability(nDice, maxSide, v, theSum); break;
			}
			case 3:
			{
				int nDice = 2;
				int maxSide = 3;
				int v = 2;
				int theSum = 4;
				_expected = 0.6;
				_received = _obj.probability(nDice, maxSide, v, theSum); break;
			}
			/*case 4:
			{
				int nDice = ;
				int maxSide = ;
				int v = ;
				int theSum = ;
				_expected = ;
				_received = _obj.probability(nDice, maxSide, v, theSum); break;
			}*/
			/*case 5:
			{
				int nDice = ;
				int maxSide = ;
				int v = ;
				int theSum = ;
				_expected = ;
				_received = _obj.probability(nDice, maxSide, v, theSum); break;
			}*/
			/*case 6:
			{
				int nDice = ;
				int maxSide = ;
				int v = ;
				int theSum = ;
				_expected = ;
				_received = _obj.probability(nDice, maxSide, v, theSum); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
