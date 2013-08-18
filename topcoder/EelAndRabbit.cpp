#line 2 "EelAndRabbit.cpp"
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

vector<int> sets[55];

bool intersect(int a, int c, int d) {
	return (a >= c && a <= d);
}

class EelAndRabbit {
	public:
	int getmax(vector <int> l, vector <int> t) {
		for(int i=0; i < 55; i++) sets[i].push_back(i);
		int n = sz(l);
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++)
				if (j != i && intersect(t[i], t[j], t[j] + l[j])) {
					sets[i].push_back(j);
				}
		}
		int best = 0;
		for(int i=0; i < n; i++)
			for(int j=0; j < n; j++)
				if (i != j) {
					set<int> temp;
					for(int k=0; k < sets[i].size(); k++)
						temp.insert(sets[i][k]);
					for(int k=0; k < sets[j].size(); k++)
						temp.insert(sets[j][k]);
					best = max(best, (int) temp.size());
				}
		if (n == 1) return 1;
		return best;
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
		cout << "Testing EelAndRabbit (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1369510407;
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
		EelAndRabbit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int l[] = {2, 4, 3, 2, 2, 1, 10};
				int t[] = {2, 6, 3, 7, 0, 2, 0};
				_expected = 6;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int l[] = {1, 1, 1};
				int t[] = {2, 0, 4};
				_expected = 2;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int l[] = {1};
				int t[] = {1};
				_expected = 1;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int l[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
				int t[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
				_expected = 7;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 4:
			{
				int l[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int l[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int l[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
