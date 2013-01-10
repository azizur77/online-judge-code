#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<string, string> ss;
#define contains(x) (floyd.find((x)) != floyd.end())


int main() {
	int N;
	cin >> N;
	int t=0;
	while(N > 0) {
		t++;
		set<string> tasks;
		set<ss> floyd;
		string s;
		for (int i=0; i < N; i++) {
			int k;
			cin >> k;
			vector<string> line;
			for (int j=0; j < k; j++) {
				cin >> s;
				tasks.insert(s);
				line.push_back(s);
			}
			for(int j=0; j < k-1; j++) {
				floyd.insert(ss(line[j], line[j+1]));
			}
		}
		int M;
		cin >> M;
		for(int i=0; i < M; i++) {
			string a, b;
			cin >> a >> b;
			tasks.insert(a);
			tasks.insert(b);
			floyd.insert(ss(a, b));
		}

		// Floyd Warshall
		vector<string> list (tasks.begin(), tasks.end());
		for(int k=0; k < list.size(); k++)
			for(int i=0; i < list.size(); i++)
				for(int j=0; j < list.size(); j++) 
					if (contains(ss(list[i], list[k])) && contains(ss(list[k], list[j]))) 
						floyd.insert(ss(list[i], list[j]));

		vector<ss> ans;
		int cnt = 0;
		for(int i=0; i < list.size(); i++)
			for(int j=i+1; j < list.size(); j++)
				if (!contains(ss(list[i], list[j])) && !contains(ss(list[j], list[i]))) {
					ans.push_back(ss(list[i], list[j]));
					cnt++;
				}

		if (cnt == 0) {
			printf("Case %d, no concurrent events.\n", t);
		}
		else {
			printf("Case %d, %d concurrent events:\n", t, cnt);
			if (cnt == 1) {
				printf("(%s,%s) \n", ans[0].first.c_str(), ans[0].second.c_str());
			}
			else {
				printf("(%s,%s) (%s,%s) \n", ans[0].first.c_str(), ans[0].second.c_str(), ans[1].first.c_str(),
				 ans[1].second.c_str());
			}

		}
		cin >> N;
	}
	return 0;
}