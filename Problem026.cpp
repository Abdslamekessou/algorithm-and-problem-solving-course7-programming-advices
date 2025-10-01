
#include <iostream>
#include <string>

// 📝 Write a C++ program that reads a string from the user  
// 🔠 Then print the string with all characters in uppercase  
// 🔡 Then print the string with all characters in lowercase  
// 📌 Example:  
// Input  : "Mohammed Abu-Hadhoud Programming Advices"  
// Output :  
// String After Upper :  
// MOHAMMED ABU-HADHOUD PROGRAMMING ADVICES  
//  
// String After Lower :  
// mohammed abu-hadhoud programming advices  



using namespace std;


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}



string UpperAllString(string S1) {

    bool isFirstLetter = true;


    for (short i = 0; i < S1.length(); i++) {

        S1[i] = toupper(S1[i]);

    }

    return S1;

}



string LowerAllString(string S1) {

    bool isFirstLetter = true;


    for (short i = 0; i < S1.length(); i++) {

            S1[i] = tolower(S1[i]);

    }

    return S1;

}




int main()
{
    string S1 = ReadString();

    cout << "\nString After Upper : \n";

    S1 = UpperAllString(S1);

    cout << S1 << endl;


    cout << "\nString After Lower : \n";

    S1 = LowerAllString(S1);

    cout << S1 << endl;

    system("pause>0");
}

