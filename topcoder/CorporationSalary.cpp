#line 2 "CorporationSalary.cpp"
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

int adj[55][55];
ll memo[55], n;

ll findSalary(int emp) {
	if (memo[emp] != -1) return memo[emp];
	memo[emp] = 0;
	for(int i=0; i < n; i++) 
		if (adj[emp][i] == 1)
			memo[emp] += findSalary(i);
	if (!memo[emp]) memo[emp]++;
	return memo[emp];
}

class CorporationSalary {
	public:
	long long totalSalary(vector <string> relations) {
		ll salary = 0;
		n = sz(relations);
		fill(memo, -1);
		REP(i, n) REP(j, n) adj[i][j] = (relations[i][j] == 'Y');
		for(int i=0; i < n; i++)
			salary += findSalary(i);
		return salary;
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
		cout << "Testing CorporationSalary (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362753578;
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
		CorporationSalary _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string relations[] = {"N"};
				_expected = 1LL;
				_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
			}
			case 1:
			{
				string relations[] = {"NNYN",
				                      "NNYN",
				                      "NNNN",
				                      "NYYN"};
				_expected = 5LL;
				_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
			}
			case 2:
			{
				string relations[] = {"NNNNNN",
				                      "YNYNNY",
				                      "YNNNNY",
				                      "NNNNNN",
				                      "YNYNNN",
				                      "YNNYNN"};
				_expected = 17LL;
				_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
			}
			case 3:
			{
				string relations[] = {"NYNNYN",
				                      "NNNNNN",
				                      "NNNNNN",
				                      "NNYNNN",
				                      "NNNNNN",
				                      "NNNYYN"};
				_expected = 8LL;
				_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
			}
			case 4:
			{
				string relations[] = {"NNNN",
				                      "NNNN",
				                      "NNNN",
				                      "NNNN"};
				_expected = 4LL;
				_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
			}
			/*case 5:
			{
				string relations[] = ;
				_expected = LL;
				_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string relations[] = ;
				_expected = LL;
				_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string relations[] = ;
				_expected = LL;
				_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
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
