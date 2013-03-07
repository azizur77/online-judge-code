#line 2 "MagicMolecule.cpp"
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


class MagicMolecule {
	public:
	int maxMagicPower(vector <int> magicPower, vector <string> magicBond) {
		
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
		cout << "Testing MagicMolecule (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361293112;
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
		MagicMolecule _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int magicPower[] = {1,2,3};
				string magicBond[] = {"NYY","YNN","YNN"};
				_expected = 4;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			case 1:
			{
				int magicPower[] = {1,1,1,1};
				string magicBond[] = {"NNYY","NNYY","YYNN","YYNN"};
				_expected = -1;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			case 2:
			{
				int magicPower[] = {86,15,100,93,53,50};
				string magicBond[] = {"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"};
				_expected = 332;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			case 3:
			{
				int magicPower[] = {3969,9430,7242,8549,8190,8368,3704,9740,1691};
				string magicBond[] = {"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"};
				_expected = 57179;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			/*case 4:
			{
				int magicPower[] = ;
				string magicBond[] = ;
				_expected = ;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int magicPower[] = ;
				string magicBond[] = ;
				_expected = ;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int magicPower[] = ;
				string magicBond[] = ;
				_expected = ;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
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
