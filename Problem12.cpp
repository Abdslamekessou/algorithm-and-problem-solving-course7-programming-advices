
#include <iostream>
#include <string>

// 🎲 Generate two 3x3 matrices with random numbers from 1 to 10  
// 👯 Compare both matrices element by element to check if they are identical  
// 🖨️ Print both matrices for visualization  
// ✅ If all elements are the same → "Yes : both matrices are typical"  
// ❌ Otherwise → "No : matrices are not typical"  
//
// 📌 Example Output:
// Matrix 1 :
// 03    07    09
// 05    01    02
// 08    06    04
//
// Matrix 2 :
// 03    07    09
// 05    01    02
// 08    06    04
//
// Yes : both matrices are typical


using namespace std;


int RandomNumber(int From, int To) {

    return rand() % (To - From + 1) + From;

}


void FillMatrixWithRandomNumbers(int Matrix[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            Matrix[i][j] = RandomNumber(1, 10);

        }
    }

}



bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

           if (Matrix1[i][j] != Matrix2[i][j]) {
               return false;
           }

        }

    }

    return true;

}



void PrintMatrix(int Matrix[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            printf("%0*d    ", 2, Matrix[i][j]);

        }

        cout << endl;
    }

}



int main()
{

    srand(unsigned(time(NULL)));

    int Matrix1[3][3], Matrix2[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);


    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix 2 : \n";
    PrintMatrix(Matrix2, 3, 3);


    if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3)) {

        cout << "\nYes : both matrices are typical " << endl;

    }
    else {

        cout << "\nNo : matrices are not typical " << endl;

    }


    cout << "\n";

    system("pause>0");
}


