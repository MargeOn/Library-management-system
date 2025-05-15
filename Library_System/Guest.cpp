#include <iostream>
#include <iomanip>
#include "Guest.h"

Guest::Guest() : currentOccupation("") {

}
Guest::~Guest() {
	//cout << "Ham huy Guest" << endl;
}
void Guest::inputInfo() {
	User::inputInfo();
	string temp;
	cout << "Nhap nganh nghe cua nguoi dung khach: ";
	getline(cin, temp);
	this->currentOccupation = temp;
}
void Guest::outputInfo() {
	User::outputInfo();
	cout << setw(25) << this->currentOccupation << endl;
}
string Guest::getCurrentOccupation() {
	return currentOccupation;
}
void Guest::setCurrentOccupation(string currentOccupation) {
	this->currentOccupation = currentOccupation;
}