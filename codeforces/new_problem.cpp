#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <string>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int main() {
	int n;
	cin >> n;
	vector<string> titles(n, "");
	for(int i=0; i < n; i++) cin >> titles[i];

	vector<string> to_try;

	for(char c='a'; c <= 'z'; c++) {
		string one;
		one+=c;
		to_try.push_back(one);
	}
	
	for(char c='a'; c <= 'z'; c++) {
		for(char d='a'; d <= 'z'; d++) { 
			string two;
			two+=c;
			two+=d;
			to_try.push_back(two);
		}
	}

	for(int i=0; i < sz(to_try); i++) {
		bool flag = false;
		for(int j=0; j < n; j++) {
			unsigned k = titles[j].find(to_try[i]);
			if (k != string::npos) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << to_try[i] << endl;
			break;
		} 
	}
	return 0;
}