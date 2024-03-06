//
// Created by Paul Contreras on 05/03/24.
//

#ifndef EX10SORTINGIMPLEMENTATION_APP_H
#define EX10SORTINGIMPLEMENTATION_APP_H

// Standard libraries
#include <iomanip>
#include <iostream>
using namespace std;

class App {
    // Function to run app
public:
    static void Run();
};

// Prototypes of app functions
// Menu
void menu();
// Print array
void printArray(int *arr, int size);
// Fill array
int *unsortedArray(int size);

#endif //EX10SORTINGIMPLEMENTATION_APP_H
