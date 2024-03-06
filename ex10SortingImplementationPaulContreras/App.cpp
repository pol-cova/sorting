//
// Created by Paul Contreras on 05/03/24.
//

#include "App.h"
// Include errors
#include "Errors.h"
// Include sorting
#include "Sorting.h"

// Function to run
void App::Run() {
    // Bool as a flag to control do-while
    bool app = true;
    // Var for store user option and array size
    int option, size;
    // Var for store user array
    int *arr = nullptr;

    // Do while
    do {
        // Call menu function to print menu
        menu();
        // Request for an option
        cout << "Select an option: ";
        cin>>option;
        // Check option with a switch
        switch (option) {
            // Fill array
            case 1:
                cout << setfill('-') << setw(40) << "" << endl;
                cout << "|           Create array           |" << endl;
                cout << setfill('-') << setw(40) << "" << endl;
                cout << "Cuantos elementos desea ingresar: ";
                cin >> size;
                // Create user array
                if (size <= 0){
                    errorZeroOrNegativeSize();
                    break;
                }
                arr = unsortedArray(size);
                break;
                // Print array
            case 2:
                cout << "Original array: ";
                printArray(arr, size);
                break;
            case 3:
                cout << "Original array: ";
                printArray(arr, size);
                // bubble sort
                bubbleSort(arr, size);
                break;
            case 4:
                cout << "Original array: ";
                printArray(arr, size);
                // insertion sort
                insertionSort(arr, size);
                break;
            case 5:
                cout << "Original array: ";
                printArray(arr, size);
                // selection sort
                selectionSort(arr, size);
                break;
            case 6:
                cout << "Original array: ";
                printArray(arr, size);
                // shell sort
                shellSort(arr, size);
                break;
            case 7:
                cout << "Original array: ";
                printArray(arr, size);
                // merge sort
                mergeSorting(arr, size);
                break;
            case 8:
                cout << "Original array: ";
                printArray(arr, size);
                // quick sort
                quickSort(arr, size);
                break;
            // Section to close do while
            case 9:
                // Bye msg
                cout << "Bye........." << endl;
                // First deallocate user array
                delete [] arr;
                // Change app bool
                app = false;
                break;
                // Default option
            default:
                cout << "Enter a valid option!!!!!"<<endl;
        }
    } while (app);
}

// Prototypes of app functions
// Menu
void menu(){
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|      Sorting algorithms by Paul     |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "| 1. Create array                     |" << endl;
    cout << "| 2. Display array                    |" << endl;
    cout << "| 3. Bubble sort                      |" << endl;
    cout << "| 4. Insertion sort                   |" << endl;
    cout << "| 5. Selection sort                   |" << endl;
    cout << "| 6. Shell sort                       |" << endl;
    cout << "| 7. Merge sort                       |" << endl;
    cout << "| 8. Quick sort                       |" << endl;
    cout << "| 9. Exit                             |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
}
// Print array
void printArray(int *arr, int size){
    // Print each element using for loop
    cout << "[" << arr[0];
    for (int i=1; i < size; ++i){
        cout << "," << arr[i];
    }
    cout << "]" << endl;
}
// Fill array
int *unsortedArray(int size){
    auto *arr = new int[size];
    for (int i = 0; i < size; ++i) {
       cout << "Ingrese elemento [" << i+1 << "]: ";
       cin >> arr[i];
    }
    return arr;
}

