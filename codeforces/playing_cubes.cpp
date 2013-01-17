#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int red, blue, pet1=0, vas1=0, pet2=0, vas2=0;
	cin >> red >> blue;
	vector<int> play1(red + blue, 0);
	vector<int> play2(red + blue, 0);
	
	// Start with red
	if (red > 0) {
	int left = red + blue - 1, ctr=1, r = red - 1, b = blue;
	while (left > 0) {
		if (play1[ctr-1] == 0 && b > 0) { play1[ctr] = 1; b--; }
		else if (play1[ctr-1] == 1 && r > 0) { play1[ctr] = 0; r--; }
		else if (b > 0) { play1[ctr] = 1; b--;}
		else { play1[ctr] = 0; r--; }
		ctr++;
		left--;
		if (left <= 0) break;
		if (play1[ctr-1] == 0 && r > 0) { play1[ctr] = 0; r--; }
		else if (play1[ctr-1] == 1 && b > 0) { play1[ctr] = 1; b--; }
		else if (r > 0) {play1[ctr] = 0; r--;}
		else { play1[ctr] = 1; b--; }
		ctr++;
		left--;
	}	
	}

	if (blue > 0) {
	int left = red + blue - 1, ctr=1, r = red, b = blue-1;
	play2[0] = 1;
	while (left > 0) {
		if (play2[ctr-1] == 0 && b > 0) { play2[ctr] = 1; b--; }
		else if (play2[ctr-1] == 1 && r > 0) { play2[ctr] = 0; r--; }
		else if (b > 0) { play2[ctr] = 1; b--;}
		else { play2[ctr] = 0; r--; }
		ctr++;
		left--;
		if (left <= 0) break;
		if (play2[ctr-1] == 0 && r > 0) { play2[ctr] = 0; r--; }
		else if (play2[ctr-1] == 1 && b > 0) { play2[ctr] = 1; b--; }
		else if (r > 0) {play2[ctr] = 0; r--;}
		else { play2[ctr] = 1; b--; }
		ctr++;
		left--;
	}	
	}
	for(int i=0; i < red+blue-1; i++) {
		if (play1[i] != play1[i+1]) vas1++;
		else pet1++;
		if (play2[i] != play2[i+1]) vas2++;
		else pet2++;
	} 
	// for(int i=0; i < red+blue; i++) printf("%d ", play1[i]); printf("\n");
	// for(int i=0; i < red+blue; i++) printf("%d ", play2[i]); printf("\n");
	if (pet1 > pet2) printf("%d %d\n", pet1, vas1);
	else printf("%d %d\n", pet2, vas2);
	return 0;
}