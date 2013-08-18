#line 2 "TeamContestEasy.cpp"
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


class TeamContestEasy {
	public:
	int worstRank(vector <int> strength) {
		int myStrength = strength[0] + strength[1] + strength[2] - min(min(strength[0], strength[1]), strength[2]);
		int rank = 1;
		bool used[51];
		fill(used, 0);
		int maxrank = sz(strength) / 3;

		sort(strength.begin() + 3, strength.end());
		reverse(strength.begin() + 3, strength.end());
		int ctr = sz(strength) - 3;
		for(int i=3; i < strength.size(); i++) {
			int idx = -1, best = INF;
			ctr--;
			for(int j=i+1; j < strength.size(); j++) {
				if (!used[j] && (strength[i] + strength[j] > myStrength) && strength[j] < best) {
					best = strength[j];
					idx = j;
				}
			}
			if (idx != -1) {
				rank++;
				used[i] = used[idx] = 1;
				ctr -= 2;
				if (ctr <= 0) break;
			}
		}

		return min(maxrank, rank);	
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
		cout << "Testing TeamContestEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363310015;
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
		TeamContestEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int strength[] = {1, 1, 1, 5, 7, 3, 5, 7, 3};
				_expected = 2;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 1:
			{
				int strength[] = {5, 7, 3};
				_expected = 1;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 2:
			{
				int strength[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 1;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 3:
			{
				int strength[] = {2,2,1,1,3,1,3,2,1,3,1,2,1,2,1};
				_expected = 4;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 4:
			{
				int strength[] = {45,72,10,42,67,51,33,21,8,51,17,72};
				_expected = 3;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 5:
			{
				int strength[] = {570466,958327,816467,17,403,953808,734850,5824,917784,921731,161921,1734,823437,3218,81,932681,2704,981643,1232,475,873323,6558,45660,1813,4714,224,
				                 32301,28081,6728,17055,561,15146,842613,5559,1860,783,989,2811,20664,112531,1933,866794,805528,53821,2465,137385,39,2007};
				_expected = 6;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 6:
			{
				int strength[] = {610297,849870,523999,6557,976530,731458,7404,795100,147040,110947,159692,40785,4949,2903,1688,37278,620703,28156,16823,1159,12132,971379,5916,1159,988589,
				                 12215,133,1490,911360,920059,544070,40249,514852,852,745070,1105,715897,714696,589133,698317,5683,631612,16453,101000,764881,101,2053,754661};
				_expected = 10;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			/*case 7:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.worstRank(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
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
