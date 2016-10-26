#include "system.h"
using namespace std;

//--------------Public--------------------------------------
//
void System::MainFrame() {
        /* code */
        std::cout << "-----------------------------------------------\n" << std::endl;
        std::cout << "\tWelcome to Neo Bank System v1.0.0\n" << std::endl;
        std::cout << "-----------------------------------------------\n" << std::endl;

        int choice=0;

        cout << "Please select your role < 1.Client or 2.Customer > : ";
        while(!(cin>>choice) || (choice!=1 && choice!=2)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input; please re-enter: ";
        }
        system("clear");
        if(choice == 1) {
                ATMServer();
        }
        else{
                ManagerServer();
        }
}

/*****************************************/
void System::ATMServer(){
        cout << "Welcome to the ATM server.\n\n" << endl;
        if (ClientVerify() == true) {
                DisplayATMMenu();
        }
}

void System::DisplayATMMenu(){
        cout << "\tWelcome, " << currUser->GetName() << "\n"<< endl;
        cout<<"Please Choose the service you want < 1-6 > : ";
        cout << "\t1. Check balance\n" << endl;
        cout << "\t2. Deposit Money\n" << endl;
        cout << "\t3. Withdraw Money.\n" << endl;
        cout << "\t4. Transfer Money.\n" << endl;
        cout << "\t5. Print execution traces\n" << endl;
        cout << "\t6. Logout\n\n" << endl;
        int input;
        while(!(cin>>input) || input<1 || input>6) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input; please re-enter.\n";
        }
        system("clear");
        switch (input) {
        case 1: CheckBalance(); break;
        case 2: DepositMoney(); break;
        case 3: WithdrawMoney(); break;
        case 4: TransferMoney(); break;
        case 5: PrintTrace(); break;
        default: Logout();
        }
}

void System::CheckBalance(){
        int acc;
        cout << "Choose the account you want to know : 1.chequing, 2.saving :";
        while(!(cin>>acc) || (acc!=1 && acc!=2)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input; please re-enter: ";
        }
        if (acc == 1) {
                double b = currUser->GetChequingBalance();
                if (b < 0) {
                        std::cout << "Sorry, you do not have a chequing account;" << std::endl;
                        system("pause");
                }
                else{
                        std::cout << "Your chequing account balance is " << to_string(b) << std::endl;
                        system("pause");
                }
        }
        else{
                double b = currUser->GetSavingBalance();
                if (b < 0) {
                        std::cout << "Sorry, you do not have a saving account;" << std::endl;
                        system("pause");
                }
                else{
                        std::cout << "Your saving account balance is " << to_string(b) << std::endl;
                        system("pause");
                }
        }
        system("clear");
        DisplayATMMenu();
}

void System::DepositMoney(){
        string event;
        int acc;
        cout << "Choose the account you want to deposit to : 1.chequing, 2.saving :";
        while(!(cin>>acc) || (acc!=1 && acc!=2)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input; please re-enter: ";
        }
        if (acc == 1) {
                bool b = currUser->GetChequing().first;
                if (b == false) {
                        std::cout << "Sorry, you do not have a chequing account;" << std::endl;
                        system("pause");
                }
                else{
                        double amount;
                        std::cout << "Please enter the amount you are going to deposit: ";
                        while(!(cin>>amount) || (amount < 0)) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "Invalid input; please re-enter: ";
                        }
                        double balance = currUser->DepositChequing(amount);
                        event = "Your have successfully deposit " + to_string(amount) + " into your chequing account.";
                        std::cout << event << endl;
                        std::cout << "Your chequing account balance is " << to_string(balance) << std::endl;
                        if (traceable == true) {
                                currUser->AddTrace(event);
                        }
                        system("pause");
                }
        }
        else{
                bool b = currUser->GetSaving().first;
                if (b == false) {
                        std::cout << "Sorry, you do not have a saving account;" << std::endl;
                        system("pause");
                }
                else{
                        double amount;
                        std::cout << "Please enter the amount you are going to deposit: ";
                        while(!(cin>>amount) || (amount < 0)) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "Invalid input; please re-enter: ";
                        }
                        double balance = currUser->DepositSaving(amount);
                        event = "Your have successfully deposit " + to_string(amount) + " into your saving account.";
                        std::cout << event << endl;
                        std::cout << "Your saving account balance is " << to_string(balance) << std::endl;
                        if (traceable == true) {
                                currUser->AddTrace(event);
                        }
                        system("pause");
                }
        }
        system("clear");
        DisplayATMMenu();
}

