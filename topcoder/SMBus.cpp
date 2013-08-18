#line 2 "SMBus.cpp"
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


class SMBus {
	public:
	int transmitTime(vector <string> messages, vector <int> times) {
		
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
		cout << "Testing SMBus (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1364640532;
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
		SMBus _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string messages[] = {"123","124","134"};
				int times[] = {1,2,3};
				_expected = 25;
				_received = _obj.transmitTime(vector <string>(messages, messages+sizeof(messages)/sizeof(string)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}
			case 1:
			{
				string messages[] = {"012", "1234", "1233", "1223", "1123"};
				int times[] = {4,1,5,2,9};
				_expected = 94;
				_received = _obj.transmitTime(vector <string>(messages, messages+sizeof(messages)/sizeof(string)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}
			case 2:
			{
				string messages[] = {"0002019289019101039663222896280025447",
				                     "00201873554718989597528841094293294387326",
				                     "010699029378761", "0110118", "011143279122561420",
				                     "001046384966198", "00200570375817801109530240012",
				                     "0003163277589822", "01100240744590150136673219652442108",
				                     "012033596872642679096489479354", "0121059494098",
				                     "00001002303019117948961792176", "00216399923558", "02014",
				                     "00224999120803846121427603894967637446889670369",
				                     "01101009414735635151893037596051740080475886",
				                     "0000101211809647472761605153430927981533514",
				                     "176845042961739039392207791589",
				                     "02000047506929386333221966659552927385017901842706",
				                     "021001117450487502127241076595509511",
				                     "021010776262723557108100899515",
				                     "0210114830738951774606917781619656",
				                     "0211798433083855430", "00000005842153604632996228135814",
				                     "0001000766929248550736138555144997170272757787",
				                     "0001010247593342056062432721557",
				                     "01100004828618452515832113396660046634951",
				                     "0132559984733529872911444204991646138116334788",
				                     "0224149857349431864906523152249992",
				                     "00001142929552573133212195441932219",
				                     "0011090498947092002457447355036811372647896489218",
				                     "000001275414757476198997466", "00010014",
				                     "00111025861963467834393486017602553072649743",
				                     "000102085", "00120882661783539",
				                     "01100018938145727291185020",
				                     "01100191373790478446634214244459341793", "0001129060",
				                     "001111287431066271555393813846448",
				                     "011010160778408696098486370196313", "0002125146381515395"};
				int times[] = {42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77,
				               87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68,
				               2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64};
				_expected = 71048;
				_received = _obj.transmitTime(vector <string>(messages, messages+sizeof(messages)/sizeof(string)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}
			/*case 3:
			{
				string messages[] = ;
				int times[] = ;
				_expected = ;
				_received = _obj.transmitTime(vector <string>(messages, messages+sizeof(messages)/sizeof(string)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				string messages[] = ;
				int times[] = ;
				_expected = ;
				_received = _obj.transmitTime(vector <string>(messages, messages+sizeof(messages)/sizeof(string)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				string messages[] = ;
				int times[] = ;
				_expected = ;
				_received = _obj.transmitTime(vector <string>(messages, messages+sizeof(messages)/sizeof(string)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
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
