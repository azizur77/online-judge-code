#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> readints() {
	vector<int> res;
	char c = '\n';
	int t = 0;
	while (c == '\n') c = getchar(); // strip new lines
	while (c != '\n' && c != 0) {
		t = 0;
		while(c != ' ' && c != '\n' && c!=0) {
			t = t * 10 + (c-'0');
			c = getchar();
		}
		res.push_back(t);
		if (c != 0 && c != '\n') c = getchar();
	}
	return res;
} 

int main() {
	vector<int> line = readints();
	while(line.size() > 0 && line[0] != 0) {
		vector<int> seqA, seqB, Ax, Ay, Bx, By;
		seqA.resize(500000);
		seqB.resize(500000);
		int acnt=0, bcnt=0;
		do {
			line = readints();
			if (line.size() > 1) 
				for(int i=0; i < line.size(); i++) seqA[acnt++] = line[i];

		} while(line.size() > 1);

		do {
			line = readints();
			if (line.size() > 1) 
				for(int i=0; i < line.size(); i++) seqB[bcnt++] = line[i];
		} while(line.size() > 1);

		Ax.resize(200000);
		Ay.resize(200000);
		Bx.resize(200000);
		By.resize(200000);

		for(int i=0; i < acnt; i+=2) Ax[i/2] = seqA[i];
		for(int i=1; i < acnt; i+=2) Ay[i/2] = seqA[i];
		for(int i=0; i < bcnt; i+=2) Bx[i/2] = seqB[i];
		for(int i=1; i < bcnt; i+=2) By[i/2] = seqB[i];
		int a_size = acnt / 2, b_size = bcnt / 2;
		for(int i=0; i < acnt/2 - 1; i++) {
			if ((Ax[i] != Ax[i+1]) && (Ay[i] != Ay[i+1])) {
				Ax[a_size] = Ax[i];
				Ay[a_size++] = Ay[i+1];
				Ax[a_size] = (Ax[i+1]);
				Ay[a_size++] = (Ay[i]);
			}
		}
		for(int i=0; i < bcnt/2 - 1; i++) {
			if ((Bx[i] != Bx[i+1]) && (By[i] != By[i+1])) {
				Bx[b_size] = Bx[i];
				By[b_size++] = By[i+1];
				Bx[b_size] = (Bx[i+1]);
				By[b_size++] = (By[i]);
			}
		}
		int mindist = (int) 1e9;
		for(int i=0; i < a_size; i++)
			for(int j=0; j < b_size; j++)
				mindist = min(mindist, abs(Ax[i] - Bx[j]) + abs(Ay[i] - By[j]));
		printf("%d\n", mindist);
	}
	return 0;
}