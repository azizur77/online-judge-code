#line 2 "PolygonTraversal2.cpp"
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
#include <bitset>
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
typedef bitset<16> BS;

bool intersect(int a1, int b1, int c1, int d1) {
	int a = min(a1, b1);
	int b = max(a1, b1);
	int c = min(c1, d1);
	int d = max(c1, d1);
	return (b > c && a < c) || (d > a && c < a);
}

int polycnt = 0, N;
bool used[16] = {0};
vi path;

void backtrack() {
	int bcnt = path.size();
	if (bcnt == N) {
		polycnt++;
		return;
	} 
	for(int i=1; i <= N; i++) if (!used[i]) {
		bool flag = false;
		for(int j=0; j <= sz(path) - 1; j++) if (abs(path[j] - i) > 1) {
			if (intersect(path.back(), i, path[j], path[j+1])) {
				flag = true;
				break;
			}
		}
		if (!flag && bcnt == N-1) {
			for(int j=0; j < sz(path) - 1; j++) if (abs(path[j] - i) > 1)
				if(intersect(path[0], i, path[j], path[j+1])) {
					flag = true;
					break;
				} 
		}

		if (flag) {
			used[i] = 1;
			path.push_back(i);
			backtrack();
			path.pop_back();
			used[i] = 0;
		}
	}
}


class PolygonTraversal2 {
	public:
	int count(int _N, vector <int> points) {
		path = points;
		N = _N;
		for(int i=0; i < sz(points); i++) used[points[i]] = 1;
		backtrack();
		return polycnt;
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
		cout << "Testing PolygonTraversal2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1364225223;
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
		PolygonTraversal2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int points[] = {1, 3, 5};
				_expected = 1;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 6;
				int points[] = {1, 4, 2};
				_expected = 1;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 7;
				int points[] = {2, 4, 7};
				_expected = 2;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 7;
				int points[] = {1, 2, 3, 4, 6, 5};
				_expected = 0;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 11;
				int points[] = {1, 5, 10};
				_expected = 1412;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int points[] = ;
				_expected = ;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int points[] = ;
				_expected = ;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int points[] = ;
				_expected = ;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
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
