
#include <iostream>
#include <iomanip> 


// 🟩 Problem: Create a 3x3 matrix filled with random numbers (1-100) 🎲  
// 🖨️ Print the matrix neatly using <iomanip> (setw) ✨  
// ➕ Calculate the sum of each row and store in an array 📊  
// 
// Example:
// 
// Matrix:
// 12   45   78
// 23   34   56
// 10   20   30
// 
// 
// Row sums:
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


void SumMatrixRowsInArr(int arr[3][3], int arrSum[3], short rows , short columns) {

    for (int i = 0; i < rows; i++) {
        arrSum[i] = RowSum(arr, i, columns);
    }

}


void PrintEachRowSum(int arrSum[3], short rows) {

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << " Sum = " << arrSum[i] << endl;
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
    int arrSum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The Following is 3*3 Matrix : " << endl;
    PrintMatrix(arr, 3, 3);

    SumMatrixRowsInArr(arr, arrSum, 3, 3);

    cout << "\nThe following are the sum of each row in the matrix :  \n";
    PrintEachRowSum(arrSum, 3);

}
