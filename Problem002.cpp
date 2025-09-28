
#include <iostream>
#include <iomanip>   // for setw

// 🟩 Problem: Create a 3x3 matrix filled with random numbers (1-100) 🎲  
// ➕ Then calculate and print the sum of each row 🖨️✨  
// 
// Example:
// 
// Matrix:
// 12   45   78
// 23   34   56
// 10   20   30
// 
// Row sums:
// 
// Row 1 Sum = 135
// Row 2 Sum = 113
// Row 3 Sum = 60



using namespace std;


int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}


void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            arr[i][j] = RandomNumber(1, 100);

        }
    }

}



int RowSum(int arr[3][3], short rowNumber, short columns) {

     int sum = 0;

     for (int j = 0; j < columns; j++) {
           sum += arr[rowNumber][j];
     }
     
     return sum;
}



void PrintEachRowSum(int arr[3][3], short rows, short columns) {

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << " Sum = " << RowSum(arr, i, columns) << endl;
    }

}



void PrintMatrix(int arr[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            cout << setw(3) << arr[i][j] << "    ";

        }

        cout << endl;
    }

}


int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The Following is 3*3 Matrix : " << endl;
    PrintMatrix(arr, 3, 3);

    cout << "\nThe following are the sum of each row in the matrix :  \n";
    PrintEachRowSum(arr, 3, 3);

}
