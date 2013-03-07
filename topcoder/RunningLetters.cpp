#line 2 "RunningLetters.cpp"
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


class RunningLetters {
	public:
	int newsLength(vector <string> running) {
		
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
		cout << "Testing RunningLetters (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362626619;
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
		RunningLetters _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string running[] = {"3 abc 1 ab"};
				_expected = 3;
				_received = _obj.newsLength(vector <string>(running, running+sizeof(running)/sizeof(string))); break;
			}
			case 1:
			{
				string running[] = {"1 babaaba"};
				_expected = 5;
				_received = _obj.newsLength(vector <string>(running, running+sizeof(running)/sizeof(string))); break;
			}
			case 2:
			{
				string running[] = {"1 ba 1 c 1 bacba 3 cba"};
				_expected = 3;
				_received = _obj.newsLength(vector <string>(running, running+sizeof(running)/sizeof(string))); break;
			}
			case 3:
			{
				string running[] = {"42 runningletters 42 runningletters 1 running"};
				_expected = 14;
				_received = _obj.newsLength(vector <string>(running, running+sizeof(running)/sizeof(string))); break;
			}
			case 4:
			{
				string running[] = {"1 b ", "1 a ", "1 b ", "1 a", " 1 b"};
				_expected = 2;
				_received = _obj.newsLength(vector <string>(running, running+sizeof(running)/sizeof(string))); break;
			}
			/*case 5:
			{
				string running[] = ;
				_expected = ;
				_received = _obj.newsLength(vector <string>(running, running+sizeof(running)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string running[] = ;
				_expected = ;
				_received = _obj.newsLength(vector <string>(running, running+sizeof(running)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string running[] = ;
				_expected = ;
				_received = _obj.newsLength(vector <string>(running, running+sizeof(running)/sizeof(string))); break;
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
