#line 2 "ThreePhotos.cpp"
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

bool check_vector(vector<string> &M, int idx, bool fix_first=true) {
	for(int i=0; i < sz(M); i++) {
		if (fix_first && M[idx][i] == 'Y') return false;
		if (!fix_first && M[i][idx] == 'Y') return false;
	}
	return true;
}

bool check_valid(vector<string> &A, vector<string> &B, vector<string> &C) {
	int N = sz(A);
	for(int i=0; i < N; i++) {
		// (x, y+) - (x, z+)
		if (check_vector(A, i, 1) && !check_vector(B, i, 1)) return false; 
		// (x+, y) - (y, z+)
		if (check_vector(A, i, 0) && !check_vector(C, i, 1)) return false;
		// (y, z+) - (x+, y)
		if (check_vector(C, i, 1) && !check_vector(A, i, 0)) return false;
		// (y+, z) - (x+, z)
		if (check_vector(C, i, 0) && !check_vector(B, i, 0)) return false;
		// (x, z+) - (x, y+)
		if (check_vector(B, i, 1) && !check_vector(A, i, 1)) return false;
		// (x+, z) - (y+, z)
		if (check_vector(B, i, 0) && !check_vector(C, i, 0)) return false;
	}
	return true;
}

bool cube[52][52][52];

class ThreePhotos {
	public:
	int removeCubes(vector <string> A, vector <string> B, vector <string> C) {
		if (!check_valid(A, B, C)) return -1;
		int N = sz(A);
		fill(cube, 0);
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++) {
				if (A[i][j] == 'N') {
					for(int k=0; k < N; k++)
						cube[i][j][k] = 1;
				}
				if (B[i][j] == 'N') {
					for(int k=0; k < N; k++)
						cube[i][k][j] = 1;
				}
				if (C[i][j] == 'N') {
					for(int k=0; k < N; k++)
						cube[k][i][j] = 1;
				}
			}
		int minmoves = 0;
		REP(i, N) REP(j, N) REP(k, N) if (cube[i][j][k]) minmoves++;
		return minmoves;
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
		cout << "Testing ThreePhotos (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1364190481;
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
		ThreePhotos _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A[] = {"YY","YY"};
				string B[] = {"YY","YY"};
				string C[] = {"YY","YY"};
				_expected = 0;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}
			case 1:
			{
				string A[] = {"NNN","NNN","NNN"};
				string B[] = {"NNN","NNN","NNN"};
				string C[] = {"NNN","NNN","NNN"};
				_expected = 27;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}
			case 2:
			{
				string A[] = {"NNNNN","NNNNN","NNNNN","YYNNN","NNNNN"};
				string B[] = {"NNNNN","NNNNN","NNNNN","NNYNY","NNNNN"};
				string C[] = {"NNYNN","NNNNY","NNNNN","NNNNN","NNNNN"};
				_expected = 123;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}
			case 3:
			{
				string A[] = {"YY","YY"};
				string B[] = {"YY","YY"};
				string C[] = {"YN","YN"};
				_expected = -1;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}
			/*case 4:
			{
				string A[] = ;
				string B[] = ;
				string C[] = ;
				_expected = ;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string A[] = ;
				string B[] = ;
				string C[] = ;
				_expected = ;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string A[] = ;
				string B[] = ;
				string C[] = ;
				_expected = ;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
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
