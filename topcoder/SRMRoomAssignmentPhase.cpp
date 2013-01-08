#line 2 "SRMRoomAssignmentPhase.cpp"
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


class SRMRoomAssignmentPhase {
	public:
	int countCompetitors(vector <int> ratings, int K) {
		int cnt = 0;
		for(int i=0; i < sz(ratings); i += K) {
			if (ratings[i] > ratings[0])
				cnt++;
		}
		return cnt;
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
		cout << "Testing SRMRoomAssignmentPhase (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352601232;
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
		SRMRoomAssignmentPhase _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int ratings[] = {491, 981, 1199, 763, 994, 879, 888};
				int K = 3;
				_expected = 2;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 1:
			{
				int ratings[] = {1024, 1000, 600};
				int K = 1;
				_expected = 0;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 2:
			{
				int ratings[] = {505, 679, 900, 1022};
				int K = 2;
				_expected = 1;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 3:
			{
				int ratings[] = {716, 58, 1000, 1004, 912, 822, 453, 1100, 558};
				int K = 3;
				_expected = 1;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 4:
			{
				int ratings[] = {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500};
				int K = 4;
				_expected = 3;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			case 5:
			{
				int ratings[] = {1197, 1198, 1196, 1195, 1199};
				int K = 1;
				_expected = 2;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}
			/*case 6:
			{
				int ratings[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int ratings[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
			}*/
			/*case 8:
			{
				int ratings[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countCompetitors(vector <int>(ratings, ratings+sizeof(ratings)/sizeof(int)), K); break;
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
