//
// Created by Paul Contreras on 05/03/24.
//

#ifndef EX10SORTINGIMPLEMENTATION_SORTING_H
#define EX10SORTINGIMPLEMENTATION_SORTING_H

#include <iomanip>
#include <iostream>
#include <chrono>
// APP Func
#include "App.h"
using namespace std;

// Bubble sort
void bubbleSort(const int *userArray, int size);
// Insertion sort
void insertionSort(const int *userArray, int size);
// Selection sort
void selectionSort(const int *userArray, int size);
// Sell sort
void shellSort(const int *userArray, int size);
// Merge sort
void merge(int *sortedArray, int low, int mid, int high);
void mergeSort(int *sortedArray, int low, int high) ;
void mergeSorting(const int *userArray, int size);
// Quick sort
void swap(int *a, int *b);
int part(int *sortedArray, int low, int high);
void quickS(int *sortedArray, int low, int high);
void quickSort(const int *userArray, int size);




#endif //EX10SORTINGIMPLEMENTATION_SORTING_H
