#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>


// 🧠✨ Problem: Delete a client from the file by their Account Number.
// 📂 Each line in "Clients.txt" contains client data separated by "#//#" like:
// "A123#//#9999#//#Abdessalem#//#07900000#//#15000"
//
// 🗂️ The program loads all clients from the file into a vector,
// finds the client with the entered account number, displays their details,
// and asks for confirmation before deleting.
//
// ⚙️ If the user confirms (Y/y):
//  - The client is marked for deletion.
//  - The file is rewritten without the deleted record.
//  - A success message is displayed.
//
// ❌ If not found:
//  - It displays: "Client With Account Number (A999) Not Found"
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
// Do you want to delete client(Y/N)?
// Y
//
// Client Deleted Successfully


using namespace std;

const string ClientsFileName = "Clients.txt";


struct stClient {

    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;

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



string ConvertRecordToLine(stClient Client, string Seperator = "#//#") {

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}



vector <stClient> LoadClientsDataFromFile(string FileName) {

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



void SaveClientsToVector(string FileName, vector <stClient> vClients) { 

    fstream MyFile;

    MyFile.open(FileName, ios::out);

    if (MyFile.is_open()) {

        stClient Client;
        string line = "";

        for (stClient& C : vClients) {

            if (C.MarkForDelete == false) {

                line = ConvertRecordToLine(C);
                MyFile << line << endl;

            }


        }


        MyFile.close();
    }

}



void PrintClientRecord(stClient Client) {

    cout << "\n\nThe following is client record data :" << endl;
    cout << "\nAccount Number   :  " << Client.AccountNumber << endl;
    cout << "Pin Code         :  " << Client.PinCode << endl;
    cout << "Name             :  " << Client.Name << endl;
    cout << "Phone            :  " << Client.Phone << endl;
    cout << "Account Balance  :  " << fixed << setprecision(2) << Client.AccountBalance << endl;
}



bool FindClientByAccountNumber(string AccountNumber , vector <stClient> vClients , stClient& Client) {


    for (stClient& C : vClients) {

        if (C.AccountNumber == AccountNumber) {

            Client = C;

            return true;
        }

    }

    return false;

}



bool MarkClientForDeleteByAccountNumber(string AccountNumber , vector <stClient> &vClients) {

    for (stClient& C : vClients) {

        if (C.AccountNumber == AccountNumber) {

            C.MarkForDelete = true ;

            return true;
        }

    }

    return false;

}



bool DeleteClientByAccountNumber(string AccountNumber , vector <stClient> &vClients) {

    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        PrintClientRecord(Client);

        cout << "\nDo you want to delete client(Y/N)? " << endl;
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y') {

            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);

            SaveClientsToVector(ClientsFileName, vClients);

            vClients = LoadClientsDataFromFile(ClientsFileName);

            cout << "\nClient Deleted Successfully\n";
          
            return true;
        }


    }
    else {

        cout << "\nClient With Account Number (" << AccountNumber << ") Not Found\n";
      
        return false;
      
    }

}



int main()
{
    vector <stClient> vClients;
    vClients = LoadClientsDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNumber(AccountNumber, vClients);

}
