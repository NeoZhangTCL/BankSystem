#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

#include "client.h"
#include "manager.h"

#ifndef System_H_
#define System_H_

class System {

bool traceable;
Manager *currOperator = NULL;
Client *currUser = NULL;

private:

void LoadClientData(int ID);
void WriteClientData();
void LoadManagerData(int ID);
void WriteManagerData();

bool GetTraceable();
void SetTraceable(bool value);

bool ClientVerify();
bool ManagerVerify();

void SetSuperUser();

public:

void MainFrame();
//void Transfer();

/*****************************************/
void ATMServer();
/*****************************************/
void DisplayATMMenu();
void CheckBalance();
void DepositMoney();
void WithdrawMoney();
void TransferMoney();
void PrintTrace();
void LogoutATMServer();

/*****************************************/
void ManagerServer();
/*****************************************/
void DisplayManagerMenu();
void SetupAccount();
void DeleteAccount();
void OpenAccount();
void CloseAccount();
void ChangeTrackable();
void LogoutManagerServer();




};

#endif
