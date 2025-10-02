
#include <iostream>
#include <string>
#include <cctype>


// 📝 Write a C++ program that reads a string from the user  
// 🔄 Then invert the case of all its letters (uppercase → lowercase, lowercase → uppercase)  
// 📌 Example 1:  
// Input  : "Mohammed Abu-Hadhoud"  
// Output : "mOHAMMED aBU-hADHOUD"  



using namespace std;


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}



char InvertLetterCase(char Ch1) {

    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);

}



string InvertAllStringLettersCase(string S1) {
    
    for (int i = 0; i < S1.length(); i++) {
        S1[i] = InvertLetterCase(S1[i]);
    }

    return S1;

}



int main()
{
    string S1 = ReadString();

    S1 = InvertAllStringLettersCase(S1);

    cout << "\nString after inverting all letters case : \n";

    cout << S1 << endl;


    system("pause>0");
}
