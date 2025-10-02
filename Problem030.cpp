#include <iostream>
#include <string>

// 📝 Write a C++ program that reads a string and a character from the user  
// 🔎 Then count how many times that character appears in the string  
// 📌 Example:  
// Input  : "Mohammed Abu-Hadhoud" , Letter = 'a'  
// Output : Letter 'a' Count = 2  


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



short CountLetterInString(string S1 , char Letter) {

    short counter = 0;

    for (short i = 0; i < S1.length(); i++) {

        if (S1[i]== Letter) {
            counter++;
        }

    }

    return counter;

}



int main()
{
  
    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\nLetter \'" << Ch1 <<"\' Count = "<< CountLetterInString(S1 , Ch1) << endl;

}
