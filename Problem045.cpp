
#include <iostream>
#include <string>
#include <vector>


// 🧠✨ Problem: Create a program to read a client's information and convert it into one line of text.
// 🧩 The data includes: Account Number, Pin Code, Name, Phone, and Account Balance.
// 🧾 Each field should be separated by "#//#" for easy saving or reading from a file.
// 💡 Example:
// Input → Account: A123 , Pin: 4567 , Name: Abdessalem , Phone: 0770000000 , Balance: 2000
// Output → A123#//#4567#//#Abdessalem#//#0770000000#//#2000


using namespace std;

struct stClient {

    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};


stClient  ReadNewClient() {

    stClient Client;

    cout << "Please Enter Client Data : \n";
    
    cout << "\nEnter Account Number?" << endl;
    getline(cin , Client.AccountNumber);

    cout << "\nEnter Pin Code?" << endl;
    getline(cin , Client.PinCode);

    cout << "\nEnter Name?" << endl;
    getline(cin , Client.Name);

    cout << "\nEnter Phone?" << endl;
    getline(cin , Client.Phone);


    cout << "\nEnter Account Balance?" << endl;
    cin >> Client.AccountBalance;

    return Client;

}


string ConvertRecordToLine(stClient Client , string Seperator = "#//#") {

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}


int main()
{
    stClient Client;
    
    Client = ReadNewClient();

    cout << "Client Record For Saving is : \n";
    cout << ConvertRecordToLine(Client);

    system("pause>0");
}


