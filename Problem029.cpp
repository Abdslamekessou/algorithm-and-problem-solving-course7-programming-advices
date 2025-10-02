#include <iostream>
#include <string>

// 📝 Write a C++ program that reads a string from the user  
// 🔢 Then count: total letters(length), capital letters, and small letters  
// 📌 Example:  
// Input  : "Mohammed Abu-Hadhoud"  
// Output :  
// String Length        = 21  
// Capital Letter Count = 2  
// Small Letter Count   = 19  


using namespace std;


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}


enum enWhatToCount {CapitalLetters = 1 , SmallLetters = 2 , All = 3 };



int CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) {
    
    if (WhatToCount == enWhatToCount::All) {
        return S1.length();
    }

    short counter = 0;

    for (short i = 0; i < S1.length(); i++) {

        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i])) {
            counter++;
        }

        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i])) {
            counter++;
        }

    }

    return counter;

}



int CountCapitalLetters(string S1) {

    int counter = 0;

    for (short i = 0; i < S1.length(); i++) {

        if (isupper(S1[i])) {
            counter++;
        }

    }

    return counter;

}



int CountSmallLetters(string S1) {

    int counter = 0;

    for (short i = 0; i < S1.length(); i++) {

        if (islower(S1[i])) {
            counter++;
        }

    }

    return counter;

}



int main()
{
    string S1 = ReadString();

    cout << "\n\nString Length        = " << CountLetters(S1) << endl;
    cout << "Capital Letter Count = " << CountLetters(S1 , enWhatToCount::CapitalLetters) << endl;
    cout << "Small Letter Count   = " << CountLetters(S1 , enWhatToCount::SmallLetters) << endl;

    cout << "\n*****************************************************************************************\n";

    cout <<"\n\nString Length        = " << S1.length() << endl;
    cout <<"Capital Letter Count = " << CountCapitalLetters(S1) << endl;
    cout <<"Small Letter Count   = " << CountSmallLetters(S1) << endl;

    
}


