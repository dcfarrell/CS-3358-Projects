//	 Author/s: Delaney Farrell -
//   Serial	Number/s: 9
//
//	 Due Date: 02/19/2020
//	 Programming Assignment Number 2
//	 Spring	2020 - CS 3358 - 253
//
//	 Instructor: Husain	Gholoom.
//
//   Creates random N x N matrices and determines if they are perfect.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//*****************************************************************
// List of functions:
//
// void populateMatrix(vector<vector<int> > &matrix, int n)
// void isPerfectMatrix(vector<vector<int> > matrix, int perf)
// void printMatrix(vector<vector<int> > matrix)
// int findPerfNum(int n)
//*******************************************************************

//*******************************************************************
// populateMatrix populates a matrix with non-repeating random #s
//
// vector<vector<int> > &matrix: N x N matrix passed by reference to
// be populated
// int n: size of matrix
// Doesn't return anything but modifies matrix
//*******************************************************************
void populateMatrix(vector<vector<int> > &matrix, int n)
{
    int nSquared = n*n;     // hold value of n^2
    int temp;               // holds a temporary random index of randNums
    vector<int> randNums;   // vector to hold a set of #s 0 to n^2

    // Fill randNums with #s 0 to n^2
    for(int i = 0; i <= nSquared; i++)
    {
        randNums.push_back(i);
    }

    // Populate matrix with non-repeating random numbers from randNums
    for(unsigned int r = 0; r < matrix.size(); r++)
    {
        for(unsigned int c = 0; c < matrix.size(); c++)
        {
            temp = rand() % randNums.size();
            matrix[r][c] = randNums.at(temp);
            randNums.erase(randNums.begin() + temp);
        }
    }

};

//*******************************************************************
// isPerfectMatrix determines if matrix is a perfect matrix
//
// vector<vector<int> > matrix: N x N matrix
// int perf: the sum all the rows, cols, and diagonals should be
// to determine perfect matrix
// Doesn't return anything but prints out sums of rows, cols, and
// diagonals of matrix and whether or not matrix is perfect
//*******************************************************************
void isPerfectMatrix(vector<vector<int> > matrix, int perf)
{
    int sum = 0;        // Holds calculated sum
    bool isPerf = true; // Perfect matrix if true

    // Sum up each row
    for(unsigned int r = 0; r < matrix.size(); r++)
    {
        for(unsigned int c = 0; c < matrix.size(); c++)
        {
            sum += matrix[r][c];
        }
        cout << "Sum of numbers in Row\t #\t" << r+1 << "\t=\t" << sum << endl;
        if(isPerf && sum != perf)
        {
            isPerf = false;
        }
        sum = 0;
    }
    cout << endl;

    // Sum up each column
    for(unsigned int c = 0; c < matrix.size(); c++)
    {
        for(unsigned int r = 0; r < matrix.size(); r++)
        {
            sum += matrix[r][c];
        }
        cout << "Sum of numbers in Column #\t" << c+1 << "\t=\t" << sum << endl;
        if(isPerf && sum != perf)
        {
            isPerf = false;
        }
        sum = 0;
    }
    cout << endl;

    // Sum of first diagonal
    for(unsigned int c = 0; c < matrix.size(); c++)
    {
        for(unsigned int r = 0; r < matrix.size(); r++)
        {
            if(r == c)
            {
                sum += matrix[r][c];
            }
        }
    }
    cout << "Sum of numbers in first diagonal:\t=\t" << sum << endl;
    if(isPerf && sum != perf)
    {
        isPerf = false;
    }
    sum = 0;
    cout << endl;

    // Sum of second diagonal
    for(unsigned int c = 0; c < matrix.size(); c++)
    {
        for(unsigned int r = 0; r < matrix.size(); r++)
        {
            if(r + c == matrix.size()-1)
            {
                sum += matrix[r][c];
            }
        }
    }
    cout << "Sum of numbers in second diagonal:\t=\t" << sum << endl;
    if(isPerf && sum != perf)
    {
        isPerf = false;
    }
    sum = 0;
    cout << endl;

    // Check to see if perfect matrix
    if(isPerf)
    {
        cout << "\nThe above is a perfect matrix" << endl;
    }
    else
    {
        cout << "\nThe above is not a perfect matrix" << endl;
    }
};

