#line 2 "PasswordXGuessing.cpp"
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


class PasswordXGuessing {
	public:
	long long howMany(vector <string> guesses) {
		
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
		cout << "Testing PasswordXGuessing (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362845182;
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
		PasswordXGuessing _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string guesses[] = {"58", "47"};
				_expected = 2LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 1:
			{
				string guesses[] = {"539", "540", "541"};
				_expected = 1LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 2:
			{
				string guesses[] = {"12", "34", "56", "78"};
				_expected = 0LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 3:
			{
				string guesses[] = {"2", "3", "5"};
				_expected = 7LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 4:
			{
				string guesses[] = {"4747", "4747", "4747", "4747"};
				_expected = 36LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			/*case 5:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
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
