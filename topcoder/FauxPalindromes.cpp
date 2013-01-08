#line 2 "FauxPalindromes.cpp"
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

bool is_pal(string p) {
	for(int i=0; i < sz(p) / 2; i++)
		if (p[i] != p[sz(p)-i-1]) return false;
	return true;
}

string tofaux(string p) {
	string res;
	for(int i=0; i < sz(p); i++) {
		int j = i;
		res += p[j];
		while(p[i] == p[j]) i++;
		i--;
	}
	return res;
}

class FauxPalindromes {
	public:
	string classifyIt(string word) {
		if (is_pal(word)) return "PALINDROME";
		else if (is_pal(tofaux(word))) return "FAUX";
		return "NOT EVEN FAUX";	
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
		cout << "Testing FauxPalindromes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356017748;
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
		FauxPalindromes _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string word = "ANA";
				_expected = "PALINDROME";
				_received = _obj.classifyIt(word); break;
			}
			case 1:
			{
				string word = "AAAAANNAA";
				_expected = "FAUX";
				_received = _obj.classifyIt(word); break;
			}
			case 2:
			{
				string word = "LEGENDARY";
				_expected = "NOT EVEN FAUX";
				_received = _obj.classifyIt(word); break;
			}
			case 3:
			{
				string word = "XXXYTYYTTYX";
				_expected = "FAUX";
				_received = _obj.classifyIt(word); break;
			}
			case 4:
			{
				string word = "TOPCOODEREDOOCPOT";
				_expected = "PALINDROME";
				_received = _obj.classifyIt(word); break;
			}
			case 5:
			{
				string word = "TOPCODEREDOOCPOT";
				_expected = "FAUX";
				_received = _obj.classifyIt(word); break;
			}
			case 6:
			{
				string word = "XXXXYYYYYZZXXYYY";
				_expected = "NOT EVEN FAUX";
				_received = _obj.classifyIt(word); break;
			}
			/*case 7:
			{
				string word = ;
				_expected = ;
				_received = _obj.classifyIt(word); break;
			}*/
			/*case 8:
			{
				string word = ;
				_expected = ;
				_received = _obj.classifyIt(word); break;
			}*/
			/*case 9:
			{
				string word = ;
				_expected = ;
				_received = _obj.classifyIt(word); break;
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
