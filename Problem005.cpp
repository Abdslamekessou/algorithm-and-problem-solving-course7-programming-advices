#include <iostream>
#include <iomanip> 


// 🎲 Generate a 3x3 matrix with random numbers  
// 📥 Store the sum of each column in a separate array  
// ➕ Print each column's sum from the array  
// 📌 Example Output:
// The Following is 3*3 Matrix : 
//  45     88     12    
//  67     34     90    
//  23     56     71    
//
// The following are the sum of each col in the matrix :  
//
// Col 1 Sum = 135  
// Col 2 Sum = 178  
// Col 3 Sum = 173  


using namespace std;



int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}



void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            arr[i][j] = RandomNumber(1, 100);

        }
    }

}



void PrintMatrix(int arr[3][3], short rows, short columns) {

    for (int i = 0; i < rows;i++) {

        for (int j = 0; j < columns; j++) {

            cout << setw(3) << arr[i][j] << "    ";

        }

        cout << endl;
    }

}




int ColumnSum(int arr[3][3], short rows, short columnNumber) {

    int sum = 0;

    for (int i = 0; i < rows; i++) {
        sum += arr[i][columnNumber];
    }

    return sum;

}



void SumMatrixColumnsInArr(int arr[3][3], int arrSum[3], int rows, short columns) {

    for (int i = 0; i < columns; i++) {
        arrSum[i] = ColumnSum(arr, rows, i);
    }
}




void PrintEachColumnSum(int arr[3], short length) {

    for (int i = 0; i < length; i++) {
        cout << "Col " << i + 1 << " Sum = " << arr[i] << endl;
    }

}




int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];
    int arrSum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The Following is 3*3 Matrix : " << endl;
    PrintMatrix(arr, 3, 3);


    SumMatrixColumnsInArr(arr, arrSum, 3, 3);

    cout << "\nThe following are the sum of each col in the matrix :  \n\n";
    PrintEachColumnSum(arrSum, 3);

}
