
#include <iostream>

using namespace std;

// 📝 Program to check if a character is a vowel (a, e, i, o, u - case insensitive).  
// 💡 Examples: 
// Input = 'A' → Yes, vowel 
// Input = 'e' → Yes, vowel.  
// Input = 'b' → No, is Not vowel.


char ReadChar() {

    char Ch1;

    cout << "Please Enter Character?" << endl;
    cin >> Ch1;

    return Ch1;
}



bool IsVowel(char Ch1) {

    Ch1 = tolower(Ch1);

    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
  
}



int main()
{
    char Ch1 = ReadChar();

    if (IsVowel(Ch1)) {
        
        cout << "\nYes Letter \'" << Ch1 << "\' is vowel" << endl;

    }
    else {

        cout << "\nNo Letter \'" << Ch1 << "\' is not vowel" << endl;

    }


}


