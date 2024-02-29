#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

// Definitions
void printArray( const int *userArray , int size);
void fillArray(int *userArray, int size);
void insertionSort(const int *userArray, int size);

// Print array function
void printArray( const int *userArray , int size){
    // Print each element using for loop
    cout << "[" << userArray[0];
    for (int i=1; i < size; ++i){
        cout << "," << userArray[i];
    }
    cout << "]" << endl;
}

// Fill array
void fillArray(int *userArray, int size){
    // For loop to enter elements
    for (int i = 0; i < size; ++i) {
        cout << "Ingrese elemento " << i+1 << " : ";
        cin >> userArray[i];
    }
}

// Insertion algorithm
void insertionSort(const int *userArray, int size){
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Insertion sort          |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    auto *sortedArray = new int[size];

    // Copy the original user array
    for (int i=0; i<size; ++i){
        sortedArray[i] = userArray[i];
    }
    // This section start a clock to measure the time to sort array
    auto start = chrono::high_resolution_clock::now();
    // Insertion algorithm
    for (int i=1; i<size; ++i){
        int k = sortedArray[i];
        int j = i-1;
        while (j >= 0 && sortedArray[j] > k){
            sortedArray[j+1] = sortedArray[j];
            --j;
        }
        sortedArray[j+1] = k;
    }
    // This section stop a clock to measure the time to sort arr
    auto end = chrono::high_resolution_clock::now();
    auto exec = chrono::duration_cast<chrono::nanoseconds>(end-start).count();


    // Print results
    cout << "Original array: ";
    printArray(userArray,size);
    cout << endl;
    cout << "Sorted array: ";
    printArray(sortedArray,size);
    cout << endl;
    cout << "Array ordenado en: " << exec << " nanosegundos " <<endl;
    // Deallocate memory
    delete [] sortedArray;
}
int main(){
	int size;
	int *array;
	
	cout << "Ingrese la cantidad de elementos para su arreglo: ";
	cin >> size;
	// Definimos arreglo
	array = new int[size];
	// Fill array
    fillArray(array, size);
	// Sorted Array
    insertionSort(array, size);
	// deallocate memory
	delete [] array;
	return 0;
}
