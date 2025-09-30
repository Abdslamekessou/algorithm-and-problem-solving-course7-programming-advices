
#include <iostream>
#include <string>

// 🎲 Define a 3x3 matrix manually with diagonal values and zeros elsewhere  
// 🧪 Check if the matrix qualifies as a scalar matrix  
// 🧠 Scalar matrix condition: all diagonal elements must be equal, others must be zero  
// 🖨️ Print the matrix for visual confirmation  
// ✅ If condition is met → "Yes : matrix is scalar"  
// ❌ Otherwise → "No : matrix is not scalar"  
//
// 📌 Example Output:
// Matrix 1 :
// 09    00    00
// 00    09    00
// 00    00    09
//
// Yes : matrix is scalar



using namespace std;


bool IsScalarMatrix(int Matrix[3][3], short rows, short columns) {

    int FirstDiagElement = Matrix[0][0];

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {


            //check for diagonal elements
            if (i == j  && Matrix[i][j] != FirstDiagElement ) {

                return false;

            }
            //check for rest elements
            else if (i != j && Matrix[i][j] != 0) {

                return false;

            }

        }


    }

    return true;


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
       {9, 0, 0},
       {0, 9, 0},
       {0, 0, 9}
    };


    cout << "\nMatrix 1 : \n";
    PrintMatrix(Matrix, 3, 3);


    if (IsScalarMatrix(Matrix, 3, 3)) {

        cout << "\nYes : matrix is scalar " << endl;

    }
    else {

        cout << "\nNo : matrix is not scalar " << endl;

    }


    cout << "\n";

    system("pause>0");
}


