#line 2 "OrderedSuperString.cpp"
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


class OrderedSuperString {
	public:
	int getLength(vector <string> words) {
		string superString = words[0];
		int idx = 0;
		for(int i=0; i < sz(words); i++) {
			bool flag = false;
			for(int j=idx; j < sz(superString); j++) {
				int match = 0;
				while((j + match) < min(sz(superString), j + sz(words[i])) && superString[j + match] == words[i][match])
					match++;
				// cout << j << " " << match << " " << words[i] << " " << superString.substr(j) << endl;
				if (match == min(sz(superString) - j , sz(words[i]))) {
					string unmatched = words[i].substr(match);
					idx = j;
					superString += unmatched;
					flag = true;
					break;
				} 
			}
			if (!flag) { idx++; superString += words[i];}
			// cout << superString << endl;
		}
		return sz(superString);
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
		cout << "Testing OrderedSuperString (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362816442;
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
		OrderedSuperString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"abc","ca"};
				_expected = 4;
				_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"a","a","b","a"};
				_expected = 3;
				_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"abcdef", "ab","bc", "de","ef"};
				_expected = 6;
				_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"ab","bc", "de","ef","abcdef"};
				_expected = 12;
				_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 4:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
