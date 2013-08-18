#line 2 "Knights.cpp"
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
#include <sstream>
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

vector<string> positions_from_string(string s) {
	vector<string> result;

	string buf;
	for(int i=0; i < sz(s); i++) {
		if (s[i] != ' ') {
			buf += s[i];
		} else {
			result.push_back(buf);
			buf = "";
		}
	}
	return result;
}

int adj[1400][1400], n;


class Knights {
	public:

	int max_match() {
		int flow = 0;
		while(bfs()) {
			flow++;
		} 
		return flow;
	}

	int bfs() {
		queue< vi > Q;
		vi root(1, 0);
		Q.push(root);
		vi path;

		while(!Q.empty()) {
			vi curr = Q.front();
			Q.pop();
			if (curr.back() == 2*n*n+1) {
				path = curr;
				break;
			}
			cout << curr.back() << endl;

			for(int i=0; i <= 2 *n * n + 1; i++)
				if (adj[curr.back()][i]) {
					vi copy = curr;
					copy.push_back(i);
					Q.push(copy);
				}
		}
		if (path.size()) {
			for(int i=0; i < path.size() - 1; i++) {
				adj[i][i+1] = 0;
				adj[i+1][i] = 1;
			}
			return 1;
		}
		return 0;
	}


	int makeFriendly(int N, vector <string> pos) {
		fill(adj, 0);
		n = N;
		int source = 0, sink = 2*N*N+1;

		for(int i=0; i < sz(pos); i++) {
			vector<string> positions = positions_from_string(pos[i]);
			for(int j=0; j < positions.size(); j++) {
				int row = positions[j][0] - 'A';
				int col = positions[j][1] - '0';

				if ((row + col) % 2) { // white
					int idx = 1 + row * N + col;
					adj[source][idx] = 1;

					//connect knight paths
					int delta = 1 + N*N;

					for(int dx = -2; dx <= 2; dx++)
						for(int dy = -2; dy <= 2; dy++)
							if((abs(dx) == 2 && abs(dy) == 1) || (abs(dy) == 2 && abs(dx) == 1))
							if(row + dx >= 0 && row + dx < N && col + dx >= 0 && col + dx < N)
								adj[idx][delta + row*N + col] = 1;


				} else { // black
					int idx = 1 + N*N + row * N + col;
					adj[idx][sink] = 1;
					int delta = 1;

					for(int dx = -2; dx <= 2; dx++)
						for(int dy = -2; dy <= 2; dy++)
							if((abs(dx) == 2 && abs(dy) == 1) || (abs(dy) == 2 && abs(dx) == 1))
							if((row + dx) >= 0 && (row + dx) < N && (col + dx) >= 0 && (col + dx < N))
								adj[delta + row*N + col][idx] = 1;
				}
			}
		}
		return max_match();
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
		cout << "Testing Knights (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1374674935;
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
		Knights _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				string pos[] = {"A2 A4", "B1 B5", "D1 D5 E2 E4 C3"};
				_expected = 1;
				_received = _obj.makeFriendly(N, vector <string>(pos, pos+sizeof(pos)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 2;
				string pos[] = {"A1 A2 B1 B2"};
				_expected = 0;
				_received = _obj.makeFriendly(N, vector <string>(pos, pos+sizeof(pos)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 6;
				string pos[] = {"A1 A5 B3 C1 C5 D2 D4 E6 F5"};
				_expected = 3;
				_received = _obj.makeFriendly(N, vector <string>(pos, pos+sizeof(pos)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 8;
				string pos[] = {"A2 A4 A5 A6 B2 B5 B6 B7 B8",
				                "C3 C8 D1 D2 D3 D4 D5 D6 D8",
				                "E1 E3 E8 F1 F2 F8 G3 G5 H4 H7 H8"};
				_expected = 12;
				_received = _obj.makeFriendly(N, vector <string>(pos, pos+sizeof(pos)/sizeof(string))); break;
			}
			case 4:
			{
				int N = 9;
				string pos[] = {"A3 A4 A5 A7 A8 B6 B8 C3 C6",
				                "C7 C9 D4 D5 D8 D9 E1 E3 E7",
				                "F2 G2 G6 G7 H2 H9 I2 I4 I5",
				                "I6 I7 I8 I9"};
				_expected = 10;
				_received = _obj.makeFriendly(N, vector <string>(pos, pos+sizeof(pos)/sizeof(string))); break;
			}
			/*case 5:
			{
				int N = ;
				string pos[] = ;
				_expected = ;
				_received = _obj.makeFriendly(N, vector <string>(pos, pos+sizeof(pos)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int N = ;
				string pos[] = ;
				_expected = ;
				_received = _obj.makeFriendly(N, vector <string>(pos, pos+sizeof(pos)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int N = ;
				string pos[] = ;
				_expected = ;
				_received = _obj.makeFriendly(N, vector <string>(pos, pos+sizeof(pos)/sizeof(string))); break;
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
