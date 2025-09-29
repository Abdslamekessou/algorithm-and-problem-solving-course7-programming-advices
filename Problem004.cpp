
#include <iostream>
#include <iomanip> 


// 🎲 Generate a 3x3 matrix with random numbers  
// ➕ Calculate and display the sum of each column  
// 📌 Example Output:
// The Following is 3*3 Matrix : 
//  67     24     89    
//  15     42     73    
//  98     11     56    
//
// The following are the sum of each col in the matrix :  
//
// Col 1 Sum = 180  
// Col 2 Sum = 77  
// Col 3 Sum = 218  


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



int ColumnSum(int arr[3][3], short rows, short columnNumber) {

    int sum = 0;

    for (int i = 0; i < rows; i++) {
        sum += arr[i][columnNumber];
    }

    return sum;

}



void PrintEachColumnSum(int arr[3][3], short rows ,short columns) {
    
    for (int i = 0; i < columns; i++) {
        cout << "Col " << i + 1 << " Sum = " << ColumnSum(arr , rows , i) << endl;
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



int main()
{
    srand(unsigned(time(NULL)));

    int arr[3][3];
    

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The Following is 3*3 Matrix : " << endl;
    PrintMatrix(arr, 3, 3);

   

    cout << "\nThe following are the sum of each col in the matrix :  \n\n";
    PrintEachColumnSum(arr, 3, 3);

}
