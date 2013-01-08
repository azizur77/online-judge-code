#line 2 "Jewelry.cpp"
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

ll tillEnd[31][30001], tillEndPrev[30001], fromZero[31][30001];


class Jewelry {
	public:
	long long howMany(vector <int> values) {
		sort(all(values));
		fill(tillEnd, 0);
		fill(fromZero, 0);
		fill(tillEndPrev, 0);
		int n = sz(values);
		int mval = values[n-1];

		// Fill fromZero
		fromZero[0][0] = 1;
		for (int i=0; i < n; i++)
			for (int j=1; j <= n * mval; j++)
				fromZero[i][j] = fromZero[i-1][j] +
					((j >= values[i]) ? fromZero[i-1][j - values[i]] : 0);

		// Fill tillEnd
		for(int i=1; i < n; i++) {
			fill(tillEnd[i], 0);
			fill(tillEndPrev, 0);
			tillEndPrev[0] = 1;
			tillEnd[i][0] = 1;
			for(int j=i; j < n; j++) {
				fill(tillEnd[i], 0);
				for(int k=0; k <= n * mval; k++) {
					tillEnd[i][k] = tillEndPrev[k]; 
					if (k >= values[j])
						tillEnd[i][k] += tillEndPrev[k - values[j]];
				}
				memcpy(tillEndPrev, tillEnd[i], sizeof(tillEnd[i]));
			}	
		} 

		ll nways = 0;
		for(int i = 0; i < n; i++) {
			int j = i + 1;
			while(j < n-1 && values[j] == values[i]) j++;
			if (values[j] == values[i]) continue;
			for(int k=0; k <= n * mval; k++) {
				nways += (fromZero[i][k] * tillEnd[j][k]);
			}
		}
		return nways;
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
		cout << "Testing Jewelry (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352713810;
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
		Jewelry _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int values[] = {1,2,5,3,4,5};
				_expected = 9LL;
				_received = _obj.howMany(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 1:
			{
				int values[] = {1000,1000,1000,1000,1000,
				                1000,1000,1000,1000,1000,
				                1000,1000,1000,1000,1000,
				                1000,1000,1000,1000,1000,
				                1000,1000,1000,1000,1000,
				                1000,1000,1000,1000,1000};
				_expected = 18252025766940LL;
				_received = _obj.howMany(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 2:
			{
				int values[] = {1,2,3,4,5};
				_expected = 4LL;
				_received = _obj.howMany(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 3:
			{
				int values[] = {7,7,8,9,10,11,1,2,2,3,4,5,6};
				_expected = 607LL;
				_received = _obj.howMany(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 4:
			{
				int values[] = {123,217,661,678,796,964,54,111,417,526,917,923};
				_expected = 0LL;
				_received = _obj.howMany(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			/*case 5:
			{
				int values[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int values[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int values[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
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
