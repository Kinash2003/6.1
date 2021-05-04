// Lab.6.1.cpp 
#include <time.h>
#include <iostream>
#include "Array.h"

Array Array1(int arr[], const int size);

int main()
{
    srand((unsigned)time(NULL));
    const int size = 50;
    int arr[size];
  
    for (int i = 0; i < size; i++)
        arr[i] = -50 + rand() % int(50 - (-50) + 1);  
    Array taskArray = Array1(arr, size);
    taskArray.Print();
    taskArray.Subtract();
    taskArray.Print();

    return 0;
}
Array Array1(int arr[], const int size)
{
    Array dynamicArray = Array(size);

    for (int i = 0; i < size; i++)
        dynamicArray[i] = arr[i];

    return dynamicArray;
}