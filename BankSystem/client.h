#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

#ifndef Client_H_
#define Client_H_

class Client
{
        int id;
        std::string name;
        std::pair <bool, double> saving;
        std::pair <bool, double> chequing;
        std::vector< std::pair<std::string,std::string> > traceList; //first string for time, and second for execution.

public:

        Client()=default;
        Client(int ID);

        int GetID() const;
        std::string GetName();
        void SetName(std::string new_name);

        std::pair<bool, double> GetChequing();
        void InitalizeChequing(double amount=0);
        double GetChequingBalance();
        double WithdrawChequing(double amount);
        double DepositChequing(double amount);

        std::pair<bool, double> GetSaving();
        void InitalizeSaving(double amount=0);
        double GetSavingBalance();
        double WithdrawSaving(double amount);
        double DepositSaving(double amount);

        std::vector<std::pair<std::string,std::string>> GetTrace();
        void AddTrace(std::string event);

};

#endif
