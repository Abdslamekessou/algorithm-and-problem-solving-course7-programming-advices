
#include <iostream>
#include <string>

// ✂️ Program to remove spaces from the beginning and/or end of a string.  
// 🔹 TrimLeft()  → Removes spaces from the left side.  
// 🔹 TrimRight() → Removes spaces from the right side.  
// 🔹 Trim()      → Removes spaces from both sides.  
// 💡 Example: Input = "      Abdessalem       "  
// 👉 Output:  
// String      = "      Abdessalem       "  
// Trim Left   = "Abdessalem       "  
// Trim Right  = "      Abdessalem"  
// Trim        = "Abdessalem"


using namespace std;



string TrimLeft(string S1) {

    for (short i = 0; i < S1.length(); i++) {

        if (S1[i] != ' ' ) {
            return S1.substr(i, S1.length() - i);
        }

    }

}



string TrimRight(string S1) {

    for (short i = S1.length() - 1; i >= 0 ; i--) {

        if (S1[i] != ' ') {

            return S1.substr(0, i+1);

        }

    }

}



string Trim(string S1) {

    return TrimLeft(TrimRight(S1));

}



int main()
{
    string S1 = "      Abdessalem       ";
    cout << "\nString      = " << S1 ;
    cout << "\n\nTrim Left   = " << TrimLeft(S1);
    cout << "\nTrim Right  = " << TrimRight(S1);
    cout << "\nTrim        = " << Trim(S1);


}


