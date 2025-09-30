
#include <iostream>
#include <string>

// 🔢 Read a number from user input  
// 🔍 Search for number in 3x3 matrix  
// 🎯 Check if number exists in any matrix position  
// 🖨️ Display matrix for visual reference  
// ✅ If found → "Yes it is there"  
// ❌ If not found → "No it is not there"  
//  
// 📌 Example Flow:  
// Matrix:  
// 77    05    12  
// 22    20    01  
// 01    00    09  
//  
// "Please enter a number to look for in matrix?"  
// User enters: 20  
// Yes it is there


using namespace std;

int ReadNumber() {

    int Number;

    cout << "\nPlease enter a number to look for in matrix ? ";
    cin >> Number;

    return Number;
}



bool IsNumberInMatrix(int Matrix[3][3], int Number, short rows, short columns) {
  
    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            if (Matrix[i][j] == Number)

                return true;

        }

    }

   
    return false;
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

    int Number = 0;


    cout << "\nMatrix 1 : \n";
    PrintMatrix(Matrix, 3, 3);

    Number = ReadNumber();


    if (IsNumberInMatrix(Matrix , Number , 3 , 3)) {

        cout << "\nYes it is there  " << endl;

    }
    else {

        cout << "\nNo it is not there" << endl;

    }


    cout << "\n";

    system("pause>0");
}
