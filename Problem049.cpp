
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

// 🧠✨ Problem: Search for a client in the file by their Account Number and display their details.
// 📂 Each line in "Clients.txt" contains client data separated by "#//#" like:
// "A123#//#9999#//#Abdessalem#//#07900000#//#15000"
// 🔍 The program reads all clients from the file, looks for the one with the entered account number,
// and displays their information if found.
//
// ✅ Example Output:
//
// Please enter AccountNumber? A123
//
// The following is extracted client record :
// Account Number   :  A123
// Pin Code         :  9999
// Name             :  Abdessalem
// Phone            :  07900000
// Account Balance  :  15000.00
//
// ❌ If not found:
// Client With Account Number (A999) Not Found



using namespace std;

const string ClientsFileName = "Clients.txt";


struct stClient {

    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};


string ReadClientAccountNumber() { 

     string AccountNumber = "";   

     cout << "\nPlease enter AccountNumber? ";     
     cin >> AccountNumber; 

     return AccountNumber; 
}



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



stClient ConvertLineToRecord(string Line, string Seperator = "#//#") {

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



vector <stClient> LoadClientsLineDataFromFile(string FileName) {

    vector <stClient> vClients;

    fstream MyFile;


    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {

        string Line;
        stClient Client;

        while (getline(MyFile, Line)) {

            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);

        }


        MyFile.close();
    }

    return vClients;

}




void PrintClientRecord(stClient Client) {

    cout << "\n\nThe following is extracted client record :" << endl;
    cout << "\nAccount Number   :  " << Client.AccountNumber << endl;
    cout << "Pin Code         :  " << Client.PinCode << endl;
    cout << "Name             :  " << Client.Name << endl;
    cout << "Phone            :  " << Client.Phone << endl;
    cout << "Account Balance  :  " << fixed << setprecision(2) <<Client.AccountBalance << endl;
}



bool FindClientByAccountNumber(stClient &Client, string AccountNumber) {

    vector <stClient> vClients;

    vClients = LoadClientsLineDataFromFile(ClientsFileName);

    for (stClient &C : vClients) {

        if (C.AccountNumber == AccountNumber) {

            Client = C ;

            return true;
        }

    }

    return false;

}



int main()
{
    stClient Client;

    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(Client, AccountNumber)) {

        PrintClientRecord(Client);
    }
    else {
        cout << "\nClient With Account Number (" << AccountNumber << ") Not Found\n";
    }
}
