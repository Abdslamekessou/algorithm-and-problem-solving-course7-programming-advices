#include <iostream>

using namespace std;

// 🔢 Generate Fibonacci series: each number = sum of two preceding ones  
// 🖨️ Print sequence: 1 1 2 3 5 8 13 21 34 55 for FibonacciSeries(10)


void FibonacciSeries(short number) {

    int prev1 = 1 , prev2 = 0 , FebNumber = 0;

    cout << "1  ";
 

    for (short i = 2 ; i <= number ; i++) {

        FebNumber = prev1 + prev2;

        cout << FebNumber << "  ";

        prev2 = prev1;
        prev1 = FebNumber;

    }

}


int main()
{
    FibonacciSeries(10);
}


