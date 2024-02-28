//
// Created by Paul Contreras on 24/02/24.
//

#include "Sorting.h"
// Libraries
#include <iomanip>
#include <iostream>
#include <chrono>
using namespace std;

// General functions
// Menu function
void menu(){
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|        Sorting and Searching        |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "| 1. Linear Search                    |" << endl;
    cout << "| 2. Binary Search                    |" << endl;
    cout << "| 3. Insertion sort                   |" << endl;
    cout << "| 4. Bubble sort                      |" << endl;
    cout << "| 5. Selection sort                   |" << endl;
    cout << "| 6. Fill array                       |" << endl;
    cout << "| 7. Exit                             |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
}
// Print array function
void printArray( const float *userArray , int size){
    // Print each element using for loop
    cout << "[" << userArray[0];
    for (int i=1; i < size; ++i){
        cout << "," << userArray[i];
    }
    cout << "]" << endl;
}
// #########################
// Fill array section
// Return size of array and print header
int fillArrayHeader(){
    int size;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Llenar arreglo             |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> size;
    if (size > 0){
        return size;}
    else{
        cout << "ERROR ingreso una cantidad negativa o 0" << endl;
        cout << "Ingrese nuevamente la cantidad de elementos: ";
        cin >> size;
        if (size > 0)
            return size;
    }
    return 1;
}
// Fill array
void fillArray(float *userArray, int size){
    // For loop to enter elements
    for (int i = 0; i < size; ++i) {
        cout << "Ingrese elemento " << i+1 << " : ";
        cin >> userArray[i];
    }
}

// ##########################
// Search section
// Linear search main section
void linearSearchSection(const float *userArray, int size){
    // Define temp variable to store the element to find
    float element;
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Busqueda secuencial          |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Ingrese el elemento a buscar: ";
    cin >> element;
    linearSearch(userArray, size, element);
}
// Binary search main section
void binarySearchSection(const float *userArray, int size){
    // Define temp variable to store the element to find
    float element;
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Busqueda binaria          |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Ingrese el elemento a buscar: ";
    cin >> element;
    // Sort array
    float *sorted = sortedArray(userArray, size);
    int index = binarySearch(sorted,element,0,size-1);
    if (index == -1){
        cout << "Elemento no encontrado en el arreglo" << endl;
    } else{
        cout << "Elemento [" << element << "] encontrado en la posicion: " << index+1 << endl;
    }
    delete [] sorted;
}
// Linear search
/*
 * This function iterate over the array and stop when found the specific element
 */
void linearSearch(const float *userArray, int size, float element){
    // For loop to iterate over the array
    // This bool is for check if element was found
    bool find = false;
    // This section start a clock to measure the time to find some item
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i < size; ++i){
        // Compare element in [i] position with the user element, if match break the loop
        if(userArray[i] == element){
            cout << "Elemento [" << element << "] encontrado en la posicion: " << i+1 << endl;
            // Change the bool
            find = true;
        }
    }
    if (!find){
        cout << "Elemento no encontrado en el arreglo" << endl;
    }else {
        // Here print time that takes to find specific element
        // This section stop a clock to measure the time to find some item
        auto end = chrono::high_resolution_clock::now();
        auto exec = chrono::duration_cast<chrono::microseconds>(end-start).count();
        cout << "Elemento encontrado en: " << exec << " microsegundos" <<endl;
    }
}
// Binary search
/*
 * This function part in half the array and compare if element is in the low or in the high section,
 * do the same until found element
 */
int binarySearch(const float *userArray, float element, int low, int high){
    // This section start a clock to measure the time to find some item
    auto start = chrono::high_resolution_clock::now();
    while(low <= high){
        // Calculate the index of the middle element
        int med = low + (high - low) / 2;
        // Section to check if element is found
        if (element == userArray[med]){
            // Here print time that takes to find specific element
            // This section stop a clock to measure the time to find some item
            auto end = chrono::high_resolution_clock::now();
            auto exec = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
            cout << "Elemento encontrado en: " << exec << " nanosegundos" <<endl;
            return med;
        }
        // If element is higher right part
        if (element > userArray[med]){
            low = med + 1;
        }
        // If element is lower search in left part
        if (element < userArray[med]){
            high = med - 1;
        }
    }
    return -1;
}

// ##########################
// Sorting section
// Insertion sort
void insertionSort(const float *userArray, int size){
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Insertion sort          |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    auto *sortedArray = new float[size];

    // Copy the original user array
    for (int i=0; i<size; ++i){
        sortedArray[i] = userArray[i];
    }
    // This section start a clock to measure the time to sort array
    auto start = chrono::high_resolution_clock::now();
    // Insertion algorithm
    for (int i=1; i<size; ++i){
        float k = sortedArray[i];
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
// Bubble sort
void bubbleSort(const float *userArray, int size){
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Bubble sort           |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    auto *sortedArray = new float[size];

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
                float temp = sortedArray[j];
                sortedArray[j] = sortedArray[j+1];
                sortedArray[j+1] = temp;
            }
        }
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
// Selection sort
void selectionSort(const float *userArray, int size){
    // Print header
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|           Bubble sort           |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    auto *sortedArray = new float[size];

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
            float temp = sortedArray[i];
            sortedArray[i] = sortedArray[mIndex];
            sortedArray[mIndex] = temp;
        }
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
// Sorted array
float* sortedArray(const float *userArray, int size){
    auto *sortedArray = new float[size];

    // Copy the original user array
    for (int i=0; i<size; ++i){
        sortedArray[i] = userArray[i];
    }
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
            float temp = sortedArray[i];
            sortedArray[i] = sortedArray[mIndex];
            sortedArray[mIndex] = temp;
        }
    }
    return sortedArray;
}

// ##########################
// Errors and exceptions handling
// This error print a msg because users try to select sort or search option, without filling the array
void emptyArrERROR(){
    cout << "Array sin elementos, selecciona option 6 para llenarlo! " <<endl;
}