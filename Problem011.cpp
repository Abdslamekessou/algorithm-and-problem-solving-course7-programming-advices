
#include <iostream>
#include <string>

// 🎲 Generate two 3x3 matrices with random numbers from 1 to 10  
// ➕ Calculate the sum of all elements in each matrix  
// ⚖️ Compare the sums of the two matrices  
// 🖨️ Print both matrices and display whether their sums are equal or not  
// 📌 Example Output:  
// Matrix 1 :  
// 03    07    10    
// 01    05    09    
// 08    02    06    
//
// Matrix 2 :  
// 04    06    07    
// 02    09    01    
// 08    05    07    
//
// No : matrices are not equal  


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



int SumOfMatrix(int Matrix[3][3], short rows, short columns) {

    int sum = 0;

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            sum += Matrix[i][j];

        }

    }

    return sum;
}



bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns) {

    return (SumOfMatrix(Matrix1 , 3 , 3) == SumOfMatrix(Matrix2, 3, 3));

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

    int Matrix1[3][3] , Matrix2[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix 1 : \n";
    PrintMatrix(Matrix1, 3, 3);


    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix 2 : \n";
    PrintMatrix(Matrix2, 3, 3);

   
    if(AreEqualMatrices(Matrix1 , Matrix2 ,3 , 3) ) {

        cout << "\nYes : both matrices are equal " << endl;

    }else {

       cout << "\nNo : matrices are not equal " << endl;

    }


    cout << "\n";

    system("pause>0");
}