void System::WithdrawMoney(){
        string event;
        int acc;
        cout << "Choose the account you want to withdraw from : 1.chequing, 2.saving :";
        while(!(cin>>acc) || (acc!=1 && acc!=2)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input; please re-enter: ";
        }
        if (acc == 1) {
                bool b = currUser->GetChequing().first;
                if (b == false) {
                        std::cout << "Sorry, you do not have a chequing account;" << std::endl;
                        system("pause");
                }
                else{
                        double amount;
                        std::cout << "Please enter the amount you are going to withdraw: ";
                        while(!(cin>>amount) || (amount < 0)) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "Invalid input; please re-enter: ";
                        }
                        double balance = currUser->WithdrawChequing(amount);
                        if (balance < 0) {
                                std::cout << "Sorry, you do not have enough money in your chequing account." << endl;
                        }
                        else{
                                event = "Your have successfully withdraw " + to_string(amount) + " from your chequing account.";
                                std::cout << event << endl;
                                std::cout << "Your chequing account balance is " << to_string(balance) << std::endl;
                                if (traceable == true) {
                                        currUser->AddTrace(event);
                                }
                        }
                        system("pause");
                }
        }
        else{
                bool b = currUser->GetSaving().first;
                if (b == false) {
                        std::cout << "Sorry, you do not have a saving account;" << std::endl;
                        system("pause");
                }
                else{
                        double amount;
                        std::cout << "Please enter the amount you are going to withdraw: ";
                        while(!(cin>>amount) || (amount < 0)) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "Invalid input; please re-enter: ";
                        }
                        double balance = currUser->WithdrawSaving(amount);
                        if (balance < 0) {
                                std::cout << "Sorry, you do not have enough money in your chequing account." << endl;
                        }
                        else{
                                event = "Your have successfully withdraw " + to_string(amount) + " from your saving account.";
                                std::cout << event << endl;
                                std::cout << "Your saving account balance is " << to_string(balance) << std::endl;
                                if (traceable == true) {
                                        currUser->AddTrace(event);
                                }
                        }
                        system("pause");
                }
        }
        system("clear");
        DisplayATMMenu();
}

void System::TransferMoney(){
        string event;
        bool b = currUser->GetChequing().first;
        if (b == false) {
                std::cout << "Sorry, you do not have a chequing account;" << std::endl;
                system("pause");
        }
        else{
                b = currUser->GetSaving().first;
                if (b == false) {
                        std::cout << "Sorry, you do not have a chequing account;" << std::endl;
                        system("pause");
                }
                else{

                }
        }

        int acc;
        cout << "Choose the account you want to transfer from : 1.chequing, 2.saving :";
        while(!(cin>>acc) || (acc!=1 && acc!=2)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input; please re-enter: ";
        }
        if (acc == 1) {
                double amount;
                std::cout << "Please enter the amount you are going to transfer from: ";
                while(!(cin>>amount) || (amount < 0)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input; please re-enter: ";
                }
                double balance = currUser->DepositChequing(amount);

                event = "Your have successfully deposit " + to_string(amount) + " into your chequing account.";
                std::cout << event << endl;
                std::cout << "Your chequing account balance is " << to_string(balance) << std::endl;
                if (traceable == true) {
                        currUser->AddTrace(event);
                }
                system("pause");

        }
        else{
                double amount;
                std::cout << "Please enter the amount you are going to deposit: ";
                while(!(cin>>amount) || (amount < 0)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input; please re-enter: ";
                }
                double balance = currUser->DepositSaving(amount);
                event = "Your have successfully deposit " + to_string(amount) + " into your saving account.";
                std::cout << event << endl;
                std::cout << "Your saving account balance is " << to_string(balance) << std::endl;
                if (traceable == true) {
                        currUser->AddTrace(event);
                }
                system("pause");

        }
        system("clear");
        DisplayATMMenu();
}

void System::PrintTrace(){

        system("clear");
        DisplayATMMenu();
}

void System::LogoutATMServer(){
        currUser->~Client();
        Welcome();
}


/*****************************************/
void System::ManagerServer(){
        cout << "Welcome to the Manager server.\n" << endl;
        if (ManagerVerify() == true) {

        }
}

void System::LogoutManagerServer(){
        currOperator->~Manager();
        Welcome();
}
//-----------private method-----------------------------------------
//
void System::LoadClientData(int ID){
        Client *c = new Client();
        ifstream inFile;
        std::string fileName = "src/Client" + to_string(ID) + ".dat";
        inFile.open(fileName,ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! ;\n";
        }
        while(inFile.read((char *) c, sizeof(Client))) {
                if (c->GetID() == ID) {
                        currUser = c;
                }
        }
        inFile.close();
}

void System::WriteClientData(){
        ofstream outFile;
        std::string fileName = "src/Client" + to_string(currUser->GetID()) + ".dat";
        outFile.open(fileName,ios::binary|ios::app);
        outFile.write((char *) &currUser, sizeof(currUser));
        outFile.close();
}


