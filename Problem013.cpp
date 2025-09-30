
#include <iostream>
#include <string>


// 🎲 Generate a single 3x3 matrix with random numbers from 1 to 10  
// 🧪 Check if this randomly generated matrix is an identity matrix  
// 🖨️ Print the matrix for visual inspection  
// 🧠 Identity matrix condition: 1s on the diagonal, 0s elsewhere  
// ✅ If condition is met → "Yes : matrix is identity"  
// ❌ Otherwise → "No : matrix is not identity"  
//
// 📌 Example Output:
// Matrix 1 :
// 01    00    00
// 00    01    00
// 00    00    01
//
// Yes : matrix is identity



using namespace std;


int RandomNumber(int From, int To) {

    return rand() % (To - From + 1) + From;

}


void FillMatrixWithRandomNumbers(int Matrix[3][3], short rows, short columns) {


    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            Matrix[i][j] = RandomNumber(1, 10);

        }
    }

}



bool IsIdentityMatrix(int Matrix[3][3], short rows, short columns) {

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            if (i == j && Matrix[i][j] != 1) {

                return false;

            }
            else if(i != j && Matrix[i][j] != 0) {

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

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "\nMatrix 1 : \n";
    PrintMatrix(Matrix, 3, 3);



    if (IsIdentityMatrix(Matrix, 3 , 3)) {

        cout << "\nYes : matrix is identity " << endl;

    }
    else {

        cout << "\nNo : matrix is not identity " << endl;

    }


    cout << "\n";

    system("pause>0");
}


