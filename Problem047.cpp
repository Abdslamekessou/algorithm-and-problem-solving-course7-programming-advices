
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


// 🧠✨ Problem: Build a program to add multiple clients to a text file (Clients.txt).
// 💾 Each client’s data (AccountNumber, PinCode, Name, Phone, Balance) is saved as one line in the file.
// 🧩 The line format uses "#//#" as a separator between fields.
// 🔁 The program keeps asking if the user wants to add another client (Y/N).
// 💡 Example:
// Input → 
// Account: A123  
// Pin: 9999  
// Name: Abdessalem  
// Phone: 07900000  
// Balance: 15000  
// Output → "A123#//#9999#//#Abdessalem#//#07900000#//#15000" added to Clients.txt


using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient {

    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};


stClient  ReadNewClient() {

    stClient Client;

    cout << "\nEnter Account Number?" << endl;
    getline(cin >> ws, Client.AccountNumber);

    cout << "\nEnter Pin Code?" << endl;
    getline(cin, Client.PinCode);

    cout << "\nEnter Name?" << endl;
    getline(cin, Client.Name);

    cout << "\nEnter Phone?" << endl;
    getline(cin, Client.Phone);


    cout << "\nEnter Account Balance?" << endl;
    cin >> Client.AccountBalance;

    return Client;

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



void AddClientToFile(string FileName ,string stDataLine) {

    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open()) {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}



void AddNewClient() {
    stClient sClient;

    sClient = ReadNewClient();

    AddClientToFile(ClientsFileName , ConvertRecordToLine(sClient) );
}



void AddClients() {

    char AddMore = 'Y';
    
    while(toupper(AddMore) == 'Y') {

        system("cls");
       
        cout << "Adding New Client : " << endl;

        AddNewClient();

        cout << "\n\nClient Added Successfully , do you want to add more clients?" << endl;
        cin >> AddMore;

    }

}

int main()
{
    AddClients();
}
