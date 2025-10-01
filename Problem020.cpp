
#include <iostream>
#include <string>
#include <iomanip>

// 🔄 Check if each row in 3x3 matrix is palindrome  
// 📖 Palindrome condition: row reads same forwards and backwards   
// 🖨️ Display matrix for visual verification  
// ✅ If all rows palindrome → "Yes : matrix is palindrome"  
// ❌ If any row fails → "No : matrix is not palindrome"  
//  
// 📌 Example Matrix:  
// 01    02    01  
// 05    05    05  
// 07    03    07  
//  
// Row1: 1-2-1 ✓ palindrome  
// Row2: 5-5-5 ✓ palindrome  
// Row3: 7-3-7 ✓ palindrome  
// Yes : matrix is palindrome


using namespace std;


bool IsPalindromeMatrix(int Matrix[3][3], short rows, short columns) {

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns / 2; j++) {

            if (Matrix[i][j] != Matrix[i][columns - 1 - j])
                return false;

        }

        cout << endl;
    }

    return true;
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
        {1 , 2 , 1},
        {5 , 5 , 5},
        {7 , 3 , 7}
    };


    cout << "\nMatrix : \n";
    PrintMatrix(Matrix, 3, 3);

    if (IsPalindromeMatrix(Matrix, 3, 3)) {

        cout << "\nYes : matrix is palindrome " << endl;

    }
    else {

        cout << "\nNo : matrix is not palindrome " << endl;

    }

    system("pause>0");
}
