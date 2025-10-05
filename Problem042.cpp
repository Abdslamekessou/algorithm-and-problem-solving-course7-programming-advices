
#include <iostream>
#include <string>
#include <vector>

// 📝 Program to replace all occurrences of a word in a string using C++ built-in functions.  
// 🔁 Uses find() and replace() to search and modify each match.  
// 💡 Example: Input  : "Welcome to Jordan, Jordan is a nice country"  
// 🔄 Replace "Jordan" with "Algeria"  
// 👉 Output : "Welcome to Algeria, Algeria is a nice country"


using namespace std;


string ReplaceWordInStringUsingBuiltInFunction(string S1 , string StringToReplace , string sReplaceTo) {

    short pos = S1.find(StringToReplace);

    while (pos != string::npos) {

        S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);

        pos = S1.find(StringToReplace);

    }

    return S1;

}



int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "Jordan";
    string sReplaceTo = "Algeria";

    cout << "Original String : \n" << S1;
    

    cout << "\n\nString after replace : \n";
    cout << ReplaceWordInStringUsingBuiltInFunction(S1 , StringToReplace , sReplaceTo);

    system("pause>0");

}

