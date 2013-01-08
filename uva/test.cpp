#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

int main() {
	string test = "8: 89 22";
	stringstream st(test);
	int g;
	int k = ((int) (st >> g));

	printf("%d %d\n", k, g); 
	return 0;
}