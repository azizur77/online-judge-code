#line 2 "HyperKnight.cpp"
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

vector<vi> choose(int k) {
	vector<vi> result;
	vi seed(8, 0);
	REP(i, 8) seed[i] = i;

	queue <vi> Q;
	for(int i=0; i < sz(seed); i++)
		Q.push(vi(1, seed[i]));

	while(Q.size()) {
		vi curr = Q.front();
		Q.pop();

		if (sz(curr) == k) {
			result.push_back(curr);
			continue;
		}

		int last = curr[sz(curr) - 1];
		for(int i=0; i < sz(seed); i++)
			if (seed[i] > last) {
				vi copy(curr);
				copy.push_back(seed[i]);
				Q.push(copy);
			}
	}
	return result;
}

ii intersect(ii a, ii b) {
	ii c = ii(max(a.X, b.X), min(a.Y, b.Y));
	if (c.X > c.Y) c = ii (-1, -1);
	return c;
}

class HyperKnight {
	public:
	long long countCells(int a, int b, int numRows, int numColumns, int k) {
		ii intervals[] = {
			ii (1, numRows-a),
			ii (a, numRows),
			ii (1, numRows-b),
			ii (b, numRows),
			ii (1, numColumns-a),
			ii (a, numColumns),
			ii (b, numColumns),
			ii (1, numColumns-b)
		};
		ii combos[] = {
			ii (0, 6),
			ii (0, 7),
			ii (1, 6),
			ii (1, 7),
			ii (2, 4),
			ii (2, 5),
			ii (3, 4),
			ii (3, 5)
		};

		ll nways = 0;
		vector<vi> test = choose(2);
		REP(i, sz(test)) {
			REP(j, 2) cout << test[i][j] << " ";
			cout << endl;
		}
		

		for(int x=k; x <= 8; x++) {
			vector <vi> combs = choose(x);

			for(int i = 0; i < sz(combs); i++) {
				vi curr (combs[i]);
				ii intX = intervals[combos[curr[0]].X];
				ii intY = intervals[combos[curr[0]].Y];
				FOR(j, 1, x) {
					intX = intersect(intX, intervals[combos[curr[j]].X]);
					intY = intersect(intY, intervals[combos[curr[j]].Y]);
				}
				if (intX.X == -1 && intX.Y == -1) continue;
				if (intY.X == -1 && intY.Y == -1) continue;
				ll sizex = intX.Y - intX.X + 1;
				ll sizey = intY.Y - intY.X + 1;
				if (x==k)
					nways += sizex*sizey;
				else
					nways -= sizex*sizey;
			}
		}


		return nways;
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
		cout << "Testing HyperKnight (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352535055;
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
		HyperKnight _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 2;
				int b = 1;
				int numRows = 8;
				int numColumns = 8;
				int k = 4;
				_expected = 20LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 1:
			{
				int a = 3;
				int b = 2;
				int numRows = 8;
				int numColumns = 8;
				int k = 2;
				_expected = 16LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 2:
			{
				int a = 1;
				int b = 3;
				int numRows = 7;
				int numColumns = 11;
				int k = 0;
				_expected = 0LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 3:
			{
				int a = 3;
				int b = 2;
				int numRows = 10;
				int numColumns = 20;
				int k = 8;
				_expected = 56LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 4:
			{
				int a = 1;
				int b = 4;
				int numRows = 100;
				int numColumns = 10;
				int k = 6;
				_expected = 564LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			case 5:
			{
				int a = 2;
				int b = 3;
				int numRows = 1000000000;
				int numColumns = 1000000000;
				int k = 8;
				_expected = 999999988000000036LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}
			/*case 6:
			{
				int a = ;
				int b = ;
				int numRows = ;
				int numColumns = ;
				int k = ;
				_expected = LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int numRows = ;
				int numColumns = ;
				int k = ;
				_expected = LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				int numRows = ;
				int numColumns = ;
				int k = ;
				_expected = LL;
				_received = _obj.countCells(a, b, numRows, numColumns, k); break;
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
