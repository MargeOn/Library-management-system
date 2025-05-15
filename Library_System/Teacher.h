#pragma once
#include "User.h"
class Teacher :
    public User
{
public:
    Teacher();
    ~Teacher();
    void inputInfo();
    void outputInfo();
    string getDepartment();
    void setDepartment(string department);
private:
    string department;
};

