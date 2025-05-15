#include <iostream>
#include <iomanip>
#include "Student.h"

Student::Student(): major("") {

}
Student::~Student() {
	//cout << "Ham huy Student" << endl;
}
void Student::inputInfo() {
	User::inputInfo();
	string temp;
	cout << "Nhap nganh hoc cua sinh vien: ";
	getline(cin, temp);
	this->major = temp;
}
void Student::outputInfo() {
	User::outputInfo();
	cout << setw(25) << this->major << endl;
}
string Student::getMajor() {
	return major;
}
void Student::setMajor(string major) {
	this->major = major;
}