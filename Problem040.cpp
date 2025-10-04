
#include <iostream>
#include <string>
#include <vector>


// 🔗 Program to join multiple strings (from a vector or array) into one string using a delimiter.  
// ⚙️ Demonstrates *function overloading* — same function name, different parameters.  
// 🧩 JoinString() → Works for both vectors and arrays of strings.  
// 💡 Example: {"Abdessalem", "Mohammed", "Abderahem"} , Delim = " "  
// 👉 Output: "Abdessalem Mohammed Abderahem"



using namespace std;



string JoinString(vector <string> vString , string delim) {

	string S1 = "";

	for (string& s : vString) {

		S1 = S1 + s + delim;

	}

	S1 = S1.substr(0, S1.length() - delim.length());

	return S1;
}




string JoinString(string arrString[], short length, string delim) {

	string S1 = "";

	for (short i = 0; i < length; i++) {

		S1 = S1 + arrString[i] + delim ;

	}

	S1 = S1.substr(0, S1.length() - delim.length());

	return S1;
}




int main()
{
	vector <string> vString = { "Abdessalem" , "Mohammed" , "Abderahem" };

	string arrString[] = { "Abdessalem" , "Mohammed" , "Abderahem" };

	cout << "Vector after join : \n" << JoinString(vString , " ");

	cout << "\n\nArray after join : \n" << JoinString(arrString, 3," ");
	
	system("pause>0");

}


