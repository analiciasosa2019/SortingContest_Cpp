// Analicia Sosa
// CECS 325-02
// Prog 2 - Sort Race
// 3/7/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program. 

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 3) {
		exit(1);
	}

	int numbers[1'000'000];
	int index = 0;

	ifstream myfile(argv[1]);
	while (myfile) {
		myfile >> numbers[index++];
	}
	index-=1;
	
	for (int i = index-1; i > -1; i--) {
		for (int j = i; j > -1; j--) {
			if (numbers[j] > numbers[i]) {
				swap(numbers[i], numbers[j]);
			}	
		}
	}
	
	ofstream outputfile(argv[2]);
	for (int i = 0; i < index; i++) {
		outputfile << numbers[i] << endl;
	}
}
