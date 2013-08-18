#line 2 "AddElectricalWires.cpp"
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

int mark[55], ctr = 0, n;
vector<string> adj;
vector<int> components[55];

void connect(int i) {
	if (mark[i]) return;
	mark[i] = 1;
	components[ctr].push_back(i);
	for(int j=0; j < n; j++)
		if (!mark[j] && adj[i][j] == '1')
			connect(j);
}	


class AddElectricalWires {
	public:
	int maxNewWires(vector <string> wires, vector <int> gridConnections) {
		fill(mark, 0);
		adj = wires;
		n = sz(wires);
		int newWires = 0;

		for(int i=0; i < n; i++)
			if (!mark[i]) {
				connect(i);
				ctr++;
			}

		int is_main[55];
		fill(is_main, 0);

		vector<int> unconnected, mainline;

		for(int i=0; i < sz(gridConnections); i++)
			is_main[gridConnections[i]] = 1;

		for(int i=0; i < ctr; i++) {
			int m = components[i].size();
			REP(j, m) FOR(k, j+1, m) {
				int u = components[i][j], v = components[i][k];
				if (wires[u][v] == '0') newWires++;
			}
			bool flag = 0;
			REP (j, m) {
				flag |= is_main[components[i][j]];
			}
			if (!flag) unconnected.push_back(m);
			else mainline.push_back(m);
		}
		sort(all(unconnected));
		sort(all(mainline));

		for(int i=sz(unconnected)-1; i > 0; i--) {
			newWires += unconnected[i] * unconnected[i-1];
			unconnected[i-1] += unconnected[i];
		}

		if (sz(unconnected) > 0) {
			newWires += mainline.back() * unconnected[0];
		}

		return newWires;


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
		cout << "Testing AddElectricalWires (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362974608;
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
		AddElectricalWires _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string wires[] = {"000","000","000"};
				int gridConnections[] = {0};
				_expected = 3;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 1:
			{
				string wires[] = {"000","000","000"};
				int gridConnections[] = {0,1};
				_expected = 1;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 2:
			{
				string wires[] = {"01","10"};
				int gridConnections[] = {0};
				_expected = 0;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 3:
			{
				string wires[] = {"00000","00000","00000","00000","00000"};
				int gridConnections[] = {0,1,2,3,4};
				_expected = 0;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			case 4:
			{
				string wires[] = {"01000","10100","01010","00100","00000"};
				int gridConnections[] = {2,4};
				_expected = 3;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}
			/*case 5:
			{
				string wires[] = ;
				int gridConnections[] = ;
				_expected = ;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string wires[] = ;
				int gridConnections[] = ;
				_expected = ;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string wires[] = ;
				int gridConnections[] = ;
				_expected = ;
				_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
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
