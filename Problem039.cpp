
#include <iostream>
#include <string>
#include <vector>

// 🔗 Program to join a vector of strings into one string with a delimiter.  
// 🔹 JoinString() → Combines all strings in a vector separated by a chosen delimiter.  
// 💡 Example: vString = {"Abdessalem", "Mohammed", "Abderahem"} , Delim = " "  
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



int main()
{
	vector <string> vString = { "Abdessalem" , "Mohammed" , "Abderahem" };

	cout << "Vector after join : \n\n" << JoinString(vString , " ");
	
	system("pause>0");

}


