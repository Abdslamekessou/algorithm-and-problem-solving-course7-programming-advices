
#include <iostream>
#include <string>

// 📝 Program to print all vowels (a, e, i, o, u) inside a given string.  
// 💡 Example: Input = "Programming Advices Mohammed Abu-Hadhoud"  
// 👉 Output = o   a   i   A   i   e   o   a   e   A   u   a   o   u  


using namespace std;


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}


bool IsVowel(char Ch1) {

    Ch1 = tolower(Ch1);

    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

}


void PrintVowels(string S1) {


    for (short i = 0; i < S1.length(); i++) {

        if (IsVowel(S1[i])) {

            cout << S1[i] << "   ";

        }

    }

}



int main()
{
    string S1 = ReadString();

    cout << "Vowels of string are  : ";

    PrintVowels(S1);

}


