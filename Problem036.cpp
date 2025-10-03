
#include <iostream>
#include <string>

using namespace std;


// 📝 Program to count the number of words in a string.  
// ✂️ Words are separated by spaces.  
// 💡 Example: Input = "Programming Advices Mohammed Abu-Hadhoud"  
// 👉 Output = 4  


string ReadString() {

    string S1;

    cout << "Please Enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}



short CountWords(string S1) {

    string delim = " ";
    short pos = 0;
    short counter = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos) {
        
        sWord = S1.substr(0, pos);

        if (sWord != "") {
            counter++;
        }

        S1.erase(0, pos + delim.length());
        
    }

  
    if (S1 != "") {
        counter++;
    }
    
    return counter;

}



int main()
{
    string S1 = ReadString();

    cout << "The number of words in string is : " << CountWords(S1);

    system("pause>0");
}

