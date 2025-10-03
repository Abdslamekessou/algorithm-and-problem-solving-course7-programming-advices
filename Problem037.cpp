
#include <iostream>
#include <string>
#include <vector>


// ✂️ Program to split a string into words (tokens) using a delimiter (space).  
// 📦 The words are stored inside a vector<string>.  
// 🔍 Then we print the number of tokens + each word separately.  
// 💡 Example: Input = "Abdessalem Kessouri study in Programming Advices"  
// 👉 Output:  
// Tokens = 5  
// Abdessalem  
// Kessouri  
// study  
// in  
// Programming  
// Advices  


using namespace std;


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}


vector <string> SplitString(string S1 , string Delim) {

    vector <string> vString;
    string sWord;
    short pos = 0;

    while ((pos = S1.find(Delim)) != string::npos) {

        sWord = S1.substr(0, pos);

        if (sWord != "") {

            vString.push_back(sWord);

        }

        S1 = S1.erase(0, pos + Delim.length());

    }

  
    if (S1 != "") {

        vString.push_back(S1);

    }

    return vString;

}




int main()
{
    vector <string> vString;

    vString = SplitString(ReadString(), " ");

    cout << "\nTokens = " << vString.size() << "\n\n";

    for (string& s : vString) {

        cout << s << endl;

    }

    system("pause>0");

}
