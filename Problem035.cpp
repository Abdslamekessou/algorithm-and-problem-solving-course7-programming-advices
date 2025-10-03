
#include <iostream>
#include <string>


// 📝 Program to split a string into words and print each word in a new line.  
// 💡 Example: Input = "Programming Advices Mohammed Abu-Hadhoud"  
// 👉 Output =  
// Programming  
// Advices  
// Mohammed  
// Abu-Hadhoud  


using namespace std;


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}



void PrintEachWordInString(string S1) {

    string delim = " ";
    short pos = 0;
    string sWord;

    cout << "\nYour String Words Are : \n\n";

    while ((pos = S1.find(delim)) != std::string::npos) {

        sWord = S1.substr(0, pos);

        if (sWord != " ") {
            cout << sWord << endl;
        }

        S1 = S1.erase(0, pos + delim.length());
    }


    if (S1 != " ") {
        cout << S1 << endl;
    }


}



int main()
{
    string S1 = ReadString();

    PrintEachWordInString(S1);
}

