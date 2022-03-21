//***************************************************************************
//
//  bubble_sort
//  CSCI 241 Assignment 1
//
//  Michael Marchetti z1860574
//
//***************************************************************************

//Source code written alongside supplemental lecture video provided on the course page

#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

//***************************************************************************
// define is used to allow for flexibility in the amount of space between 
// each entry and the amount of entries per line
//***************************************************************************
#define NUM_PER_LINE 8
#define NUM_WIDTH 8

int build_array(int[]);
void bubbleSort(int[], int);
void print_array(int[], int);

int main()
{
    int array[1000];
    int count;

    //read numbers into the array until end of file.

    count = build_array(array);

    bubbleSort(array, count);

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

//******************************************************************************
// the bubble sort function uses nested for loops to sort indexes in the array
// in ascending order by making single sweeping passes that loop until all
// indexes are sorted correctly. Sourced from textbook page 478  
//******************************************************************************

void bubbleSort(int array[], int n)
{
    int maxElement;
    int index;

    for (maxElement = n - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (array[index] > array[index + 1])
            {
                swap(array[index], array[index + 1]);
            }  
        }         
    }
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