//*******************************************************************
// printMatrix prints matrix
//
// vector<vector<int> > matrix: N x N matrix
// Doesn't return anything, but prints matrix
//*******************************************************************
void printMatrix(vector<vector<int> > matrix)
{
    for(unsigned int r = 0; r < matrix.size(); r++)
    {
        cout << "\t";
        for(unsigned int c = 0; c < matrix.size(); c++)
        {
            if(matrix[r][c] < 10)
            {
                cout << matrix[r][c] << "\t ";
            }
            else if(matrix[r][c] < 100)
            {
                cout << matrix[r][c] << "\t";
            }
            else
            {
                cout << matrix[r][c] << "\t";
            }
        }
        cout << "\n" << endl;
    }
};

//*******************************************************************
// findPerfNum finds perfect number for N x N matrix
//
// int n: value to be used
// Returns perfect number of N x N matrix
//*******************************************************************
int findPerfNum(int n)
{
    return (n*((n*n)+1))/2;
};

//*******************************************************************
// main
//*******************************************************************
int main()
{
    srand(time(0)); // Seeding rand

    int n = 0;          // Size of the matrix
    int perfNum;    // Calculated perfect number
    char ans;       // User answer: y|Y = yes, n|N = no

    // Header Message
    cout << "Welcome to my perfect matrix program. The function of the program "
         "is to:\n\n\t1. Allow the user to enter the size of the perfect matrix,"
         " such as N. N >=2 and < 13.\n\t2. Create a 2 D vector array of size N "
         "x N.\n\t3. Populate the 2 D vector array with distinct random numbers."
         "\n\t4. Display the perfect number, sum for each row, column, and "
         "diagonals then determine \n\t   whether the numbers in N x N vector "
         "array are perfect matrix numbers.\n" << endl;

    do
    {
        do
        {
            // Get N from user
            cout << "Enter the size of the matrix : ";
            cin >> n;

            // Error checking if user enters a character or integer outside of range
            if(!cin)
            {
                cin.clear();
                cin.ignore();
                cout << "\nError *** Invalid choice - Size must be >= 2 and < 13"
                     "\n" << endl;
            }
            else if(n < 2 || n >= 13)
            {
                cout << "\nError *** Invalid choice - Size must be >= 2 and < 13"
                     "\n" << endl;
            }
        }
        while(n < 2 || n >= 13);
        // Create N x N 2D vector
        vector<int> vec(n);
        vector<vector<int> > matrix(n, vec);

        // Call function to populate N x N matrix
        populateMatrix(matrix, n);

        // Print matrix
        cout << "\n\nThe perfect matrix that is created for size " << n << " :\n"
             << endl;
        printMatrix(matrix);

        // Call function to determine if matrix is a perfect matrix
        perfNum = findPerfNum(n);
        cout << "\nThe perfect number is: " << perfNum << "\n" << endl;
        isPerfectMatrix(matrix, perfNum);

        // Check to see if user wants to continue
        do
        {
            cout << "\nWould you like to find another perfect matrix - Enter y or Y "
                 "for yes or n or N for no: ";
            cin >> ans;

            // Error checking for ans
            if(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N')
            {
                cout << "\nError *** Invalid choice - Must enter y|Y or n|N" << endl;
            }
        }
        while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
        cout << endl;
    }
    while(ans == 'y' || ans == 'Y');

    // Footer Message
    cout << "\nThis Algorithm is Implemented by Delaney Farrell\n\n"
         "February 19 - 2020" << endl;

    return 0;
}
