#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>


// 🧠✨ Problem: Build a full client management system (Bank Management App).
// 📂 Each client's data is stored in "Clients.txt" separated by "#//#", for example:
// "A123#//#9999#//#Abdessalem#//#07900000#//#15000"
//
// ⚙️ The program manages client accounts: add, delete, update, find, and list all clients.
// 💵 New Feature Added: Transactions Menu (Deposit, Withdraw, Show Total Balance).
//
// 🧩 Features:
// ✅ Display all clients in a formatted table.
// ➕ Add new clients (checks duplicate Account Numbers).
// ✏️ Update client info (Pin, Name, Phone, Balance).
// 🗑️ Delete clients safely after confirmation.
// 🔍 Search for clients by Account Number.
// 💰 Deposit or withdraw money from an account.
// 📊 Show total balances for all clients.
// 🚪 Exit safely with a goodbye message.
//
// 💡 Example Output:
// ===========================================
//         Main Menue Screen
// ===========================================
// [1] Show Client List.
// [2] Add New Client.
// [3] Delete Client.
// [4] Update Client Info.
// [5] Find Client.
// [6] Transactions.
// [7] Exit.
// ===========================================
// Choose what do you want to do? [1 to 7]? 6
//
// -----------------------------------
//      Transactions Menu
// -----------------------------------
// [1] Deposit
// [2] Withdraw
// [3] Total Balances
// [4] Main Menu


using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenu();
void ShowTransactionsMenu();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};


vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;


    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;

}


sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); //cast string to double
    return Client;
}


string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}


bool ClientExistsByAccountNumber(string AccountNumber, string FileName) {

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {

        string line;
        sClient Client;

        while (getline(MyFile, line)) {

            Client = ConvertLinetoRecord(line);

            if (Client.AccountNumber == AccountNumber) {

                MyFile.close();

                return true;

            }
        }

        MyFile.close();

    }

    return false;

}

sClient ReadNewClient() {

    sClient Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName)) {

        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);

    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}



vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}


void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}


void ShowAllClientsScreen()
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0) {

        cout << "\t\t\t\tNo Clients Available In the System!";

    }
    else {

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
}


void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;
}


sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}


bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    for (sClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;
}


vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vClients;
}

void AddDataLineToFile(string FileName, string stDataLine) {

    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open()) {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}

void AddNewClient() {

    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddNewClients() {

    char AddMore = 'Y';

    do {

        cout << "\nAdding New Client:\n\n";

        AddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients) {

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);

            SaveCleintsDataToFile(ClientsFileName, vClients);

            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;

        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }

}


bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients) {

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            for (sClient& C : vClients) {

                if (C.AccountNumber == AccountNumber) {

                    C = ChangeClientRecord(AccountNumber);
                    break;
                }

            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;

        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }

}


string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}


void ShowDeleteClientScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}


void ShowUpdateClientScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}


void ShowAddNewClientsScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();
}

void ShowFindClientScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        PrintClientCard(Client);

    }
    else {
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
    }

}


void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

enum enMainMenueOptions
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eShowTransactionsMenu = 6, eExit = 7
};

enum enTransactionsOptions {
    eDeposit = 1,
    eWithdraw = 2,
    eShowTotalBalance = 3,
    eShowMainMenu = 4

};

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 7]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void GoBackToMainMenue() {

    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenu();

}

void GoBackToTransactionsMenu() {

    cout << "\n\nDo you want to go back to Transactions Menu...\n";
    system("pause>0");
    ShowTransactionsMenu();

}

short ReadTransactionsMenuOption() {

    cout << "\n\nChoose what do you want to do? [1 to 4]? ";

    short Choice = 0;
    cin >> Choice;

    return Choice;
}



bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients) {

    char Answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y') {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Succesfully . New Balance is : " << C.AccountBalance;
                return true;
            }

        }

        return false;
        
    }
    
}


void ShowDepositScreen() {

    system("cls");

    cout << "===========================================\n";
    cout << "\tDeposit Screen\n";
    cout << "===========================================\n";

    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();

    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;


    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
    
}


void ShowWidthrawScreen() {

    system("cls");

    cout << "===========================================\n";
    cout << "\tWidthraw Screen\n";
    cout << "===========================================\n";

    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();

    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    while (Amount > Client.AccountBalance) {
        cout << "\nAmount Exceeds the balance , you can withdraw up to : " <<Client.AccountBalance;
        cout << "\n\nPlease enter another amount? ";
        cin >> Amount;
    }


    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1 , vClients);
}

void PrintClientRecordBalanceLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowTotalBalances() {

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0) {

        cout << "\t\t\t\tNo Clients Available In the System!";

    }
    else {

        for (sClient Client : vClients)
        {
            
            PrintClientRecordBalanceLine(Client);
            cout << endl;

            TotalBalances += Client.AccountBalance;
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t\t\t Total Balances = " << TotalBalances << endl;
    }

}



void ShowTotalBalanceScreen() {

    system("cls");

    ShowTotalBalances();


}

void PerformTransactionMenuOption(enTransactionsOptions TransactionsOptions) {
    
    switch (TransactionsOptions) {

     case enTransactionsOptions::eDeposit :
         ShowDepositScreen();
         GoBackToTransactionsMenu();
         break;

     case enTransactionsOptions::eWithdraw:
         ShowWidthrawScreen();
         GoBackToTransactionsMenu();
         break;

     case enTransactionsOptions::eShowTotalBalance:
         ShowTotalBalanceScreen();
         GoBackToTransactionsMenu();
         break;
     
     case enTransactionsOptions::eShowMainMenu:
         GoBackToMainMenue();
         break;
     
    }

}

void ShowTransactionsMenu() {

    system("cls");
    cout << "===========================================\n";
    cout << "\tTransactions Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Widthraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menu.\n";

    PerformTransactionMenuOption((enTransactionsOptions)ReadTransactionsMenuOption());
}

void PerfromMainMenuOperation(enMainMenueOptions MainMenueOption) {

    switch (MainMenueOption) {

    case enMainMenueOptions::eListClients:
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;


    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eShowTransactionsMenu:
        system("cls");
        ShowTransactionsMenu();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    }

}

void ShowMainMenu() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "===========================================\n";
    PerfromMainMenuOperation((enMainMenueOptions)ReadMainMenueOption());
}


int main()
{
    ShowMainMenu();
}

