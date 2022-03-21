#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

#define NUM_PER_LINE 8
#define NUM_WIDTH 8

int build_array(int[]);
void sort_array(int[], int);
void print_array(int[], int);

int main()
{
    int array[1000];
    int count;

    //read numbers into the array until end of file.

    count = build_array(array);

    sort_array(array, count);

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
void sort_array(int array[], int n)
{
    int min_index;
    //int temp;
    
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
 
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        swap(array[i], array[min_index]);
        /*
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
        */
    }
}
void print_array(int array[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        cout << setw(NUM_WIDTH) << array[i];

        if ((i+1) % NUM_PER_LINE)
	{
	    cout << endl;
	}
    }

    if (i % NUM_PER_LINE != 0)
        cout << endl;
}
