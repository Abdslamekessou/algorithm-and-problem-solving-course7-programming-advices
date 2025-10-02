#include <iostream>
#include <string>

// 📝 Write a C++ program that reads a string and a character from the user  
// 🔎 Then count how many times that character appears in the string  
// 🎭 The program should handle both case-sensitive and case-insensitive counting  
// 📌 Example:  
// Input  : "Mohammed Abu-Hadhoud" , Letter = 'a'  
// Output :  
// Letter 'a' Count = 2  
// Letter 'a' Or 'A' Count = 3  



using namespace std;


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}



char ReadChar() {

    char Ch1;

    cout << "Please Enter Character?" << endl;
    cin >> Ch1;

    return Ch1;
}



char InvertLetterCase(char char1) {
    
    return (isupper(char1) ? tolower(char1) : toupper(char1));

}



short CountLetter(string S1 , char Letter , bool MatchCase = true) {

    short counter = 0;

    for (short i = 0; i < S1.length(); i++) {

        if (MatchCase) {

            if (S1[i] == Letter) {
                counter++;
            }

        }
        else {

            if (tolower(S1[i]) == tolower(Letter)) {
                counter++;
            }

        }


    }

    return counter;

}




int main()
{
    string S1 = ReadString();
    char Ch1 = ReadChar();


    cout << "\nLetter \'" << Ch1 <<"\' Count = "<< CountLetter(S1 , Ch1) << endl;

    cout << "\nLetter \'" << Ch1 << "\' Or \'"
        << char(InvertLetterCase(Ch1)) << "\' Count = " 
        << CountLetter(S1, Ch1 , false) << endl;

}
