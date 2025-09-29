
#include <iostream>
#include <string>

// 🎲 Generate a 3x3 matrix with random numbers from 1 to 10  
// ➕ Calculate the sum of all elements in the matrix  
// 🖨️ Print the matrix and its total sum  
// 📌 Example Output:
// Matrix : 
// 03    07    10    
// 01    05    09    
// 08    02    06    
//
// Sum of Matrix is : 51  


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


    cout << "\n\nSum of Matrix is : " << SumOfMatrix(Matrix , 3 ,3) << endl;
    

    cout << "\n";
}


