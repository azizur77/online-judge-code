#line 2 "TheJediTestDiv2.cpp"
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


class TheJediTestDiv2 {
	public:
	int countSupervisors(vector <int> students, int Y, int J) {
		int mins = INF;
		for(int y=0; y < sz(students); y++) {
			int jedi = 0;
			if (students[y] > Y) jedi += (int) ceil(1.0*(students[y] - Y) / J);
			for(int i=0; i < sz(students); i++)
				if (i != y) {
					jedi += (int) ceil(1.0*students[i] / J);
				}
			mins = min(jedi, mins);
		}
		return mins;
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
		cout << "Testing TheJediTestDiv2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1360203007;
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
		TheJediTestDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int students[] = {10, 15};
				int Y = 12;
				int J = 5;
				_expected = 3;
				_received = _obj.countSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), Y, J); break;
			}
			case 1:
			{
				int students[] = {11, 13, 15};
				int Y = 9;
				int J = 5;
				_expected = 7;
				_received = _obj.countSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), Y, J); break;
			}
			case 2:
			{
				int students[] = {10};
				int Y = 100;
				int J = 2;
				_expected = 0;
				_received = _obj.countSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), Y, J); break;
			}
			case 3:
			{
				int students[] = {0, 0, 0, 0, 0};
				int Y = 145;
				int J = 21;
				_expected = 0;
				_received = _obj.countSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), Y, J); break;
			}
			case 4:
			{
				int students[] = {4, 7, 10, 5, 6, 55, 2};
				int Y = 20;
				int J = 3;
				_expected = 26;
				_received = _obj.countSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), Y, J); break;
			}
			/*case 5:
			{
				int students[] = ;
				int Y = ;
				int J = ;
				_expected = ;
				_received = _obj.countSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), Y, J); break;
			}*/
			/*case 6:
			{
				int students[] = ;
				int Y = ;
				int J = ;
				_expected = ;
				_received = _obj.countSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), Y, J); break;
			}*/
			/*case 7:
			{
				int students[] = ;
				int Y = ;
				int J = ;
				_expected = ;
				_received = _obj.countSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), Y, J); break;
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
