
#include <iostream>
#include <string>
#include <cctype>

// 📝 Write a C++ program that reads a character from the user  
// 🔄 Then invert its case: uppercase → lowercase, lowercase → uppercase  
// 📌 Example :  
// Input  : 'a'  
// Output : 'A' 


using namespace std;


char ReadChar() {

    char Ch1;

    cout << "Please Enter a Character?" << endl;
    cin >> Ch1;

    return Ch1;
}



char InvertLetterCase(char Ch1) {

    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);

}



int main()
{
    char Ch1 = ReadChar();
    
    Ch1 = InvertLetterCase(Ch1);
    cout << "\nChar after inverting case : \n";
    cout << Ch1 << endl;


    system("pause>0");
}
