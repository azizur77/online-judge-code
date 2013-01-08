#line 2 "ShortPalindromes.cpp"
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
#include <map>
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

map<string, string> memo;

bool checkPal(string &S) {
	for(int i=0; i < S.length(); i++) 
		if (S[i] != S[S.length() - 1 - i]) 
			return false;
	return true;
}


string solve(string S) {
	if (memo.find(S) != memo.end()) {
		return memo[S];
	}
	int n = sz(S);
	if (checkPal(S)) return (memo[S] = S);

	if (S[0] == S[n-1]) {
		return (memo[S] = S[0] + solve(S.substr(1, n-2)) + S[n-1]);
	}
	string a = S[0] + solve(S.substr(1, n-1)) + S[0];
	string b = S[n-1] + solve(S.substr(0, n-1)) + S[n-1];
	if (sz(a) < sz(b)) memo[S] = a;
	else if (sz(a) == sz(b)) memo[S] = min(a, b);
	else memo[S] = b;
	return memo[S];
}


class ShortPalindromes {
	public:
	string shortest(string base) {
		return solve(base);
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
		cout << "Testing ShortPalindromes (1150.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352731472;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1150.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ShortPalindromes _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string base = "AAAB";
				_expected = "BAAAB";
				_received = _obj.shortest(base); break;
			}
			case 1:
			{
				string base = "TOPCODER";
				_expected = "REDTOCPCOTDER";
				_received = _obj.shortest(base); break;
			}
			case 2:
			{
				string base = "Q";
				_expected = "Q";
				_received = _obj.shortest(base); break;
			}
			case 3:
			{
				string base = "MADAMIMADAM";
				_expected = "MADAMIMADAM";
				_received = _obj.shortest(base); break;
			}
			case 4:
			{
				string base = "ALRCAGOEUAOEURGCOEUOOIGFA";
				_expected = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA";
				_received = _obj.shortest(base); break;
			}
			/*case 5:
			{
				string base = ;
				_expected = ;
				_received = _obj.shortest(base); break;
			}*/
			/*case 6:
			{
				string base = ;
				_expected = ;
				_received = _obj.shortest(base); break;
			}*/
			/*case 7:
			{
				string base = ;
				_expected = ;
				_received = _obj.shortest(base); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
