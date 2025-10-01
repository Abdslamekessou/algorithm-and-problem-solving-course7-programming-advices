
#include <iostream>
#include <string>
#include <iomanip>


// ✅ Find minimum and maximum values in a 3x3 matrix  
// 📊 Scan all matrix elements to determine min and max values  
// 🖨️ Display matrix for visual reference  
// 📈 Output both minimum and maximum numbers found   
//  
// 📌 Example Output:  
// Matrix:  
// 77    05    12  
// 22    20    01  
// 01    00    09  
//  
// Minimum number is : 0  
// Maximum number is : 77  


using namespace std;



int MaxNumberInMatrix(int Matrix[3][3], short rows, short columns) {

    int MaxNumber = Matrix[0][0];

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            if (Matrix[i][j] > MaxNumber)
                MaxNumber = Matrix[i][j];
                
        }

    }

    return MaxNumber;

}



int MinNumberInMatrix(int Matrix[3][3], short rows, short columns) {

    int MinNumber = Matrix[0][0];

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            if (Matrix[i][j] < MinNumber)
                MinNumber = Matrix[i][j];

        }

    }

    return MinNumber;

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
        {77 , 5 , 12},
        {22 , 20 , 1},
        {1 , 0 ,  9}
    };



    cout << "\nMatrix : \n";
    PrintMatrix(Matrix, 3, 3);



    cout << "\nMinimum number is : " << MinNumberInMatrix(Matrix, 3, 3) << endl;
    cout << "\nMaximum number is : " << MaxNumberInMatrix(Matrix, 3, 3) << endl;

    system("pause>0");
}
