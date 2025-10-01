
#include <iostream>
#include <string>
#include <iomanip>

// 🔍 Find common numbers between two 3x3 matrices  
// 🔄 Compare each element from Matrix1 with all elements in Matrix2  
// 📊 Print numbers that exist in both matrices  
// 🖨️ Display both matrices for visual comparison  
// 🎯 Output only intersecting numbers in sequence  
//  
// 📌 Example Output:  
// Matrix 1:  
// 77    05    12  
// 22    20    01  
// 01    00    09  
//  
// Matrix 2:  
// 05    80    90  
// 22    77    01  
// 10    88    01  
//  
// Intersected Numbers are:  
// 77    5    22    1    1


using namespace std;



bool IsNumberInMatrix(int Matrix[3][3], int Number, short rows, short columns) {


    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            if (Matrix[i][j] == Number)

                return true;

        }

    }

    return false;
  
}



void PrintIntersectedNumberInMatrix(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns) {

    int Number;

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            Number = Matrix1[i][j];

            if (IsNumberInMatrix(Matrix2, Number , 3, 3)) {
                cout << setw(3) << Number << "     ";
            }
            

        }

    }

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

    int Matrix1[3][3] = {
        {77 , 5 , 12},
        {22 , 20 , 1},
        {1 , 0 ,  9}
    };

    int Matrix2[3][3] = {
    {5 , 80 , 90},
    {22 , 77 , 1},
    {10 , 88 ,  1}
    };


    cout << "\nMatrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix 2 : \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers are : \n\n";
    PrintIntersectedNumberInMatrix(Matrix1, Matrix2, 3, 3);

    system("pause>0");
}
