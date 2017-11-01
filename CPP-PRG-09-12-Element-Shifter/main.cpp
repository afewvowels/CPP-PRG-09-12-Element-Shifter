//
//  main.cpp
//  CPP-PRG-09-12-Element-Shifter
//
//  Created by Keith Smith on 10/31/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a function that accepts an int array and the array's size as arguments. The
//  function should create a new array that is one element larger than the argument array.
//  The first element of the new array should be set to 0. Element 0 of the argument array
//  should be copied to element 2 of the new array, and so forth. The function should return a
//  pointer to the new array.

#include <iostream>

using namespace std;

int *getArraySize();
int *fillArray(int *, int);
int *modifyArray(int *, int *, int);
void displayArray(int *, int);

int main()
{
    int *intArrSize = nullptr;
    int *intArrSizeNew = nullptr;
    
    int *intArrNumbers = nullptr;
    int *intArrNumbersResized = nullptr;
    
    intArrSize = getArraySize();
    
    intArrNumbers = fillArray(intArrNumbers, *intArrSize);
    
    intArrSizeNew = new int;
    
    *intArrSizeNew = *intArrSize + 1;
    
    intArrNumbersResized = modifyArray(intArrNumbersResized, intArrNumbers, *intArrSizeNew);
    
    displayArray(intArrNumbersResized, *intArrSizeNew);
    
    return 0;
}

int *getArraySize()
{
    int *intArrSize = nullptr;
    
    intArrSize = new int;
    
    cout << "Please enter the size of the array: ";
    cin >> *intArrSize;
    while(!cin || *intArrSize <= 1 || *intArrSize > 100)
    {
        cout << "Please enter a number between 2 and 100: ";
        cin.clear();
        cin.ignore();
        cin >> *intArrSize;
    }
    
    return intArrSize;
}

int *fillArray(int *intArr, int intSize)
{
    intArr = new int[intSize];
    
    for (int i = 0 ; i < intSize ; i++)
    {
        cout << "Please enter number " << (i + 1) << " of " << intSize << ": ";
        cin >> intArr[i];
        while(!cin || intArr[i] < -100 || intArr[i] > 100)
        {
            cout << "Please enter a number between -100 and 100: ";
            cin.clear();
            cin.ignore();
            cin >> intArr[i];
        }
    }
    
    return intArr;
}

int *modifyArray(int *intArrNew, int *intArr, int intSize)
{
    intArrNew = new int[intSize];
    
    intArrNew = intArr;
    
    for (int i = intSize ; i > 0 ; i--)
    {
        swap(intArrNew[i], intArrNew[i - 1]);
    }
    
    intArrNew[0] = 0;
    
    return intArrNew;
}

void swap(int *intA, int *intB)
{
    int *intTemp = nullptr;
    
    intTemp = intA;
    intA = intB;
    intB = intTemp;
}

void displayArray(int *intArr, int intSize)
{
    for (int i = 0 ; i < intSize ; i++)
    {
        cout << "Element " << i << " of " << (intSize - 1) << ": ";
        cout << intArr[i] << endl;
    }
}
