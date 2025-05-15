#include <iostream>
#include <iomanip>
#include "User.h"
#include "BorrowBook.h"
#include "Book.h"


// Hàm khởi tạo đối tượng Book
User::User(): userID(0), name(""), email(""),birthDay("") {

}
// Hàm hủy đối tượng Book
User::~User() {
	//cout << "Ham huy User" << endl;
}

string User::getRole() {
	return this->role;
}

// Phương thức lấy các biến thành viên của đối tượng User của thư viện
int User::get_ID() const{
	return userID;
}
string User::get_Name() const{
	return name;
}
string User::get_Email() const{
	return email;
}

string User::get_BirthDay() const{
	return birthDay;
}
// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng User của trong thư viện
void User::setRole(string role) {
	this->role = role;
}

void User::set_ID(int id) {
	this->userID = id;
}
void User::set_Name(const string &name) {
	this->name = name;
}
void User::set_Email(const string& email) {
	this->email = email;
}

void User::set_BirthDay(const string& birthDay){
	this->birthDay = birthDay;
}

void User::inputInfo() {
	int id;
	cout << "Nhap id cua nguoi muon: ";
	cin >> id;
	this->userID = id;

	cin.ignore();
	string name;
	cout << "Nhap ten cua nguoi muon: ";
	getline(cin, name);
	this->name = name;

	string birthDay;
	cout << "Nhap ngay sinh cua nguoi muon: ";
	getline(cin, birthDay);
	this->birthDay = birthDay;

	string email;
	cout << "Nhap email cua nguoi muon: ";
	getline(cin, email);
	this->email = email;
}
void User::outputInfo() {
	cout << setw(10) << this->get_ID()
		<< setw(20) << this->get_Name()
		<< setw(15) << this->get_BirthDay()
		<< setw(25) << this->get_Email()
		<< setw(15) << this->getRole();
}

void User::showBorrowBooks() {
	cout << setw(20) << "Borrow Day"
		<< setw(10) << "ID Book"
		<< setw(30) << "Title"
		<< setw(30) << "Author"
		<< setw(25) << "Catergory"
		<< setw(15) << "Publish Year" 
		<< setw(10) << "Quantity" << endl;
	for (int i = 0; i < borrowBooks.size(); i++) {
		cout << setw(20) << borrowBooks[i].getBorrowDay()
			<< setw(10) << borrowBooks[i].getBook().get_ID()
			<< setw(30) << borrowBooks[i].getBook().get_Title()
			<< setw(30) << borrowBooks[i].getBook().get_Author()
			<< setw(25) << borrowBooks[i].getBook().get_CategoryBook()
			<< setw(15) << borrowBooks[i].getBook().get_Year()
			<< setw(10) << borrowBooks[i].getBook().get_Quantity() << endl;
	}
}
void User::showOverDueBooks() {

}
void User::addBorrowBook(const BorrowBook& borrowBook) {
	borrowBooks.push_back(borrowBook);
}
void User::removeBorrowBook(const int& index) {
	if (index >= 0 && index < borrowBooks.size()) {
		borrowBooks.erase(borrowBooks.begin() + index);
	}
}

int User::findBook(const int& bookID) {
	for (int i = 0; i < borrowBooks.size(); i++) {
		if (borrowBooks[i].getBook().get_ID() == bookID) {
			return i;
		}
	}
	return -1;
}

int User::getSizeBorrow() {
	return borrowBooks.size();
}
BorrowBook& User::getBorrowBook(const int& index) {
	return borrowBooks[index];
}
