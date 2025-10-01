#include <iostream>

using namespace std;

// 🔄 Generate Fibonacci series using recursion  
// 🧮 Each recursive call calculates next number = previous two numbers sum  
// 📉 Decrement counter until base case (number > 0)  
// 🖨️ Output: 1    1    2    3    5    8    13    21    34    55


void PrintFibonacciUsingRecursion(short number , short prev1 , short prev2) {

    int FabNumber = 0;

    if (number > 0) {

        FabNumber = prev1 + prev2;

        prev2 = prev1;
        prev1 = FabNumber;

        cout << FabNumber << "    ";

        PrintFibonacciUsingRecursion(number - 1, prev1, prev2);

    }

}


int main()
{
    PrintFibonacciUsingRecursion(10, 0, 1);
    
}
