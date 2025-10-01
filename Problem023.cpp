
#include <iostream>
#include <string>

using namespace std;

// 📝 Write a C++ program that reads a string from the user  
// ✂️ Then print the first letter of each word on a new line  
// 📌 Example:  
// Input  : "Hello World From C++"  
// Output :  
// H  
// W  
// F  
// C  


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin , S1);

    return S1;
}



void PrintFirstLetterOfEachWord(string S1) {

    bool isFirstLetter = true;

    cout << "\nFirst Letters Of this String : \n";
    
    for (int i = 0 ; i < S1.length(); i++) {

        if (S1[i] != ' ' && isFirstLetter) {

            cout << S1[i] << endl;

        }

        isFirstLetter = (S1[i] == ' ' ? true : false);
    }

}



int main()
{
    string S1 = ReadString();

    PrintFirstLetterOfEachWord(S1);
}

