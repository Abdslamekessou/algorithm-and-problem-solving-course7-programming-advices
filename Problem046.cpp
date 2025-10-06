
#include <iostream>
#include <string>
#include <vector>


// 🧠✨ Problem: Convert a line of client data into a structured record (object) and display it clearly.
// 📜 The line contains all client fields separated by "#//#".
// 🧩 Each part should be split and stored in a struct with fields: AccountNumber, PinCode, Name, Phone, and AccountBalance.
// 💡 Example:
// Input → "fa4#//#1234#//#Kessouri Abdessalem#//#07909203#//#5000.990234"
// Output → 
// Account Number: fa4
// Pin Code: 1234
// Name: Kessouri Abdessalem
// Phone: 07909203
// Account Balance: 5000.990234


using namespace std;


struct stClient {

    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};



vector <string> SplitString(string Line, string Seperator) {

    vector <string> vString;
    string sWord;
    short pos = 0;

    while ((pos = Line.find(Seperator)) != string::npos) {

        sWord = Line.substr(0, pos);

        if (sWord != "") {

            vString.push_back(sWord);

        }

        Line.erase(0, pos + Seperator.length());

    }

    if (Line != "") {

        vString.push_back(Line);

    }

    return vString;

}



stClient ConvertLineToRecord(string Line , string Seperator) {

    stClient sClient;
    vector <string> vClientData;

    vClientData = SplitString(Line, Seperator);

    sClient.AccountNumber = vClientData[0];
    sClient.PinCode = vClientData[1];
    sClient.Name = vClientData[2];
    sClient.Phone = vClientData[3];
    sClient.AccountBalance = stod(vClientData[4]);

    return sClient;
}


void PrintClientRecord(stClient Client) {

    cout << "\n\nThe following is extracted client record :" << endl;
    cout << "\nAccount Number   :  " << Client.AccountNumber << endl;
    cout << "Pin Code         :  " << Client.PinCode << endl;
    cout << "Name             :  " << Client.Name << endl;
    cout << "Phone            :  " << Client.Phone << endl;
    cout << "Account Balance  :  " << Client.AccountBalance << endl;
}



int main()
{

    string stLine = "fa4#//#1234#//#Kessouri Abdessalem#//#07909203#//#5000.990234";

    cout << "Line Record is : \n";
    cout << stLine;

    stClient sClient = ConvertLineToRecord(stLine, "#//#");

    PrintClientRecord(sClient);
}


