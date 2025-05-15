#include <iostream>
#include <iomanip>
#include "Teacher.h"

Teacher::Teacher(): department("") {

}
Teacher::~Teacher() {
	//cout << "Ham huy Teacher" << endl;
}
void Teacher::inputInfo(){
	User::inputInfo();
	string temp;
	cout << "Nhap phong ban cua giao vien: ";
	getline(cin, temp);
	this->department = temp;
}
void Teacher::outputInfo() {
	User::outputInfo();
	cout << setw(25) << this->department << endl;
}
string Teacher::getDepartment() {
	return department;
}
void Teacher::setDepartment(string department) {
	this->department = department;
}