#line 2 "TravellingPurchasingMan.cpp"
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

int stopen[100], duration[100], stclose[100];
vector<ii> edges[100];
int visited[100] = {0}, M;

class TravellingPurchasingMan {
	public:
	int maxStores(int N, vector <string> interestingStores, vector <string> roads) {
		for(int i=0; i < sz(interestingStores); i++) {
			stringstream in;
			in << interestingStores[i];
			in >> stopen[i] >> stclose[i] >> duration[i];
		}
		M = sz(interestingStores);
		for(int i=0; i < roads.size(); i++) {
			stringstream in;
			int a, b, c;
			in << roads[i];
			in >> a >> b >> c;
			// cout << a << " " << b << " " << c << endl;
			edges[a].push_back(ii(b, c));
			edges[b].push_back(ii(a, c));
		}
		return backtrack(0, N-1);
	}
	int backtrack(int time, int store) {
		int can = 0, stores = 0, fast_stores = 0;

		if (store < M && (time <= stclose[store] && time >= stopen[store])) {
			can = 1;
			
		}

		for(int i=0; i < edges[store].size(); i++) {
			int u = edges[store][i].X, w = edges[store][i].Y;
			if (!visited[u]) {
				visited[u] = 1;
				fast_stores = max(fast_stores, backtrack(time + w, u));
				if (store < M)
				stores = max(stores, backtrack(max(time, stopen[store]) + w + duration[store], u));
				visited[u] = 0;
			}
		}
		if (can) stores++;
		return max(stores, fast_stores);
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
		cout << "Testing TravellingPurchasingMan (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1368895620;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TravellingPurchasingMan _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				string interestingStores[] = {"1 10 10" , "1 55 31", "10 50 100" };
				string roads[] = {"1 2 10"};
				_expected = 1;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 3;
				string interestingStores[] = {"1 10 10" , "1 55 30", "10 50 100" };
				string roads[] = {"1 2 10"};
				_expected = 2;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 5;
				string interestingStores[] = {"0 1000 17"};
				string roads[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"};
				_expected = 0;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			/*case 3:
			{
				int N = ;
				string interestingStores[] = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				int N = ;
				string interestingStores[] = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int N = ;
				string interestingStores[] = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.maxStores(N, vector <string>(interestingStores, interestingStores+sizeof(interestingStores)/sizeof(string)), vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
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
