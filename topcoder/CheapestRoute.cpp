#line 2 "CheapestRoute.cpp"
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
#define INF (int)1e7
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

ii d[1000][1000];

struct cost {
	int node, tele, C, M;
	cost(int a, int b, int c, int d) : node(a), tele(b), C(c), M(d) {}
	const bool operator<(const cost& rhs) const {
		if (C > rhs.C) return true;
		return M > rhs.M;
	}
};

class CheapestRoute {
	public:
	vector <int> routePrice(vector <int> cellPrice, vector <int> enterCell, vector <int> exitCell, int teleportPrice) {
		priority_queue<cost> heap;
		set<ii> visited;
		int n = sz(cellPrice);
		heap.push(cost(0, 0, 0, 0));
		REP(i, n) REP(j, n+1) d[i][j] = ii(INF, INF);

		ii optimal (INF, INF);

		while(heap.size() > 0) {
			cost curr = heap.top();
			heap.pop();

			if (ii(curr.C, curr.M) >= d[curr.node][curr.tele]) continue;


			d[curr.node][curr.tele] = ii (curr.C, curr.M);

			if (curr.node == n-1) {
				optimal = min(optimal, ii(curr.C, curr.M));
				continue;
			}


			if (curr.node > 0 && cellPrice[curr.node - 1] != -1) 
				heap.push(cost(curr.node - 1, curr.tele, curr.C + cellPrice[curr.node - 1], curr.M + 1));
			if (curr.node < n-1 && cellPrice[curr.node + 1] != -1) 
				heap.push(cost(curr.node + 1, curr.tele, curr.C + cellPrice[curr.node + 1], curr.M + 1));

			if (curr.tele < n+1)
			for(int i=0; i < sz(enterCell); i++)
				if (enterCell[i] == curr.node && cellPrice[exitCell[i]] != -1) {
					heap.push(cost(exitCell[i], curr.tele + 1, curr.tele + teleportPrice + curr.C, 
						curr.M + 1));
				}
		}

		if (optimal.X == INF || optimal.Y == INF) return vi();
		vi res(2, 0);
		res[0] = optimal.X;
		res[1] = optimal.Y;
		return res;
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
		cout << "Testing CheapestRoute (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362754220;
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
		CheapestRoute _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cellPrice[] = {32, 12, 88, 4, 27, 98, 69, 6};

				int enterCell[] = {0, 6, 3, 3, 6, 4, 0, 0, 2, 2, 4, 5, 6, 0, 5, 3, 3, 3, 2, 4, 4, 3, 0, 5, 3, 3, 2, 1, 3, 0, 1, 1, 7, 5, 5, 3, 1, 6, 2, 1, 5, 4, 7, 4, 6};
				int exitCell[] = {1, 3, 0, 1, 4, 0, 1, 1, 7, 4, 6, 3, 7, 6, 6, 3, 4, 6, 0, 6, 2, 0, 7, 2, 6, 3, 6, 2, 5, 5, 0, 7, 2, 1, 3, 4, 6, 3, 6, 0, 5, 3, 0, 1, 6};
				int teleportPrice = 24;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
			}
			case 1:
			{
				int cellPrice[] = {0,-1,0,0};
				int enterCell[] = {0};
				int exitCell[] = {2};
				int teleportPrice = 1000;
				int __expected[] = {1000, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
			}
			case 2:
			{
				int cellPrice[] = {1,2,3};
				int enterCell[] = {};
				int exitCell[] = {};
				int teleportPrice = 100;
				int __expected[] = {5, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
			}
			case 3:
			{
				int cellPrice[] = {1,2,-1};
				int enterCell[] = {0};
				int exitCell[] = {2};
				int teleportPrice = 0;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
			}
			case 4:
			{
				int cellPrice[] = {4,2,1,0,5,6,0,3,0};
				int enterCell[] = {4,4,3,7,5,4,2,5,8,4};
				int exitCell[] = {7,3,5,0,5,4,5,0,8,3};
				int teleportPrice = 8;
				int __expected[] = {14, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
			}
			/*case 5:
			{
				int cellPrice[] = ;
				int enterCell[] = ;
				int exitCell[] = ;
				int teleportPrice = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
			}*/
			/*case 6:
			{
				int cellPrice[] = ;
				int enterCell[] = ;
				int exitCell[] = ;
				int teleportPrice = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
			}*/
			/*case 7:
			{
				int cellPrice[] = ;
				int enterCell[] = ;
				int exitCell[] = ;
				int teleportPrice = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
