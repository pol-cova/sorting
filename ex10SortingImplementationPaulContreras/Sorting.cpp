//
// Created by Paul Contreras on 05/03/24.
//

#include "Sorting.h"

// Bubble sort
void bubbleSort(const int *userArray, int size){
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Bubble sort           |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    auto *sortedArray = new int[size];

    // Copy the original user array
    for (int i=0; i<size; ++i){
        sortedArray[i] = userArray[i];
    }
    // This section start a clock to measure the time to sort array
    auto start = chrono::high_resolution_clock::now();
    // Bubble sort  algorithm
    for(int i=0; i<size-1; ++i){
        for(int j=0; j < size - i - 1; ++j){
            if (sortedArray[j] > sortedArray[j+1]){
                //Swap
                int temp = sortedArray[j];
                sortedArray[j] = sortedArray[j+1];
                sortedArray[j+1] = temp;
            }
        }
    }
    // This section stop a clock to measure the time to sort arr
    auto end = chrono::high_resolution_clock::now();
    auto exec = chrono::duration_cast<chrono::nanoseconds>(end-start).count();


    // Print results
    cout << endl;
    cout << "Sorted array: ";
    printArray(sortedArray,size);
    cout << endl;
    cout << "Array ordenado en: " << exec << " nanosegundos " <<endl;
    // Deallocate memory
    delete [] sortedArray;
}
// Insertion sort
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
    cout << endl;
    cout << "Sorted array: ";
    printArray(sortedArray,size);
    cout << endl;
    cout << "Array ordenado en: " << exec << " nanosegundos " <<endl;
    // Deallocate memory
    delete [] sortedArray;
}
// Selection sort
void selectionSort(const int *userArray, int size){
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Selection sort           |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    auto *sortedArray = new int[size];

    // Copy the original user array
    for (int i=0; i<size; ++i){
        sortedArray[i] = userArray[i];
    }
    // This section start a clock to measure the time to sort array
    auto start = chrono::high_resolution_clock::now();
    // Selection sort  algorithm
    for (int i=0; i<size - 1; ++i){
        // Define min index
        int mIndex = i;
        for (int j= i + 1; j <size; ++j){
            if (sortedArray[j] < sortedArray[mIndex]){
                mIndex = j;
            }
        }
        // Swap elements
        if (mIndex != i){
            int temp = sortedArray[i];
            sortedArray[i] = sortedArray[mIndex];
            sortedArray[mIndex] = temp;
        }
    }
    // This section stop a clock to measure the time to sort arr
    auto end = chrono::high_resolution_clock::now();
    auto exec = chrono::duration_cast<chrono::nanoseconds>(end-start).count();


    // Print results
    cout << endl;
    cout << "Sorted array: ";
    printArray(sortedArray,size);
    cout << endl;
    cout << "Array ordenado en: " << exec << " nanosegundos " <<endl;
    // Deallocate memory
    delete [] sortedArray;
}
// Sell sort
void shellSort(const int *userArray, int size){
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Shell sort           |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    auto *sortedArray = new int[size];

    // Copy the original user array
    for (int i=0; i<size; ++i){
        sortedArray[i] = userArray[i];
    }
    // This section start a clock to measure the time to sort array
    auto start = chrono::high_resolution_clock::now();

    // Shell sort algorithm
    for (int index = size /2; index > 0 ; index /= 2){
        for (int i = index; i < size; i += 1){
            int temp = sortedArray[i];
            int j;
            for (j = i; j>= index && sortedArray[j-index] > temp; j -= index){
                sortedArray[j] = sortedArray[j-index];
            }
            sortedArray[j] = temp;
        }
    }
    // This section stop a clock to measure the time to sort arr
    auto end = chrono::high_resolution_clock::now();
    auto exec = chrono::duration_cast<chrono::nanoseconds>(end-start).count();


    // Print results
    cout << endl;
    cout << "Sorted array: ";
    printArray(sortedArray,size);
    cout << endl;
    cout << "Array ordenado en: " << exec << " nanosegundos " <<endl;
    // Deallocate memory
    delete [] sortedArray;
}
// Merge sort
void merge(int *sortedArray, int low, int mid, int high) {
    int sizeL = mid - low + 1;
    int sizeR = high - mid;

    // Temporary arrays
    int arrL[sizeL], arrR[sizeR];

    // Copy data to temporary arrays
    for (int i = 0; i < sizeL; ++i) {
        arrL[i] = sortedArray[low + i];
    }
    for (int j = 0; j < sizeR; ++j) {
        arrR[j] = sortedArray[mid + 1 + j];
    }

    // Merge the temporary arrays back into sortedArray
    int i = 0, j = 0, k = low;
    while (i < sizeL && j < sizeR) {
        if (arrL[i] <= arrR[j]) {
            sortedArray[k] = arrL[i];
            i++;
        } else {
            sortedArray[k] = arrR[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of arrL[], if there are any
    while (i < sizeL) {
        sortedArray[k] = arrL[i];
        i++;
        k++;
    }

    // Copy the remaining elements of arrR[], if there are any
    while (j < sizeR) {
        sortedArray[k] = arrR[j];
        j++;
        k++;
    }
}

void mergeSort(int *sortedArray, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Sort first and second halves
        mergeSort(sortedArray, low, mid);
        mergeSort(sortedArray, mid + 1, high);

        // Merge the sorted halves
        merge(sortedArray, low, mid, high);
    }
}

void mergeSorting(const int *userArray, int size){
    int *sortedArray = new int[size];

    // Copy the original user array
    for (int i = 0; i < size; ++i) {
        sortedArray[i] = userArray[i];
    }
    // Perform merge sort
    mergeSort(sortedArray, 0, size - 1);
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Merge sort           |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    // Print results
    cout << endl;
    cout << "Sorted array: ";
    printArray(sortedArray,size);
    // Deallocate memory
    delete [] sortedArray;
}
// Quick sort
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int *sortedArray, int low, int high){
    int pivote = sortedArray[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++){
        if (sortedArray[j] <= pivote){
            i++;
            swap(&sortedArray[i], &sortedArray[j]);
        }
    }
    swap(&sortedArray[i+1], &sortedArray[high]);
    return i+1;
}
void quickS(int *sortedArray, int low, int high){
    if (low < high){
        int p1 = part(sortedArray, low, high);
        quickS(sortedArray, low, p1 - 1);
        quickS(sortedArray, p1+1, high);
    }
}
void quickSort(const int *userArray, int size){
    int *sortedArray = new int[size];

    // Copy the original user array
    for (int i = 0; i < size; ++i) {
        sortedArray[i] = userArray[i];
    }
    // Perform quick sort
    quickS(sortedArray, 0, size - 1);

    // Print results
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Quick sort           |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << endl;
    cout << "Sorted array: ";
    printArray(sortedArray,size);
    // Deallocate memory
    delete [] sortedArray;
}