// Serial Number : 9
//
// Author : Delaney Farrell
// Due Date :   04/06/2020
// Programming Assignment Number 4
//
// Spring 2020 - CS 3358 - 253
//
// Instructor: Husain Gholoom.
//
// Program that runs multiple recursive functions;\.

#include <iostream>
#include <ctime>

using namespace std;

//*******************************************************************
// void GenerateArray(int arr[], int size)
//
// Parameter(s): int arr[], int size
// Return: void
// Generates an array of size size of random numbers between 10 and
// 375
//*******************************************************************
void GenerateArray(int arr[], int size);

//*******************************************************************
// void ReverseArray(const int arr[], int size)
//
// Parameter(s): const int arr[], int size
// Return: void
// Prints out the array inputted reversed
//*******************************************************************
void ReverseArray(const int arr[], int size);

//*******************************************************************
// void SquaredArray(int start, int end)
//
// Parameter(s): int start, int end
// Return: void
// Squares every single value from 1 to the beginning of the array
// and displays the values
//*******************************************************************
void SquaredArray(int start, int end);

//*******************************************************************
// int SumOfDigits(int n)
//
// Parameter(s): int n
// Return: int
// Returns the sum of digits of integer n
//*******************************************************************
int SumOfDigits(int n);

//*******************************************************************
// void IsPrime(int num, int i)
//
// Parameter(s): int num, int i
// Return: void
// Outputs whether or not num is a prime number
//*******************************************************************
void IsPrime(int num, int i);

int main()
{
    srand(time(0)); // Seeding rand

    int* arr; // dynamic array for randomly generated values
    int arrSize; // user input for size of the array

    // Intro Message
    cout << "***    Welcome to My Recursion APP     ***\n\n"
         "Enter the array size. (Must  be >= 5) ->\t";

    cin >> arrSize;

    // Error checking
    if (arrSize < 5)
    {
        cout << "\n\nInvalid array size. Size must >= 5." << endl;
    }
    else
    {

        arr = new int[arrSize];

        // Generate Array
        GenerateArray(arr, arrSize);

        // Reverse Array
        cout << "Reversed array is \t:  ";
        ReverseArray(arr, arrSize - 1);
        cout << endl;

        // Squares Values of Array
        cout << "Table of square values 1 - " << arr[0] << "\n" << endl;
        cout << "N\tN Squared" << endl;
        SquaredArray(1, arr[0]);
        cout << endl;

        // Sums digits of first value of the array
        cout << "Sum of its digits is  " << SumOfDigits(arr[0]) << endl;

        // Check to see if each member of arr is prime or not
        cout << "\nIs It Prime : \n" << endl;
        for(int i = 0; i < arrSize; i++)
        {
            IsPrime(arr[i], arr[i] - 1);
        }
        cout << endl;

        // deletes dynamically allocated array
        delete [] arr;
        arr = NULL;
    }

    // End Message
    cout << "\nDelaney Farrell - Tweak Programming Director\n"
         "March 2020" << endl;

    return 0;
}

void GenerateArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 375) + 10;
    }

    cout << "\n\nThe generated array is\t:  ";
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n" << endl;
}

void ReverseArray(const int arr[], int size)
{
    if(size <= 0)
    {
        cout << arr[0] << endl;
    }
    else
    {
        cout << arr[size] << " ";
        ReverseArray(arr, size - 1);
    }
}

void SquaredArray(int start, int end)
{
    if(start >= end)
    {
        cout << end << "\t" << end*end << endl;
    }
    else
    {
        cout << start << "\t" << start*start << endl;
        SquaredArray(start + 1, end);
    }
}

int SumOfDigits(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    else
    {
        return n % 10 + SumOfDigits(n / 10);
    }
}

void IsPrime(int num, int i)
{
    if(i > 1)
    {
        if(num % i == 0)
        {
            cout << "The number " << num << " is Not Prime." << endl;
        }
        else
        {
            IsPrime(num, i-1);
        }
    }
    else
    {
        cout << "The number " << num << " is Prime." << endl;
    }
}