void System::LoadManagerData(int ID){
        Manager *m = new Manager();
        ifstream inFile;
        std::string fileName = "src/Manager" + to_string(ID) + ".dat";
        inFile.open(fileName,ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! \n";
        }
        while(inFile.read((char *) m, sizeof(Manager))) {
                if (m->GetID() == ID) {
                        currOperator = m;
                }
        }
        inFile.close();
}

void System::WriteManagerData(){
        ofstream outFile;
        std::string fileName = "src/Manager" + to_string(currOperator->GetID()) + ".dat";
        outFile.open(fileName,ios::binary|ios::app);
        outFile.write((char *) &currOperator, sizeof(Manager));
        outFile.close();
}

//------------------------------------------------------

bool System::GetTraceable(){
        return traceable;
}

void System::SetTraceable( bool value){
        if( currOperator->GetMantaince() == true) {
                traceable = value;
        }
}

//------------------------------------------------------

bool System::ClientVerify(){
        int id;
        while((cout << "Please enter your id : ") && !(cin>>id)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input; please re-enter.\n";
        }
        LoadClientData(id);
        if (currUser == NULL) {
                cout << "The id you enter doesn't exist." << endl;
                return false;
        }
        else{
                string name;
                while ((cout << "Please enter your name : ") && !(cin>>name)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input; please re-enter.\n";
                }
                if (currUser->GetName() != name) {
                        cout << "Your ID and account name doesn,t match.\n";
                        currUser->~Client();
                        return false;
                }
                else{
                        return true;
                }
        }
}

bool System::ManagerVerify(){
        int id;
        while((cout << "Please enter your id : ") && !(cin>>id)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input; please re-enter.\n";
        }
        LoadManagerData(id);
        if (currOperator == NULL) {
                cout << "The id you enter doesn't exist." << endl;
                return false;
        }
        else{
                string name;
                while ((cout << "Please enter your name : ") && !(cin>>name)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input; please re-enter.\n";
                }
                if (currOperator->GetName() != name) {
                        cout << "Your ID and account name doesn,t match.\n";
                        currOperator->~Manager();
                        return NULL;
                }
                else{
                        return true;
                }
        }
}


void System::SetSuperUser(){
        Manager m(0, true);
        m.SetName("superuser");
        currOperator = &m;
        WriteManagerData();
}




//
// void Client::Withdraw(){
//         std::cout << "Please choose the acount you want to withdraw from < 1.saving, 2.chequing, others: cancel >:" << std::endl;
//         std::cin >> accType;
//         if (accType == 1) {
//                 if (chequing.first == false) {
//                         std::cout << "Because you do not have a chequing account, you cannot draw any money from it." << std::endl;
//                 }
//                 else{
//                         std::cout << "Please enter the amount withdraw:" << std::endl;
//                         std::cin >> amount;
//                         if (chequing.second < amount) {
//                                 std::cout << "Sorry, you cannot draw this amount dur to a incifficent chequing balance. " << std::endl;
//                         }
//                         else{
//                                 chequing.second -= amount;
//                                 std::cout << "You have successfully withdraw " << amount << " from your chequing account." << std::endl;
//                         }
//                 }
//         }
//         else if (accType == 2) {
//                 if (saving.first == false) {
//                         std::cout << "Because you do not have a saving account, you cannot draw any money from it." << std::endl;
//                 }
//                 else{
//                         std::cout << "Please enter the amount withdraw:" << std::endl;
//                         std::cin >> amount;
//                         if (saving.second < amount) {
//                                 std::cout << "Sorry, you cannot draw this amount dur to a incifficent saving balance. " << std::endl;
//                         }
//                         else{
//                                 saving.second -= amount;
//                                 std::cout << "You have successfully withdraw " << amount << " from your saving account." << std::endl;
//                         }
//                 }
//         }
//         else{}
// }
//
//
//
// //1. saving; 2.chequing
// void Client::Save(){
//         std::cout << "Please choose the acount you want to save to < 1.saving, 2.chequing, 3.cancel >:" << std::endl;
//         std::cin >> accType;
//         if (accType == 1) {
//                 if (chequing.first == false) {
//                         std::cout << "Because you do not have a chequing account, you cannot draw any money from it." << std::endl;
//                 }
//                 else{
//                         std::cout << "Please enter the amount withdraw:" << std::endl;
//                         std::cin >> amount;
//                         chequing.second += amount;
//                         std::cout << "You have successfully withdraw " << amount << " from your chequing account." << std::endl;
//                 }
//         }
//         else if (accType == 2) {
//                 if (saving.first == false) {
//                         std::cout << "Because you do not have a saving account, you cannot draw any money from it." << std::endl;
//                 }
//                 else{
//                         std::cout << "Please enter the amount withdraw:" << std::endl;
//                         std::cin >> amount;
//                         saving.second += amount;
//                         std::cout << "You have successfully withdraw " << amount << " from your saving account." << std::endl;
//                 }
//         }
//         else{}
// }
