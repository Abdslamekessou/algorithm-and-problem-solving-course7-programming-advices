
#include <iostream>
#include <string>

// 🧮 Define a 3x3 matrix with preset values  
// 🔢 Ask the user to input a number to search for  
// 🔍 Count how many times that number appears in the matrix  
// 🖨️ Print the matrix for visual reference  
// 📊 Display the total count of the number in the matrix  
// ✅ Useful for frequency analysis or pattern detection  
//
// 📌 Example Output:
// Matrix 1 :
// 09    01    12
// 00    09    01
// 00    09    09
//
// Enter the number to count in matrix?
// 9
//
// Number 9 count in matrix is : 4



using namespace std;


int ReadNumber() {

    int number;

    cout << "\nEnter the number to count in matrix?\n";
    cin >> number;

    return number;
}



int CountNumberInMatrix(int Matrix[3][3], int Number, short rows, short columns) {

    short NumberCount = 0;

    for (short i = 0; i < rows;i++) {

        for (short j = 0; j < columns; j++) {

            if (Matrix[i][j] == Number)
                NumberCount++;

        }
        
    }

    return NumberCount;

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
       {9, 1, 12},
       {0, 9, 1},
       {0, 9, 9}
    };

    int Number = 0;


    cout << "\nMatrix 1 : \n";
    PrintMatrix(Matrix, 3, 3);

    Number = ReadNumber();

    cout << "\nNumber " << Number <<" count in matrix is : " << CountNumberInMatrix(Matrix , Number , 3, 3) << endl;


    system("pause>0");
}


