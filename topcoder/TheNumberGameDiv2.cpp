#line 2 "TheNumberGameDiv2.cpp"
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
#include <queue>
#include <sstream>
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

set<int> seen;

int revint(int k) {
	stringstream ss, tt;
	ss << k;
	string rev = ss.str();
	reverse(all(rev));
	tt << rev;
	int x;
	tt >> x;
	return x;
}

class TheNumberGameDiv2 {
	public:
	int minimumMoves(int A, int B) {
		queue<ii> Q;
		Q.push(ii(A, 0));
		while(!Q.empty()) {
			ii curr = Q.front();
			Q.pop();
			if (seen.find(curr.X) != seen.end()) continue;
			seen.insert(curr.X);

			if (curr.X == B) return curr.Y;

			Q.push(ii(curr.X / 10, curr.Y+1));
			Q.push(ii(revint(curr.X), curr.Y+1));
		}
		return -1;
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
		cout << "Testing TheNumberGameDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1364224858;
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
		TheNumberGameDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 25;
				int B = 5;
				_expected = 2;
				_received = _obj.minimumMoves(A, B); break;
			}
			case 1:
			{
				int A = 5162;
				int B = 16;
				_expected = 4;
				_received = _obj.minimumMoves(A, B); break;
			}
			case 2:
			{
				int A = 334;
				int B = 12;
				_expected = -1;
				_received = _obj.minimumMoves(A, B); break;
			}
			case 3:
			{
				int A = 218181918;
				int B = 9181;
				_expected = 6;
				_received = _obj.minimumMoves(A, B); break;
			}
			case 4:
			{
				int A = 9798147;
				int B = 79817;
				_expected = -1;
				_received = _obj.minimumMoves(A, B); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minimumMoves(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minimumMoves(A, B); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.minimumMoves(A, B); break;
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
