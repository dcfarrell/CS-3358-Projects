//	 Author/s: Delaney Farrell -
//   Serial	Number/s:
//
//	 Due Date: 02/19/2020
//	 Programming Assignment Number 2
//	 Spring	2020 - CS 3358 - 253
//
//	 Instructor: Husain	Gholoom.
//
// 	<Brief description of the purpose of the program>

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void populateMatrix(vector<vector<int> > &matrix, int n) {
    //int nSquared = n*n;
    int counter = 0;
    int temp1, temp2;
    vector<int> v(n+1);
    vector<vector<int> > randNums(n+1, v);

    for(unsigned int r = 0; r <= v.size(); r++) {
        for(unsigned int c = 0; c <= v.size(); c++) {
            randNums[r][c] = counter;
            counter++;
        }
    }

    for(unsigned int r = 0; r < matrix.size(); r++) {
        for(unsigned int c = 0; c < matrix.size(); c++) {
            temp1 = rand() % n;
            temp2 = rand() % n;
            matrix[r][c] = randNums[temp1][temp2];
            cout << temp1 << " " << temp2 << endl;
            randNums[temp1].erase(randNums[temp1].begin()+temp2);
        }
    }

};

void isPerfectMatrix(vector<vector<int> > matrix, int num) {

};

void printMatrix(vector<vector<int> > matrix) {
    for(unsigned int r = 0; r < matrix.size(); r++) {
        for(unsigned int c = 0; c < matrix.size(); c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
};

int findPerfNum(int n) {
    return (n*(n*n+1))/2;
}

int main()
{
    srand(time(0));

    int n;
    int perfNum;
    //vector<int> vec(n);
    //vector<vector<int> > matrix(n, vec);
    char ans;

    // Header Message
    cout << "Welcome to my perfect matrix program. The function of the program "
         "is to:\n\n\t1. Allow the user to enter the size of the perfect matrix,"
         " such as N. N >=2 and < 13.\n\t2. Create a 2 D vector array of size N "
         "x N.\n\t3. Populate the 2 D vector array with distinct random numbers."
         "\n\t4. Display the perfect number, sum for each row, column, and "
         "diagonals then determine \n\t   whether the numbers in N x N vector "
         "array are perfect matrix numbers.\n" << endl;

    do {
        // Get N from user
        cout << "Enter the size of the matrix : ";
        cin >> n;

        // Create N x N vector
        vector<int> vec(n);
        vector<vector<int> > matrix(n, vec);

        // Call function to populate N x N matrix
        populateMatrix(matrix, n);

        // Print matrix
        cout << "\n\nThe perfect matrix that is created for size " << n << " :\n"
             << endl;
        printMatrix(matrix);

        // Call function to determine if perfect matrix
        perfNum = findPerfNum(n);
        isPerfectMatrix(matrix, perfNum);

        // Check to see if user wants to continue
        cout << "Would you like to find another perfect matrix - Enter y or Y for"
             " yes or n or N for no: ";
        cin >> ans;
        // Error checking for ans
    } while(ans == 'y' || ans == 'Y');

    // Footer Message
    cout << "This Algorithm is Implemented by Delaney Farrell\n\n"
         "February 19 - 2020" << endl;

    return 0;
}
