#line 2 "FoxAndTouristFamilies.cpp"
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


int n, m, IDX=0;
double counts[100][100];
vi _A, _B;

void bfs(int start) {
	queue< pair<int, vi> > S;
	S.push(mp(start, vi()));
	bool seen[100];
	fill(seen, 0);
	while(S.size()) {
		pair <int, vi> curr = S.front();
		S.pop();
		if (seen[curr.X]) continue;
		seen[curr.X] = true;
		REP(i, sz(curr.Y)) counts[IDX][curr.Y[i]] += (1.0 / m);
		REP(i, m) {
			int ele;
			if (_A[i] == curr.X) ele = _B[i];
			else if (_B[i] == curr.X) ele = _A[i];
			else continue;
			if (!seen[ele]) {
				vi copy(curr.Y);
				copy.push_back(i);
				S.push(mp(ele, copy));
			}
		}
	}
	IDX++;
}


class FoxAndTouristFamilies {
	public:
	double expectedLength(vector <int> A, vector <int> B, vector <int> f) {
		REP(i, 100) REP(j, 100) counts[i][j] = 0.0;
		_A = A;
		_B = B;
		m = sz(A);
		n = m + 1;
		REP(i, sz(f)) bfs(f[i]);
		double res = 0;
		REP(j, n) {
			double d = 1.0;
			REP(i, IDX) {
				d *= counts[i][j];
			}
			res += d;
		}
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
		cout << "Testing FoxAndTouristFamilies (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1353430824;
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
		FoxAndTouristFamilies _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {0, 1};
				int B[] = {1, 2};
				int f[] = {0};
				_expected = 1.5;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {0, 1};
				int B[] = {1, 2};
				int f[] = {0, 0};
				_expected = 1.25;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {0, 1};
				int B[] = {1, 2};
				int f[] = {0, 1};
				_expected = 0.75;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {0, 1};
				int B[] = {1, 2};
				int f[] = {0, 2};
				_expected = 1.0;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {0,0,0};
				int B[] = {1,2,3};
				int f[] = {0};
				_expected = 1.0;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {0,0,0};
				int B[] = {1,2,3};
				int f[] = {1,2};
				_expected = 0.7777777777777777;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = {0,1,1,3,5,6};
				int B[] = {1,2,3,4,4,4};
				int f[] = {5,6,1};
				_expected = 0.4537037037037037;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			case 7:
			{
				int A[] = {0,1,2,3,4,5,6,7,8,9};
				int B[] = {1,2,3,4,5,6,7,8,9,10};
				int f[] = {0,0,0,0,0,0,0,0,0,0};
				_expected = 1.4914341925000003;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int f[] = ;
				_expected = ;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int A[] = ;
				int B[] = ;
				int f[] = ;
				_expected = ;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int A[] = ;
				int B[] = ;
				int f[] = ;
				_expected = ;
				_received = _obj.expectedLength(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(f, f+sizeof(f)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
