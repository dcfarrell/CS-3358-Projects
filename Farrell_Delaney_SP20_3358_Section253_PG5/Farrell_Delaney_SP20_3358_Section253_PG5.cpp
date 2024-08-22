// Serial Number : 9
//
// Author : Delaney Farrell
// Due Date : 4/20/2020
// Programming Assignment Number 5
//
// Spring 2020 - CS 3358 - 253
//
// Instructor: Husain Gholoom.
//
// Program to test different sorting and searching functions

#include <iostream>
#include <ctime>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;

//*******************************************************************
// void PrintArray(const char arr[], int size)
//
// Parameter(s): const char arr[], int size
// Return: void
// Prints char array up to 20
//*******************************************************************
void PrintArray(const char arr[], int size);

//*******************************************************************
// int SequentialSearch(int target, char arr[], int size)
//
// Parameter(s): char arr[], int size, int target
// Return: int
// Sequentially searches array for the target
//*******************************************************************
int SequentialSearch(int target, char arr[], int size);

//*******************************************************************
// int SelectionSort(int size, char arr[])
//
// Parameter(s): char arr[], int size
// Return: int
// Uses selection sort algorithm on array
//*******************************************************************
int SelectionSort(int size, char arr[]);

//*******************************************************************
// int InsertionSort(int size, char arr[])
//
// Parameter(s): char arr[], int size
// Return: int
// Uses insertion sort algorithm on array
//*******************************************************************
int InsertionSort(int size, char arr[]);

//*******************************************************************
// void QuickSortMid(char arr[], int left, int right, int& count);
//
// Parameter(s): char arr[], int left, int right, int& count
// Return: void
// Uses quick sort algorithm on array, middle pivot
//*******************************************************************
void QuickSortMid(char arr[], int left, int right, int& count);

//*******************************************************************
// void QuickSortMid(char arr[], int left, int right, int& count);
//
// Parameter(s): char arr[], int left, int right, int& count
// Return: void
// Uses quick sort algorithm on array, middle - 1 pivot
//*******************************************************************
void QuickSortMidMinusOne(char arr[], int left, int right, int& count);

//*******************************************************************
// void QuickSortMid(char arr[], int left, int right, int& count);
//
// Parameter(s): char arr[], int left, int right, int& count
// Return: void
// Uses quick sort algorithm on array, front pivot
//*******************************************************************
void QuickSortFirst(char arr[], int left, int right, int& count);

//*******************************************************************
// void QuickSortMid(char arr[], int left, int right, int& count);
//
// Parameter(s): char arr[], int left, int right, int& count
// Return: void
// Uses quick sort algorithm on array, last pivot
//*******************************************************************
void QuickSortLast(char arr[], int left, int right, int& count);

