// Analicia Sosa
// CECS 325-02
// Prog4 - Pthreads
// 3/21/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program. 

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	if (argc < 4) {
		exit(1);
	}
	
	ofstream numbers;
	numbers.open("numbers.dat");

	int nums = stoi(argv[1]);

	for (int i = 0; i < stoi(argv[1]); i++) {
		numbers << stoi(argv[2]) + rand() % (stoi(argv[3]) - stoi(argv[2]));
		if (i != nums) numbers << endl;
	}
	
	numbers.close();
	return 0;
}
