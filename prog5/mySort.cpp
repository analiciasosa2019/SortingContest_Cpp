// Analicia Sosa
// CECS325-02
// Prog5 Threads
// 04/06/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <fstream>
#include <iostream>
#include <thread>

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

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int index = low;

	for(int i = low; i <= high; i++) {
		if (arr[i] <= pivot) {
			swap(arr[index++], arr[i]);
		}
	}
	
	return --index;
}

void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

void sort(int *array) {
	quicksort(array, 0, 62'500 - 1);
}

int main(int argc, char *argv[]) {
	int SIZE = 1'000'000/16;

	if (argc < 3) {
		exit(1);
	}
	
	int arr[1'000'000];
	int* t0 = arr;
	int* t1 = arr + 62'500;
	int* t2 = arr + 125'000;
	int* t3 = arr + 187'500;
	int* t4 = arr + 250'000;
	int* t5 = arr + 312'500;
	int* t6 = arr + 375'000;
	int* t7 = arr + 437'500;
	int* t8 = arr + 500'000;
	int* t9 = arr + 562'500;
	int* t10 = arr + 625'000;
	int* t11 = arr + 687'500;
	int* t12 = arr + 750'000;
	int* t13 = arr + 812'500;
	int* t14 = arr + 875'000;
	int* t15 = arr + 937'500;
	int index = 0;
	ifstream myfile(argv[1]);
	//thread thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7;

	while(myfile) {
		myfile >> arr[index++];
	}

	thread thread0(sort, t0);
	thread thread1(sort, t1);
	thread thread2(sort, t2);
	thread thread3(sort, t3);
	thread thread4(sort, t4);
	thread thread5(sort, t5);
	thread thread6(sort, t6);
	thread thread7(sort, t7);
	thread thread8(sort, t8);
	thread thread9(sort, t9);
	thread thread10(sort, t10);
	thread thread11(sort, t11);
	thread thread12(sort, t12);
	thread thread13(sort, t13);
	thread thread14(sort, t14);
	thread thread15(sort, t15);

	thread0.join();
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();
	thread6.join();
	thread7.join();
	thread8.join();
	thread9.join();
	thread10.join();
	thread11.join();
	thread12.join();
	thread13.join();
	thread14.join();
	thread15.join();

	thread threada(merge, arr, SIZE);
	thread threadb(merge, arr + 2 * SIZE, SIZE);
	thread threadc(merge, arr + 4 * SIZE, SIZE);
	thread threadd(merge, arr + 6 * SIZE, SIZE);
	thread threade(merge, arr + 8 * SIZE, SIZE);
	thread threadf(merge, arr + 10 * SIZE, SIZE);
	thread threadg(merge, arr + 12 * SIZE, SIZE);
	thread threadh(merge, arr + 14 * SIZE, SIZE);
	
	threada.join();
	threadb.join();
	threadc.join();
	threadd.join();
	threade.join();
	threadf.join();
	threadg.join();
	threadh.join();

	thread threadA(merge, arr, 2 * SIZE);
	thread threadB(merge, arr + 4 * SIZE, 2 * SIZE);
	thread threadC(merge, arr + 8 * SIZE, 2 * SIZE);
	thread threadD(merge, arr + 12 * SIZE, 2 * SIZE);
	
	threadA.join();
	threadB.join();
	threadC.join();
	threadD.join();

	thread threadE(merge, arr, 4 * SIZE);
	thread threadF(merge, arr + 8 * SIZE, 4 * SIZE);
	
	threadE.join();
	threadF.join();

	merge(arr, 8 * SIZE);

	for (int i = 0; i < 999'999; i++) {
		cout << arr[i];
	}

}