int main()
{
    srand(time(0)); // Seeding rand

    char* arr; // dynamic array for randomly generated values
    char* initialArr;
    int arrSize; // user input for size of the array
    int count = 0; // used for counting # of recursions

    cout << "Searching / Sorting Benchmark\n\n" << endl;

    cout << "Enter the size of the array:\t";
    cin >> arrSize;
    cout << endl;

    if(arrSize > 4)
    {

        arr = new char[arrSize];
        initialArr = new char[arrSize];

        for(int i = 0; i < arrSize; i++)
        {
            arr[i] = ((rand() % 126) + 33);
        }

        memcpy(initialArr, arr, arrSize);

        cout << "Array elements are : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;

        // Sequential Search for 80
        cout << "Sequential Search :\n" << endl;
        cout << "Searching for 80\n" << endl;
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        auto start = high_resolution_clock::now();
        int numTimes80 = SequentialSearch(80, arr, arrSize);
        auto stop = high_resolution_clock::now();
        auto timenow2 = chrono::system_clock::to_time_t(chrono::system_clock::now());
        auto duration = duration_cast< milliseconds>(stop - start);
        if(numTimes80 > 0)
        {
            cout << "80 Was Found." << endl;
        }
        else
        {
            cout << "80 Was Not Found." << endl;
        }
        cout << "Start Time : " << ctime(&timenow);
        cout << "End Time : " << ctime(&timenow2);
        cout << "Actual CPU Clock Time : " << duration.count() << " milliseconds" << endl;
        cout << "Total Number of char 80 : " << numTimes80 << endl;
        cout << "Array Elements : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;
        memcpy(arr, initialArr, arrSize);

        // Selection Sort
        cout << "Selection Sort :\n" << endl;
        timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        start = high_resolution_clock::now();
        int numSwaps = SelectionSort(arrSize, arr);
        stop = high_resolution_clock::now();
        timenow2 = chrono::system_clock::to_time_t(chrono::system_clock::now());
        duration = duration_cast< milliseconds>(stop - start);
        cout << "Start Time : " << ctime(&timenow);
        cout << "End Time : " << ctime(&timenow2);
        cout << "Actual CPU Clock Time : " << duration.count() << " milliseconds" << endl;
        cout << "Total Number of Swaps : " << numSwaps << endl;
        cout << "Sorted Elements : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;
        memcpy(arr, initialArr, arrSize);

        // Insertion Sort
        cout << "Insertion Sort :\n" << endl;
        timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        start = high_resolution_clock::now();
        int numComp = InsertionSort(arrSize, arr);
        stop = high_resolution_clock::now();
        timenow2 = chrono::system_clock::to_time_t(chrono::system_clock::now());
        duration = duration_cast< milliseconds>(stop - start);
        cout << "Start Time : " << ctime(&timenow);
        cout << "End Time : " << ctime(&timenow2);
        cout << "Actual CPU Clock Time : " << duration.count() << " milliseconds" << endl;
        cout << "Total Number of Comparisons : " << numComp << endl;
        cout << "Sorted Elements : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;
        memcpy(arr, initialArr, arrSize);

        // Quick Sort - Middle Element
        cout << "Quick Sort - The middle element as a pivot :\n" << endl;
        timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        start = high_resolution_clock::now();
        QuickSortMid(arr, 1, arrSize - 1, count);
        stop = high_resolution_clock::now();
        timenow2 = chrono::system_clock::to_time_t(chrono::system_clock::now());
        duration = duration_cast< milliseconds>(stop - start);
        cout << "Start Time : " << ctime(&timenow);
        cout << "End Time : " << ctime(&timenow2);
        cout << "Actual CPU Clock Time : " << duration.count() << " milliseconds" << endl;
        cout << "Number of Recursive calls : " << count << endl;
        cout << "Sorted Elements : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;
        memcpy(arr, initialArr, arrSize);
        count = 0;

        // Quick Sort - Middle Element - 1
        cout << "Quick Sort - The middle - 1 element as a pivot :\n" << endl;
        timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        start = high_resolution_clock::now();
        QuickSortMidMinusOne(arr, 1, arrSize - 1, count);
        stop = high_resolution_clock::now();
        timenow2 = chrono::system_clock::to_time_t(chrono::system_clock::now());
        duration = duration_cast< milliseconds>(stop - start);
        cout << "Start Time : " << ctime(&timenow);
        cout << "End Time : " << ctime(&timenow2);
        cout << "Actual CPU Clock Time : " << duration.count() << " milliseconds" << endl;
        cout << "Number of Recursive calls : " << count << endl;
        cout << "Sorted Elements : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;
        memcpy(arr, initialArr, arrSize);
        count = 0;

        // Quick Sort - First Element
        cout << "Quick Sort - first element as a pivot :\n" << endl;
        timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        start = high_resolution_clock::now();
        QuickSortFirst(arr, 1, arrSize - 1, count);
        stop = high_resolution_clock::now();
        timenow2 = chrono::system_clock::to_time_t(chrono::system_clock::now());
        duration = duration_cast< milliseconds>(stop - start);
        cout << "Start Time : " << ctime(&timenow);
        cout << "End Time : " << ctime(&timenow2);
        cout << "Actual CPU Clock Time : " << duration.count() << " milliseconds" << endl;
        cout << "Number of Recursive calls : " << count << endl;
        cout << "Sorted Elements : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;
        memcpy(arr, initialArr, arrSize);
        count = 0;

        // Quick Sort - Last Element
        cout << "Quick Sort - last element as a pivot :\n" << endl;
        timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        start = high_resolution_clock::now();
        QuickSortLast(arr, 1, arrSize - 1, count);
        stop = high_resolution_clock::now();
        timenow2 = chrono::system_clock::to_time_t(chrono::system_clock::now());
        duration = duration_cast< milliseconds>(stop - start);
        cout << "Start Time : " << ctime(&timenow);
        cout << "End Time : " << ctime(&timenow2);
        cout << "Actual CPU Clock Time : " << duration.count() << " milliseconds" << endl;
        cout << "Number of Recursive calls : " << count << endl;
        cout << "Sorted Elements : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;

        // Sequential search for 80 after sort
        cout << "Sequential Search for 80 After Sort\n" << endl;
        cout << "Searching for 80\n" << endl;
        timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        start = high_resolution_clock::now();
        numTimes80 = SequentialSearch(80, arr, arrSize);
        stop = high_resolution_clock::now();
        timenow2 = chrono::system_clock::to_time_t(chrono::system_clock::now());
        duration = duration_cast< milliseconds>(stop - start);
        if(numTimes80 > 0)
        {
            cout << "80 Was Found." << endl;
        }
        else
        {
            cout << "80 Was Not Found." << endl;
        }
        cout << "Start Time : " << ctime(&timenow);
        cout << "End Time : " << ctime(&timenow2);
        cout << "Actual CPU Clock Time : " << duration.count() << " milliseconds" << endl;
        cout << "Total Number of char 80 : " << numTimes80 << endl;
        cout << "Array Elements : ";
        PrintArray(arr, arrSize);
        cout << "\n" << endl;

        // Exit Message
        cout << "4 - 2020\n"
             "Sorting / Searching Benchmark by :\n"
             "Delaney Farrell" << endl;

        // deletes dynamically allocated array
        delete [] arr;
        arr = NULL;
        delete [] initialArr;
        initialArr = NULL;

    }
    else
    {
        cout << " *** Error - Invalid input - Size must be > 4 *** \n" << endl;
    }
    return 0;
}

