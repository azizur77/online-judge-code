#line 2 "ICPCBalloons.cpp"
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

int N;
vi _accepted, _count;
string _size;

class ICPCBalloons {
	public:
	int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted) {
		vi large, medium;
		for(int i=0; i < sz(balloonCount); i++) {
			if (balloonSize[i] == 'M') {
				medium.push_back(balloonCount[i]);
			}
			else if (balloonSize[i] == 'L') {
				large.push_back(balloonCount[i]);
			}
		}

		sort(all(medium));
		sort(all(large));
		sort(all(maxAccepted));
		reverse(all(medium));
		reverse(all(large));
		reverse(all(maxAccepted));

		for(int i=0; i < 21; i++) {
			medium.push_back(0);
			large.push_back(0);
		}

		int problems = sz(maxAccepted);
		int mincost = INF;

		int mtot = accumulate(all(medium), 0);
		int ltot = accumulate(all(large), 0);

		for(int i=0; i < (1 << (problems)); i++) {
			int cost = 0, mctr=0, lctr=0;
			int msum = 0, lsum = 0; 
			bool flag = false;
			for(int j=0; j < problems; j++) {
				int state = (i & (1 << j));
				if (state) {
					if (maxAccepted[j] > medium[mctr]) 
						cost += (maxAccepted[j] - medium[mctr]);
					msum += maxAccepted[j];
					mctr++;
				}
				else {
					if (maxAccepted[j] > large[lctr]) 
						cost += (maxAccepted[j] - large[lctr]);
					lsum += maxAccepted[j];
					lctr++;
				}
			}
			if (msum > mtot || lsum > ltot) continue;
			mincost = min(mincost, cost);
		}
		if (mincost < INF) return mincost;
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
		cout << "Testing ICPCBalloons (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1353428010;
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
		ICPCBalloons _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int balloonCount[] = {100};
				string balloonSize = "L";
				int maxAccepted[] = {1,2,3,4,5};
				_expected = 10;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 1:
			{
				int balloonCount[] = {100};
				string balloonSize = "M";
				int maxAccepted[] = {10,20,30,40,50};
				_expected = -1;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 2:
			{
				int balloonCount[] = {5,6,1,5,6,1,5,6,1};
				string balloonSize = "MLMMLMMLM";
				int maxAccepted[] = {7,7,4,4,7,7};
				_expected = 6;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 3:
			{
				int balloonCount[] = {100,100};
				string balloonSize = "ML";
				int maxAccepted[] = {50,51,51};
				_expected = -1;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 4:
			{
				int balloonCount[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
				string balloonSize = "MMMLLLMMLLMLMLM";
				int maxAccepted[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
				_expected = 5;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 5:
			{
				int balloonCount[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
				string balloonSize = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL";
				int maxAccepted[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
				_expected = 210;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			/*case 6:
			{
				int balloonCount[] = ;
				string balloonSize = ;
				int maxAccepted[] = ;
				_expected = ;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int balloonCount[] = ;
				string balloonSize = ;
				int maxAccepted[] = ;
				_expected = ;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int balloonCount[] = ;
				string balloonSize = ;
				int maxAccepted[] = ;
				_expected = ;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
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
