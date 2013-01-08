#line 2 "TomekPhone.cpp"
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


class TomekPhone {
	public:
	int minKeystrokes(vector <int> occurences, vector <int> keySizes) {
		int numkeys = accumulate(all(keySizes), 0);
		if (numkeys < sz(occurences)) return -1;
		vi ctrs(keySizes);
		sort(all(occurences));
		reverse(all	(occurences));
		int cost = 0;
		int lenk = sz(keySizes);
		int j = 0;
		REP(i, sz(occurences)) {
			while(keySizes[j % lenk] == 0) j++;
			if (keySizes[j % lenk] > 0) {
				keySizes[j % lenk]--;
				cost += (ctrs[j % lenk] - keySizes[j % lenk]) * occurences[i];
				j++;
			}
		}
		return cost;
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
		cout << "Testing TomekPhone (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352567406;
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
		TomekPhone _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int occurences[] = {7,3,4,1};
				int keySizes[] = {2,2};
				_expected = 19;
				_received = _obj.minKeystrokes(vector <int>(occurences, occurences+sizeof(occurences)/sizeof(int)), vector <int>(keySizes, keySizes+sizeof(keySizes)/sizeof(int))); break;
			}
			case 1:
			{
				int occurences[] = {13,7,4,20};
				int keySizes[] = {2,1};
				_expected = -1;
				_received = _obj.minKeystrokes(vector <int>(occurences, occurences+sizeof(occurences)/sizeof(int)), vector <int>(keySizes, keySizes+sizeof(keySizes)/sizeof(int))); break;
			}
			case 2:
			{
				int occurences[] = {11,23,4,50,1000,7,18};
				int keySizes[] = {3,1,4};
				_expected = 1164;
				_received = _obj.minKeystrokes(vector <int>(occurences, occurences+sizeof(occurences)/sizeof(int)), vector <int>(keySizes, keySizes+sizeof(keySizes)/sizeof(int))); break;
			}
			case 3:
			{
				int occurences[] = {100,1000,1,10};
				int keySizes[] = {50};
				_expected = 1234;
				_received = _obj.minKeystrokes(vector <int>(occurences, occurences+sizeof(occurences)/sizeof(int)), vector <int>(keySizes, keySizes+sizeof(keySizes)/sizeof(int))); break;
			}
			case 4:
			{
				int occurences[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
				int keySizes[] = {10,10,10,10,10,10,10,10};
				_expected = 3353;
				_received = _obj.minKeystrokes(vector <int>(occurences, occurences+sizeof(occurences)/sizeof(int)), vector <int>(keySizes, keySizes+sizeof(keySizes)/sizeof(int))); break;
			}
			/*case 5:
			{
				int occurences[] = ;
				int keySizes[] = ;
				_expected = ;
				_received = _obj.minKeystrokes(vector <int>(occurences, occurences+sizeof(occurences)/sizeof(int)), vector <int>(keySizes, keySizes+sizeof(keySizes)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int occurences[] = ;
				int keySizes[] = ;
				_expected = ;
				_received = _obj.minKeystrokes(vector <int>(occurences, occurences+sizeof(occurences)/sizeof(int)), vector <int>(keySizes, keySizes+sizeof(keySizes)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int occurences[] = ;
				int keySizes[] = ;
				_expected = ;
				_received = _obj.minKeystrokes(vector <int>(occurences, occurences+sizeof(occurences)/sizeof(int)), vector <int>(keySizes, keySizes+sizeof(keySizes)/sizeof(int))); break;
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
