
#include <iostream>
#include <iomanip> 

// 🔢 Fill a 3x3 matrix with ordered numbers starting from 1  
// 🔄 Create and display its transposed version  
// 📌 Example Output:
// The following is 3*3 ordred matrix : 
//
//   1     2     3    
//   4     5     6    
//   7     8     9    
//
// The following is 3*3 transposed matrix : 
//
//   1     4     7    
//   2     5     8    
//   3     6     9    


using namespace std;


void FillMatrixWithOrdredNumbers(int arr[3][3], short rows, short columns) {

    int counter = 0;

    for (short i = 0; i < rows; i++) {

        for (short j = 0; j < columns; j++) {

            counter++;
            arr[i][j] = counter;

        }
    }
}



void TransposeMatrix(int arr[3][3],int arrTransposed[3][3],short rows, short columns) {

    for (short i = 0; i < rows; i++) {

        for (short j = 0; j < columns; j++) {

            arrTransposed[i][j] = arr[j][i] ;

        }
    }


}



void PrintMatrix(int arr[3][3], short rows, short columns) {

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            cout << setw(3) << arr[i][j] << "    ";

        }

        cout << endl;
    }

}



int main()
{
    int arr[3][3];
    int arrTransposed[3][3];

    FillMatrixWithOrdredNumbers(arr, 3, 3);

    TransposeMatrix(arr, arrTransposed, 3, 3);


    cout << "The following is 3*3 ordred matrix : \n" << endl;
    PrintMatrix(arr, 3, 3);

    cout << "\nThe following is 3*3 transposed matrix : \n" << endl;
    PrintMatrix(arrTransposed, 3, 3);

}


