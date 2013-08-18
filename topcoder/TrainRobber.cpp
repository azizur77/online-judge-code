#line 2 "TrainRobber.cpp"
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
#define EPS 1e-9
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

vector<ll> a, d, seq;

struct node {
	ll num, gen;
	bool operator<(const node &other) const {
		return num > other.num;
	}
	node(ll a, ll b) : num(a), gen(b) {}
};

void loadGen(vector<string> offset, vector<string> period) {
	
	for(int i=0; i < sz(offset); i++) {
		stringstream ss;
		int x;
		ss << offset[i];
		while(ss >> x) {
			a.push_back(x);
		}
	}

	for(int i=0; i < sz(period); i++) {
		stringstream ss;
		int x;
		ss << period[i];
		while(ss >> x) {
			d.push_back(x);
		}
	}
}

void getSeq(int n) {
	priority_queue<node> heap;

	for(int i=0; i < sz(a); i++)
		heap.push(node(a[i], i));

	while (seq.size() < n+1) {
		node curr = heap.top();
		heap.pop();
		ll popgen = curr.gen;
		heap.push(node(curr.num + d[popgen], popgen));
		seq.push_back(curr.num);
	}

}

class TrainRobber {
	public:
	double finalPosition(double length, int nCarriages, vector <string> offset, vector <string> period, double trainSpeed, double robberSpeed, int nBridges) {
		loadGen(offset, period);
		seq.push_back(0);
		getSeq(nBridges);

		double currX = 0;
		int carriage = 0;

		for(int i=1; i <= nBridges; i++) {
			currX = seq[i];
			double interval = (1.0 * (seq[i] - seq[i-1])) / (trainSpeed + robberSpeed);
			int deltaCarr = int(floor((interval * robberSpeed) / length + EPS));

			if ((carriage + deltaCarr) >= nCarriages) {
				currX = seq[i-1] + double(nCarriages - carriage) * length * (trainSpeed + robberSpeed) / robberSpeed;
				break;
			}
			carriage += deltaCarr;
		}

		return currX;
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
		cout << "Testing TrainRobber (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1376725284;
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
		TrainRobber _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 1;
				int nCarriages = 4;
				string offset[] = {"3 4"};
				string period[] = {"4", "2"};
				int trainSpeed = 1;
				int robberSpeed = 1;
				int nBridges = 100;
				_expected = 14.0;
				_received = _obj.finalPosition(length, nCarriages, vector <string>(offset, offset+sizeof(offset)/sizeof(string)), vector <string>(period, period+sizeof(period)/sizeof(string)), trainSpeed, robberSpeed, nBridges); break;
			}
			case 1:
			{
				int length = 1;
				int nCarriages = 4;
				string offset[] = {"3 4"};
				string period[] = {"4 2"};
				int trainSpeed = 1;
				int robberSpeed = 1;
				int nBridges = 1;
				_expected = 3.0;
				_received = _obj.finalPosition(length, nCarriages, vector <string>(offset, offset+sizeof(offset)/sizeof(string)), vector <string>(period, period+sizeof(period)/sizeof(string)), trainSpeed, robberSpeed, nBridges); break;
			}
			case 2:
			{
				int length = 5;
				int nCarriages = 10;
				string offset[] = {"8 23"};
				string period[] = {"15 13"};
				int trainSpeed = 10;
				int robberSpeed = 10;
				int nBridges = 10;
				_expected = 75.0;
				_received = _obj.finalPosition(length, nCarriages, vector <string>(offset, offset+sizeof(offset)/sizeof(string)), vector <string>(period, period+sizeof(period)/sizeof(string)), trainSpeed, robberSpeed, nBridges); break;
			}
			case 3:
			{
				int length = 100;
				int nCarriages = 100;
				string offset[] = {"1 1"};
				string period[] = {"1 1"};
				int trainSpeed = 100;
				int robberSpeed = 100;
				int nBridges = 100;
				_expected = 50.0;
				_received = _obj.finalPosition(length, nCarriages, vector <string>(offset, offset+sizeof(offset)/sizeof(string)), vector <string>(period, period+sizeof(period)/sizeof(string)), trainSpeed, robberSpeed, nBridges); break;
			}
			case 4:
			{
				int length = 1;
				int nCarriages = 1000000;
				string offset[] = {"10", "15 63"};
				string period[] = {"23 42 11"};
				int trainSpeed = 10;
				int robberSpeed = 1000;
				int nBridges = 1000;
				_expected = 6355.0;
				_received = _obj.finalPosition(length, nCarriages, vector <string>(offset, offset+sizeof(offset)/sizeof(string)), vector <string>(period, period+sizeof(period)/sizeof(string)), trainSpeed, robberSpeed, nBridges); break;
			}
			/*case 5:
			{
				int length = ;
				int nCarriages = ;
				string offset[] = ;
				string period[] = ;
				int trainSpeed = ;
				int robberSpeed = ;
				int nBridges = ;
				_expected = ;
				_received = _obj.finalPosition(length, nCarriages, vector <string>(offset, offset+sizeof(offset)/sizeof(string)), vector <string>(period, period+sizeof(period)/sizeof(string)), trainSpeed, robberSpeed, nBridges); break;
			}*/
			/*case 6:
			{
				int length = ;
				int nCarriages = ;
				string offset[] = ;
				string period[] = ;
				int trainSpeed = ;
				int robberSpeed = ;
				int nBridges = ;
				_expected = ;
				_received = _obj.finalPosition(length, nCarriages, vector <string>(offset, offset+sizeof(offset)/sizeof(string)), vector <string>(period, period+sizeof(period)/sizeof(string)), trainSpeed, robberSpeed, nBridges); break;
			}*/
			/*case 7:
			{
				int length = ;
				int nCarriages = ;
				string offset[] = ;
				string period[] = ;
				int trainSpeed = ;
				int robberSpeed = ;
				int nBridges = ;
				_expected = ;
				_received = _obj.finalPosition(length, nCarriages, vector <string>(offset, offset+sizeof(offset)/sizeof(string)), vector <string>(period, period+sizeof(period)/sizeof(string)), trainSpeed, robberSpeed, nBridges); break;
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
