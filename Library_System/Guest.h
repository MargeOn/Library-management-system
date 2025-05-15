#pragma once
#include "User.h"
class Guest :
    public User
{
public:
    Guest();
    ~Guest();
    void inputInfo();
    void outputInfo();
    string getCurrentOccupation();
    void setCurrentOccupation(string currentOccupation);
private:
    string currentOccupation;
};

