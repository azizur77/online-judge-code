#line 2 "Aircraft.cpp"
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


class Aircraft {
	public:
	string nearMiss(vector <int> p1, vector <int> v1, vector <int> p2, vector <int> v2, int R) {
		ll vel[3], pos[3], range=R;
		for(int i=0; i < 3; i++) {
			vel[i] = v2[i] - v1[i];
			pos[i] = p2[i] - p1[i];
		}
		ll A =0, B = 0, C = -(range*range);
		for(int i=0; i < 3; i++) {
			B += 2LL	*(pos[i] * vel[i]);
			A += vel[i] * vel[i];
			C += pos[i] * pos[i];
		}
		ll D = B*B - 4LL*A*C;

		if (C <= 0 || (A!=0 && D >= 0 && ((D-B) >= 0 || (-D-B) >= 0))) {
			return "YES";
		}
		return "NO";
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
		cout << "Testing Aircraft (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361459821;
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
		Aircraft _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p1[] = {15,50,5};
				int v1[] = {25,1,0};
				int p2[] = {161,102,9};
				int v2[] = {-10,-10,-1};
				int R = 10;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 1:
			{
				int p1[] = {0,0,0};
				int v1[] = {2,2,0};
				int p2[] = {9,0,5};
				int v2[] = {-2,2,0};
				int R = 5;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 2:
			{
				int p1[] = {0,0,0};
				int v1[] = {-2,2,0};
				int p2[] = {9,0,5};
				int v2[] = {2,2,0};
				int R = 5;
				_expected = "NO";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 3:
			{
				int p1[] = {-2838,-7940,-2936};
				int v1[] = {1,1,-2};
				int p2[] = {532,3850,9590};
				int v2[] = {1,0,-3};
				int R = 3410;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 4:
			{
				int p1[] = {-8509,9560,345};
				int v1[] = {-89,-33,62};
				int p2[] = {-5185,-1417,2846};
				int v2[] = {-58,24,26};
				int R = 8344;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 5:
			{
				int p1[] = {-7163,-371,-2459};
				int v1[] = {-59,-41,-14};
				int p2[] = {-2398,-426,-5487};
				int v2[] = {-43,27,67};
				int R = 5410;
				_expected = "NO";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 6:
			{
				int p1[] = {1774,-4491,7810};
				int v1[] = {-12,19,-24};
				int p2[] = {2322,3793,9897};
				int v2[] = {-12,19,-24};
				int R = 10000;
				_expected = "YES";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			case 7:
			{
				int p1[] = {3731,8537,5661};
				int v1[] = {-70,71,32};
				int p2[] = {8701,-1886,-5115};
				int v2[] = {28,-13,7};
				int R = 9766;
				_expected = "NO";
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}
			/*case 8:
			{
				int p1[] = ;
				int v1[] = ;
				int p2[] = ;
				int v2[] = ;
				int R = ;
				_expected = ;
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}*/
			/*case 9:
			{
				int p1[] = ;
				int v1[] = ;
				int p2[] = ;
				int v2[] = ;
				int R = ;
				_expected = ;
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
			}*/
			/*case 10:
			{
				int p1[] = ;
				int v1[] = ;
				int p2[] = ;
				int v2[] = ;
				int R = ;
				_expected = ;
				_received = _obj.nearMiss(vector <int>(p1, p1+sizeof(p1)/sizeof(int)), vector <int>(v1, v1+sizeof(v1)/sizeof(int)), vector <int>(p2, p2+sizeof(p2)/sizeof(int)), vector <int>(v2, v2+sizeof(v2)/sizeof(int)), R); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
