
#include <iostream>
#include <string>


// 🧮 Count zeros in a 3x3 matrix  
// 📊 Check if matrix is sparse (majority zeros)  
// 🔍 Sparse condition: zero count ≥ ceil(total_elements / 2)  
// 🖨️ Display matrix for visual verification  
// ✅ If sparse → "Yes : matrix is sparse"  
// ❌ If not sparse → "No : matrix is not sparse"  
//  
// 📌 Example Matrix:  
// 00    00    12  
// 00    00    01  
// 00    00    09  
//  
// Yes : matrix is sparse


using namespace std;


int CountNumberInMatrix(int Matrix[3][3], int Number, short rows, short columns) {

    short NumberCount = 0;

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            if (Matrix[i][j] == Number)
                NumberCount++;

        }

    }

    return NumberCount;

}



bool IsSparceMatrix(int Matrix[3][3], short rows, short columns) {
    
    short MatrixSize = rows * columns;

    return (CountNumberInMatrix(Matrix, 0, 3, 3) >= ceil((float) MatrixSize / 2));

}



void PrintMatrix(int Matrix[3][3], short rows, short columns) {

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            printf("%0*d    ", 2, Matrix[i][j]);

        }

        cout << endl;
    }

}



int main()
{

    srand(unsigned(time(NULL)));

    int Matrix[3][3] = {
       {0, 0, 12},
       {0, 0, 1},
       {0, 0, 9}
    };


    cout << "\nMatrix 1 : \n";
    PrintMatrix(Matrix, 3, 3);


    if (IsSparceMatrix(Matrix, 3, 3)) {

        cout << "\nYes : matrix is sparce " << endl;

    }
    else {

        cout << "\nNo : matrix is not sparce " << endl;

    }


    cout << "\n";

    system("pause>0");
}
