
#include <iostream>
#include <string>

// 📝 Write a C++ program that reads a string from the user  
// 🔡 Then convert the first letter of each word to lowercase  
// 📌 Example:  
// Input  : "Abdessalem Kessouri Study From Programming Advices By Dr Mohammed Abu-Hadhoud"  
// Output : "abdessalem kessouri study from programming advices by dr mohammed abu-hadhoud"  


using namespace std;



string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}



string LowerFirstLetterOfEachWord(string S1) {

    bool isFirstLetter = true;


    for (short i = 0; i < S1.length(); i++) {

        if (S1[i] != ' ' && isFirstLetter) {

            S1[i] = tolower(S1[i]);

        }

        isFirstLetter = (S1[i] == ' ' ? true : false);

    }

    return S1;

}




int main()
{
    string S1 = ReadString();

    cout << "\nString After Conversion : \n";

    S1 = LowerFirstLetterOfEachWord(S1);

    cout << S1 << endl;

    system("pause>0");
}

