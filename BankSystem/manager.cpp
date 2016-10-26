#include "manager.h"

Manager::Manager(int ID, bool mantain){
    id = ID;
    mantaince_right = mantain;
}

int Manager::GetID() const{
    return id;
}

std::string Manager::GetName(){
    return name;
}

void Manager::SetName(std::string new_name){
        name = new_name;
}

bool Manager::GetMantaince(){
    return mantaince_right;
}

void Manager::SetMantaince(Manager *man_id, bool right){
    if (man_id == NULL){
        return;
    }
    if (mantaince_right == true){
        man_id -> mantaince_right = right;
    }
}
