
#include <iostream>
#include <iomanip>   // for setw

// 🟩 Problem: Create a 3x3 matrix filled with random numbers (1-100) 🎲  
// 🖨️ Print the matrix in a formatted way using <iomanip> (setw) ✨


using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}


void FillMatrixWithRandomNumbers(int arr[3][3] , short rows , short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            arr[i][j] = RandomNumber(1, 100);

        }
    }

}



void PrintMatrix(int arr[3][3] , short rows, short columns) {

    for (int i = 0; i < rows ;i++) {

        for (int j = 0; j < columns ; j++) {

            cout << setw(3) << arr[i][j] << "    ";

        }

        cout << endl;
    }

}


int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr , 3 , 3);

    cout << "The Following is 3*3 Matrix : " << endl;
    PrintMatrix(arr , 3 , 3 );

}


