#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef Manager_H
#define Manager_H

class Manager {

        int id;
        std::string name;
        bool mantaince_right;

public:

        Manager()=default;
        Manager(int ID, bool mantain = false);
        int GetID() const;
        std::string GetName();
        void SetName(std::string new_name);
        bool GetMantaince ();
        void SetMantaince (Manager *man_id, bool right);
};

#endif
