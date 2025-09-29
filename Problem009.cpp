
#include <iostream>
#include <string>

// 🎲 Generate a 3x3 matrix with random numbers from 1 to 10  
// 🖨️ Print the full matrix  
// 📍 Display the middle row and the middle column of the matrix  
// 📌 Example Output:
// Matrix : 
// 03    07    10    
// 01    05    09    
// 08    02    06    
//
// Middle Row of Matrix is : 
// 01    05    09    
//
// Middle Column of Matrix is : 
// 07    05    02    


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



void PrintMiddleOfRowMatrix(int Matrix[3][3], short rows ,  short columns) {

    short middleRow = rows / 2;

    for (short i = 0; i < columns; i++) {
        printf("%0*d    ", 2, Matrix[middleRow][i]);
    }

}



void PrintMiddleColumnOfMatrix(int Matrix[3][3], short rows, short columns) {

    short middleCol = rows / 2;

    for (short i = 0; i < columns; i++) {

        printf("%0*d    ", 2, Matrix[i][middleCol]);

    }

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

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "\nMatrix : \n";
    PrintMatrix(Matrix, 3, 3);

    cout << "\n\nMiddle Row of Matrix  is : " << endl;
    PrintMiddleOfRowMatrix(Matrix, 3, 3);

    
    cout << "\n\nMiddle Column of Matrix  is : " << endl;
    PrintMiddleColumnOfMatrix(Matrix, 3, 3);

    cout << "\n";
}


