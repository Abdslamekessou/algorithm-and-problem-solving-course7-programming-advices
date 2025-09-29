
#include <iostream>
#include <iomanip> 


// 🔢 Fill a 3x3 matrix with ordered numbers starting from 1  
// 🖨️ Print the matrix in a formatted way  
// 📌 Example Output:
// The following is 3*3 ordred matrix : 
//   1     2     3    
//   4     5     6    
//   7     8     9    


using namespace std;


void FillMatrixWithOrdredNumbers(int arr[3][3] , short rows , short columns) {

    int counter = 0;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < columns; j++) {

            counter++;
            arr[i][j] = counter ;

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



int main()
{
    int arr[3][3];

    FillMatrixWithOrdredNumbers(arr, 3, 3);

    cout << "The following is 3*3 ordred matrix : " << endl;
    PrintMatrix(arr, 3, 3);
}


