#include "client.h"

Client::Client(int ID){
    id = ID;
}

int Client::GetID() const{
    return id;
}

std::string Client::GetName(){
        return name;
}

void Client::SetName(std::string new_name){
        name = new_name;
}

std::pair<bool, double> Client::GetChequing(){
        return chequing;
}

void Client::InitalizeChequing(double amount){
        chequing.first = true;
        chequing.second = amount;
}

double Client::GetChequingBalance(){
        if(saving.first == false) {
                return -1.0;
        }
        else{
                return saving.second;
        }
}

double Client::WithdrawChequing(double amount){
        if (chequing.first == false) {
                return -1.0;
        }
        else{
                if (chequing.second < amount)
                        return -2.0;
                else
                        chequing.second -= amount;
                return chequing.second;
        }
}

double Client::DepositChequing(double amount){
        if (chequing.first == false) {
                return -1.0;
        }
        else{
                chequing.second += amount;
                return chequing.second;
        }
}

std::pair<bool, double> Client::GetSaving(){
        return saving;
}

void Client::InitalizeSaving(double amount){
        saving.first = true;
        saving.second = amount;
}

double Client::GetSavingBalance(){
        if(saving.first == false) {
                return -1.0;
        }
        else{
                return saving.second;
        }
}

double Client::WithdrawSaving(double amount){
        if (saving.first == false) {
                return -1.0;
        }
        else{
                if (saving.second < amount)
                        return -2.0;
                else
                        saving.second -= amount;
                return saving.second;
        }
}

double Client::DepositSaving(double amount){
        if (saving.first == false) {
                return -1.0;
        }
        else{
                saving.second += amount;
                return saving.second;
        }
}

std::vector<std::pair<std::string,std::string> > Client::GetTrace(){
    return traceList;
}

void Client::AddTrace(std::string event){
    time_t now = time(0);
    string opTime = ctime(&now);
    std::pair<std::string,std::string> r;
    r.first = opTime;
    r.second = event;
    traceList.push_back(r);
}
