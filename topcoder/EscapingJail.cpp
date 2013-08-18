#line 2 "EscapingJail.cpp"
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
#define INF (int)1e7
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



int dist(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'z')
		return 10 + (c - 'a');
	else if (c >= 'A' && c <= 'Z')
		return 36 + (c - 'A');
	else
		return INF;
}

class EscapingJail {
	public:
	int getMaxDistance(vector <string> chain) {
		int length = chain.size();
		int floyd[55][55];
		for(int i=0; i < length; i++)
			for(int j=0; j < length; j++)
				floyd[i][j] = dist(chain[i][j]);

		for(int k=0; k < length; k++)
			for(int i=0; i < length; i++)
				for(int j=0; j < length; j++)
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);


		int mdist = 0;

		for(int i=0; i < length; i++)
			for(int j=0; j < length; j++)
				if (i != j) {
					mdist = max(mdist, floyd[i][j]);
					printf("%d %d : %d\n", i, j, floyd[i][j]);
				}

		if (mdist > INF/2)
			mdist = -1;

		return mdist;

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
		cout << "Testing EscapingJail (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1374081971;
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
		EscapingJail _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chain[] = {"0568",
				                  "5094",
				                  "6903",
				                  "8430"};
				_expected = 8;
				_received = _obj.getMaxDistance(vector <string>(chain, chain+sizeof(chain)/sizeof(string))); break;
			}
			case 1:
			{
				string chain[] = {"0 ",
				                  " 0"};
				_expected = -1;
				_received = _obj.getMaxDistance(vector <string>(chain, chain+sizeof(chain)/sizeof(string))); break;
			}
			case 2:
			{
				string chain[] = {"0AxHH190",
				                  "A00f3AAA",
				                  "x00     ",
				                  "Hf 0  x ",
				                  "H3  0   ",
				                  "1A   0  ",
				                  "9A x  0Z",
				                  "0A    Z0"};
				_expected = 43;
				_received = _obj.getMaxDistance(vector <string>(chain, chain+sizeof(chain)/sizeof(string))); break;
			}
			case 3:
			{
				string chain[] = {"00",
				                  "00"};
				_expected = 0;
				_received = _obj.getMaxDistance(vector <string>(chain, chain+sizeof(chain)/sizeof(string))); break;
			}
			/*case 4:
			{
				string chain[] = ;
				_expected = ;
				_received = _obj.getMaxDistance(vector <string>(chain, chain+sizeof(chain)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string chain[] = ;
				_expected = ;
				_received = _obj.getMaxDistance(vector <string>(chain, chain+sizeof(chain)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string chain[] = ;
				_expected = ;
				_received = _obj.getMaxDistance(vector <string>(chain, chain+sizeof(chain)/sizeof(string))); break;
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
