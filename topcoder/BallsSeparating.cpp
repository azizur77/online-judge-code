#line 2 "BallsSeparating.cpp"
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

vi r, g, b;

int box_score(int i) {
	int a[] = {r[i], g[i], b[i]};
	sort(a, a+3);
	return a[0] + a[1];
}

bool cmp(int a, int b1) { return box_score(a) < box_score(b1); }
bool cmpr(int a, int b1) {return r[a] < r[b1]; }
bool cmpg(int a, int b1) {return g[a] < g[b1]; }
bool cmpb(int a, int b1) {return b[a] < b[b1]; }

class BallsSeparating {
	public:
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
		if (sz(red) < 3) return -1;
		r = red;
		g = green;
		b = blue;
		int moves = 0;
		int mr=INF, mg=INF, mb=INF;
		bool flagr = true, flagg = true, flagb = true;
		for(int i=0; i < sz(red); i++) {
			if (r[i] >= g[i] && r[i] >= b[i]) { flagr = false; mg = min(mg, r[i] - g[i]); mb = min(mb, r[i] - b[i]); }
			if (g[i] >= r[i] && g[i] >= b[i]) { flagg = false; mr = min(mr, g[i] - r[i]); mb = min(mb, g[i] - b[i]); }
			if (b[i] >= g[i] && b[i] >= r[i]) { flagb = false; mg = min(mg, b[i] - g[i]); mr = min(mr, b[i] - r[i]); } 
			moves+= box_score(i);
		}
		if (flagr) moves+= mr;
		if (flagg) moves += mg;
		if (flagb) moves += mb;


		// vi indices(sz(red), 0);
		
		// for(int i=0; i < sz(red); i++) {
		// 	indices[i] = i;
		// }

		// bool seen[51] = {false};

		// for(int i=0; i < sz(red); i++) {
		// 	sort(all(indices), cmp);
		// 	int x = indices[0];
		// 	int k = box_score(x);
		// 	int T = r[x] + g[x] + b[x];
		// 	seen[x] = 1;
		// 	indices.clear();
		// 	for(int j=0; j < sz(red); j++) {
		// 		if (!seen[j]) {
		// 			indices.push_back(j);
		// 		}
		// 	}
		// 	int ri = max_element(all(indices), cmpr) - indices.begin();	
		// 	int gi = max_element(all(indices), cmpg) - indices.begin();	
		// 	int bi = max_element(all(indices), cmpb) - indices.begin();	
		// 	moves += k;

		// 	if (T-k == r[x]) {
		// 		g[gi] += g[x];
		// 		g[x] = 0;
		// 		b[bi] += b[x];
		// 		b[x] = 0;
		// 	}
		// 	else if (T-k == g[x]) {
		// 		r[ri] += r[x];
		// 		r[x] = 0;
		// 		b[bi] += b[x];
		// 		b[x] = 0;
		// 	}
		// 	else if (T-k == b[x]) {
		// 		g[gi] += g[x];
		// 		g[x] = 0;
		// 		r[ri] += r[x];
		// 		r[x] = 0;
		// 	}

			


	

		return moves;
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
		cout << "Testing BallsSeparating (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1359475809;
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
		BallsSeparating _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int red[] = {1, 1, 1};
				int green[] = {1, 1, 1};
				int blue[] = {1, 1, 1};
				_expected = 6;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 1:
			{
				int red[] = {5};
				int green[] = {6};
				int blue[] = {8};
				_expected = -1;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 2:
			{
				int red[] = {4, 6, 5, 7};
				int green[] = {7, 4, 6, 3};
				int blue[] = {6, 5, 3, 8};
				_expected = 37;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 3:
			{
				int red[] = {7, 12, 9, 9, 7};
				int green[] = {7, 10, 8, 8, 9};
				int blue[] = {8, 9, 5, 6, 13};
				_expected = 77;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 4:
			{
				int red[] = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
				int green[] = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
				int blue[] = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
				_expected = 7230607;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			/*case 5:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
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
