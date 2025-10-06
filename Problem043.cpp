
#include <iostream>
#include <string>
#include <vector>

// 📝 Program to replace a specific word in a string using Split and Join functions in C++.
// ⚙️ It allows replacing words with or without matching case (case-sensitive or case-insensitive).
// 🔍 Uses custom functions: SplitString(), JoinString(), and LowerAllString().
// 💡 Example:
//    Input  : "Welcome to Jordan , Jordan is a nice country"
//    Replace: "jordan" → "Algeria"
// 👉 Output with Match Case      : "Welcome to Jordan , Jordan is a nice country"
// 👉 Output without Match Case   : "Welcome to Algeria , Algeria is a nice country"


using namespace std;


string LowerAllString(string S) {
    
    for (short i = 0; i < S.length(); i++) {
        S[i] = tolower(S[i]);
    }

    return S;

}


vector <string> SplitString(string S1, string delim) {

    vector <string> vString;
    string sWord;
    short pos = 0;

    while ((pos = S1.find(delim)) != string::npos) {

        sWord = S1.substr(0, pos);

        if (sWord != "") {

            vString.push_back(sWord);

        }

        S1.erase(0, pos + delim.length());

    }

    if (S1 != "") {

        vString.push_back(S1);

    }

    return vString;

}


string JoinString(vector <string> vString, string delim) {

    string S1 = "";

    for (string& s : vString) {

        S1 = S1 + s + delim;

    }

    S1 = S1.substr(0, S1.length() - delim.length());

    return S1;
}



string ReplaceWordInStringUsingSplit(string S1 , string StringToReplace , string sReplaceTo ,bool MatchCase = true ) {

    vector <string> vString;
    vString = SplitString(S1 , " ");

    string S2 = "";

    for (string& s : vString) {
        
        if (s == StringToReplace && MatchCase) {
            s = sReplaceTo;
        }
        else if (LowerAllString(s) == LowerAllString(StringToReplace) && !MatchCase) {
            s = sReplaceTo;
        }

        

    }

    return  JoinString(vString , " ");


}



int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "jordan";
    string sReplaceTo = "Algeria";

    cout << "Original String : \n" << S1;


    cout << "\n\nReplace with match case : \n";
    cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, sReplaceTo );


    cout << "\n\nReplace with don't match case : \n";
    cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, sReplaceTo , false);

    system("pause>0");
}

