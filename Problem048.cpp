
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>


// 🧠✨ Problem: Display all clients’ data from a text file (Clients.txt) in a clean table format.
// 📂 Each client record in the file looks like: 
// "A123#//#9999#//#Abdessalem#//#07900000#//#15000"
// 🧩 The program reads each line, splits it into fields, and converts it into a struct (stClient).
// 📊 Then it prints all clients in a nicely formatted table with columns (Account, Pin, Name, Phone, Balance).
// 💡 Example Output:
//
// ┌──────────────────────────────────────────────────────────────┐
// | Account Number | Pin Code | Client Name | Phone | Balance    |
// ├──────────────────────────────────────────────────────────────┤
// | A123           | 9999     | Abdessalem  | 07900000 | 15000.00|
// └──────────────────────────────────────────────────────────────┘



using namespace std;

const string ClientsFileName = "Clients.txt";

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



void PrintClientRecord(stClient sClient) {

    cout << left;

    cout<< "| " << setw(15) << sClient.AccountNumber 
        << "| " << setw(15) << sClient.PinCode 
        << "| " << setw(30) << sClient.Name 
        << "| " << setw(18) <<sClient.Phone 
        << "| " << setw(18) << fixed << setprecision(2) <<sClient.AccountBalance 
        << "\n";

}



void PrintAllClientsData(vector <stClient> vClients) {

    cout << "\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n\n";
    cout << "----------------------------------------------------------------------------------------------------------------------\n\n";

    cout << left;
    cout << "| " << setw(15) << "Account Number";
    cout << "| " << setw(15) << "Pin Code";
    cout << "| " << setw(30) << "Client Name";
    cout << "| " << setw(18) << "Phone";
    cout << "| " << setw(18) << "Balance";
    cout << "\n\n";
    cout << "----------------------------------------------------------------------------------------------------------------------\n\n";
    

    for (stClient Client : vClients) {

        PrintClientRecord(Client);

    }

    cout << "\n";
    cout << "----------------------------------------------------------------------------------------------------------------------\n\n";
    
}



int main()
{
    vector <stClient> vClients;

    vClients = LoadClientsLineDataFromFile(ClientsFileName);
    
    PrintAllClientsData(vClients);

}
