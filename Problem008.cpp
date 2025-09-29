#include <iostream>
#include <iomanip> 
#include <string>

// 🎲 Generate two 3x3 matrices with random numbers from 1 to 10  
// ✖️ Multiply them element by element and store results in a new matrix  
// 🖨️ Print the two matrices and their multiplication result  
// 📌 Example Output:
// Matrix 1 : 
// 03    07    10    
// 01    05    09    
// 08    02    06    
//
// Matrix 2 : 
// 04    06    03    
// 02    09    01    
// 07    05    08    
//
// Results : 
// 12    42    30    
// 02    45    09    
// 56    10    48    



using namespace std;


int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}


void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            arr[i][j] = RandomNumber(1, 10);

        }
    }

}



void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], 
    int MatrixResults[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];

        }

        cout << endl;
    }

}



void PrintMatrix(int arr[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            printf("%0*d    ", 2, arr[i][j]);

        }

        cout << endl;
    }

}



int main()
{
    srand(unsigned(time(NULL)));

    int Matrix1[3][3],  Matrix2[3][3],  MatrixResults[3][3];

    FillMatrixWithRandomNumbers(Matrix1 , 3 ,3);

    cout << "\nMatrix 1 : " << endl;
    PrintMatrix(Matrix1, 3, 3);


    FillMatrixWithRandomNumbers(Matrix2 , 3 ,3);

    cout << "\nMatrix 2 : " << endl;
    PrintMatrix(Matrix2, 3, 3);

    MultiplyMatrix(Matrix1, Matrix2, MatrixResults, 3, 3);

    cout << "\nResults : " << endl;
    PrintMatrix(MatrixResults, 3, 3);

    system("pause>0");

}

