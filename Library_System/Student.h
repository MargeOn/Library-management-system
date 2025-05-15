#pragma once
#include "User.h"
class Student :
    public User
{
public:
    Student();
    ~Student();
    void inputInfo();
    void outputInfo();
    string getMajor();
    void setMajor(string major);
private:
    string major;
};

