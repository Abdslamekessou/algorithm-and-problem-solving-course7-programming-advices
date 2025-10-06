
#include <iostream>
#include <string>
#include <vector>


// 📝 Program to remove punctuation marks from a given string in C++.
// ⚙️ It checks every character and removes symbols like , . ; ! ? etc.
// 🔍 Uses ispunct() to detect punctuation characters.
// 💡 Example:
//    Input  : "Welcome to Jordan , Jordan it's an amazing country;"
// 👉 Output : "Welcome to Jordan  Jordan its an amazing country"


using namespace std;



string RemovePunctuationsFromString(string S1) {

    string S2 = "";

    for (short i = 0; i < S1.length(); i++) {
        
        if (!ispunct(S1[i]))
              S2 += S1[i];
        
  }

    return S2;

}



int main()
{
    string S1 = "Welcome to Jordan , Jordan it's an amazing country;";
  
    cout << "Original String : \n" << S1;

    cout << "\n\nPauncuations Removed: \n";
    cout << RemovePunctuationsFromString(S1);


    system("pause>0");
}

