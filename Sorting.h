//
// Created by Paul Contreras on 24/02/24.
//

#ifndef EX_9_M_ORD_C_PAULCONTRERAS_SORTING_H
#define EX_9_M_ORD_C_PAULCONTRERAS_SORTING_H

// General functions
// Menu function
// This function print menu options
void menu();
// Print array function
// This function print the elements of the array
void printArray(const float *userArray , int size);
// ##########################
// Fill array section
// Fill array header this function return size of array
int fillArrayHeader();
// Fill array function
// This function get pointer
void fillArray(float *userArray, int size);
// ##########################
// Search section
// Linear search main section
void linearSearchSection(const float *userArray, int size);
// Binary search main section
void binarySearchSection(const float *userArray, int size);
// Linear search
/*
 * This function iterate over the array and stop when found the specific element
 */
void linearSearch(const float *userArray, int size, float element);
// Binary search
/*
 * This function part in half the array and compare if element is in the low or in the high section,
 * do the same until found element
 */
int binarySearch(const float *userArray, float element, int low, int high);

// ##########################
// Sorting section
// Insertion sort
void insertionSort(const float *userArray, int size);
// Bubble sort
void bubbleSort(const float *userArray, int size);
// Selection sort
void selectionSort(const float *userArray, int size);
// Sorted array
float* sortedArray(const float *userArray, int size);


// ##########################
// Errors and exceptions handling
void emptyArrERROR();


#endif //EX_9_M_ORD_C_PAULCONTRERAS_SORTING_H
