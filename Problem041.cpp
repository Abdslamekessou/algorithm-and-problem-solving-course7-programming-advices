
#include <iostream>
#include <string>
#include <vector>

// 🔄 Program to reverse the order of words in a string.  
// ✂️ Uses SplitString() to separate words and iterator to reverse them.  
// 🧩 Words are split by spaces and joined back in reverse order.  
// 💡 Example: Input = "Abdessalem Kessouri study Programming Advices"  
// 👉 Output: "Advices Programming study Kessouri Abdessalem"


using namespace std;


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}



vector <string> SplitString(string S1 , string delim) {

    vector <string> vString;
    string sWord;
    short pos = 0;

    while ((pos = S1.find(delim)) != string::npos ) {

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



string ReverseWordsInString(string S1) {

    vector <string> vString;
    string S2 = "";
    
    vString = SplitString(S1, " ");

    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin()) {

        --iter;

        S2 += *iter + " ";
    }

    S2 = S2.substr(0, S2.length() - 1);

    return S2;

}



int main()
{

    string S1 = ReadString();
  
    cout << "\n\nString after reversing words : \n";
    cout << ReverseWordsInString(S1);

    system("pause>0");
    
}

