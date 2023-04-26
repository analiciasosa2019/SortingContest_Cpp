// Analicia Sosa
// CECS325-02
// Prog4 Pthreads
// 3/21/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <fstream>
#include <iostream>
#include <pthread.h>

using namespace std;


void merge(int *array, int num) {

	int i = 0, j = num;
	int sorted[2 * num];
	for (int k = 0; k < 2 * num; k++) {	
		if ((array[i] > array[j] && j < 2 * num) || i >= num) {
			sorted[k] = array[j++];
		}
		else {
			sorted[k] = array[i++];
		}
	}
	copy(sorted, sorted + ((2 * num)), array);
}

void *sort(void *array) {
	int num = 125'000;

	for (int i = num - 1; i > -1; i--) {
		for (int j = i; j > -1; j--) {
			if (((int*)array)[i] < ((int*)array)[j]) swap(((int*)array)[i], ((int*)array)[j]);
		}
	}
	return array;
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		exit(1);
	}
	
	int arr[1'000'000];
	void* t0 = arr;
	void* t1 = arr + 125'000;
       	void* t2 = arr + 250'000;
	void* t3 = arr + 375'000;
	void* t4 = arr + 500'000;
	void* t5 = arr + 625'000;
	void* t6 = arr + 750'000; 
	void* t7 = arr + 875'000;
	int index = 0;
	ifstream myfile(argv[1]);
	pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7;
	int iret0, iret1, iret2, iret3, iret4, iret5, iret6,  iret7;

	while(myfile) {
		myfile >> arr[index++];
	}
	index--;

	iret0 = pthread_create (&thread0, NULL, sort, t0);
	iret1 = pthread_create (&thread1, NULL, sort, t1);
	iret2 = pthread_create (&thread2, NULL, sort, t2);
	iret3 = pthread_create (&thread3, NULL, sort, t3);
	iret4 = pthread_create (&thread4, NULL, sort, t4);
	iret5 = pthread_create (&thread5, NULL, sort, t5);
	iret6 = pthread_create (&thread6, NULL, sort, t6);
	iret7 = pthread_create (&thread7, NULL, sort, t7);

	pthread_join (thread0, NULL);
	pthread_join (thread1, NULL);
	pthread_join (thread2, NULL);
	pthread_join (thread3, NULL);
	pthread_join (thread4, NULL);
	pthread_join (thread5, NULL);
	pthread_join (thread6, NULL);
	pthread_join (thread7, NULL);
	
	merge(arr, 125'000);
	merge(arr + 250'000, 125'000);
	merge(arr + 500'000, 125'000);
	merge(arr + 750'000, 125'000);
	
	merge(arr, 250'000);
	merge(arr + 500'000, 250'000);
	
	merge(arr, 500'000);

	ofstream outputfile(argv[2]);
	for (int i = 0; i < index; i++) {
		outputfile << arr[i];
		if (i != index) outputfile << endl;
	}

}



