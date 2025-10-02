
#include <iostream>
#include <string>

using namespace std;

// 📝 Program to count how many vowels (a, e, i, o, u) exist in a string.  
// 💡 Example: Input = "Abdessalem" → Output = 4 



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



short CountVowels(string S1) {

    short counter = 0;

    for (short i = 0; i < S1.length(); i++) {

        if (IsVowel(S1[i])) {
            counter++;
        }

    }

    return counter;
}



int main()
{
    string S1 = ReadString();

    cout << "Number Of Vowels is : " << CountVowels(S1) << endl;

}