void PrintArray(const char arr[], int size)
{

    if(size >= 20)
    {
        for(int i = 0; i < 20; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int SequentialSearch(int target, char arr[], int size)
{
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == 80)
        {
            count++;
        }
    }

    return count;
}


int SelectionSort(int size, char arr[])
{
    int count = 0;

    for(int i = 0; i < size - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            int swap = arr[i];
            arr[i] = arr[min];
            arr[min] = swap;
            count++;
        }
    }
    return count;
}

int InsertionSort(int size, char arr[])
{
    int count = 0;

    for(int i = 1; i < size - 1; i++)
    {
        int value = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            count++;
        }
        arr[j + 1] = value;
    }
    return count;
}

void QuickSortMid(char arr[], int left, int right, int& count)
{
    int l = left, r = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    while (l <= r)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l <= r)
        {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }

    if (left < r)
    {
        count++;
        QuickSortMid(arr, left, r, count);
    }

    if (l < right)
    {
        count++;
        QuickSortMid(arr, l, right, count);
    }
}

void QuickSortMidMinusOne(char arr[], int left, int right, int& count)
{
    int l = left, r = right;
    int temp;
    int pivot = arr[(left + right - 1) / 2];

    while (l <= r)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l <= r)
        {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
    if (left < r)
    {
        count++;
        QuickSortMidMinusOne(arr, left, r, count);
    }

    if (l < right)
    {
        count++;
        QuickSortMidMinusOne(arr, l, right, count);
    }
}

void QuickSortFirst(char arr[], int left, int right, int& count)
{
    int l = left, r = right;
    int temp;
    int pivot = arr[left];

    while (l <= r)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l <= r)
        {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
    if (left < r)
    {
        count++;
        QuickSortFirst(arr, left, r, count);
    }

    if (l < right)
    {
        count++;
        QuickSortFirst(arr, l, right, count);
    }
}

void QuickSortLast(char arr[], int left, int right, int& count)
{
    int l = left, r = right;
    int temp;
    int pivot = arr[right];

    while (l <= r)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l <= r)
        {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }

    if (left < r)
    {
        count++;
        QuickSortLast(arr, left, r, count);
    }

    if (l < right)
    {
        count++;
        QuickSortLast(arr, l, right, count);
    }
}
