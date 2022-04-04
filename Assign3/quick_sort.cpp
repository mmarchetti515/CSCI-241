//***************************************************************************
//
//  quick_sort
//  CSCI 241 Assignment 3
//
//  Michael Marchetti z1860574
//
//***************************************************************************

//***************************************************************************
// Source code written alongside supplemental lecture video provided on the course page.
// Source code taken from previous assignments due to similar nature in formatting
// and input/ output.
//***************************************************************************

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <fstream>

using namespace std;

//***************************************************************************
// define is used to allow for flexibility in the amount of space between 
// each entry and the amount of entries per line
//***************************************************************************

#define NUM_PER_LINE 8
#define NUM_WIDTH 8

int build_array(int[]);
void quickSort(int[], int);
void print_array(int[], int);

int main()
{
    int array[1000];
    int count;

    //read numbers into the array until end of file.

    count = build_array(array);

    quickSort(array, count);

    //Print the values in the array.

    print_array(array, count);

    return 0;
}

int build_array(int array[])
{
    int count = 0;
    
    while (cin >> array[count])
    {
        count++;
    }

    return count;
}

//***************************************************************************
// insertion sort algorithm obtained from pseudocode available in the course 
// material page
//***************************************************************************

int partition(int array[], int start, int end)
{
    int mid = (start + end)/2;

    swap(array[start] && array[mid])
    {
        int pivotIndex = start;
        int pivotValue = array[start];
        int scan = start + 1;

        while(scan <= end)
        {
            if(array[scan] < pivotValue)
            {
                int pivotIndex = pivotIndex + 1;
                
                swap(array[pivotIndex] && array[scan])
            }
            int scan = scan + 1;
        }      
    }
    return 0;
}

void quickSort(int array[], int start, int end)
{
    if (start < end) 
    {
        int pivotPoint = partition(array, start, end);
        quickSort(array, start, pivotPoint - 1);
        quickSort(array, pivotPoint + 1, end);
    }
    return 0;
}



void print_array(int array[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        cout << setw(NUM_WIDTH) << array[i];

        if ((i+1) % NUM_PER_LINE == 0)
            cout << endl;
    }

    if (i % NUM_PER_LINE != 0)
        cout << endl;
}