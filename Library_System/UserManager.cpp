#include <iostream>
#include <iomanip>
#include "UserManager.h"
#include "BorrowBook.h"
#include "Student.h"
#include "Teacher.h"
#include "Guest.h"
#include "User.h"
#include "CalculateOverDue.h"

bool CompareByID::operator()(const User* a, const User* b) const {
	if (a == nullptr || b == nullptr) return false;  
	return a->get_ID() < b->get_ID();  // So sánh dựa trên id
}

UserManager::UserManager() {
}
void UserManager::showUsersBorrowBook() {
	int i = 0;
	for (User* user : ListUser) {
		cout << setw(65) << "                                                                                                               " << endl;
		cout << setw(65) << "============================================================================================================================================" << endl;
		cout << setw(5) << "No";
		if (Student* stuPtr = dynamic_cast<Student*>(user)) {
			cout << setw(10) << "ID User"
				<< setw(20) << "User Name"
				<< setw(15) << "Birthday"
				<< setw(25) << "Email"
				<< setw(15) << "Field"
				<< setw(25) << "Major" << endl;
			cout << setw(5) << i + 1 << "."; ++i;
			stuPtr->outputInfo();
		}
		if (Teacher* teaPtr = dynamic_cast<Teacher*>(user)) {
			cout << setw(10) << "ID User"
				<< setw(20) << "User Name"
				<< setw(15) << "Birthday"
				<< setw(25) << "Email"
				<< setw(15) << "Field"
				<< setw(25) << "Department" << endl;
			cout << setw(5) << i + 1 << "."; ++i;
			teaPtr->outputInfo();
		}
		if (Guest* geuPtr = dynamic_cast<Guest*> (user)) {
			cout << setw(10) << "ID User"
				<< setw(20) << "User Name"
				<< setw(15) << "Birthday"
				<< setw(25) << "Email"
				<< setw(15) << "Field"
				<< setw(25) << "Current Occupation" << endl;
			cout << setw(5) << i + 1 << "."; ++i;
			geuPtr->outputInfo();
		}
		cout << setw(65) << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		user->showBorrowBooks();
	}
}
void UserManager::addUser(User* user) {
	ListUser.insert(user);
	TransactionList.push_back(user);
}
User* UserManager::findUser(const int& userID) {
	for (User* user : ListUser) {
		if (Student* stuPtr = dynamic_cast<Student*>(user)) {
			if (stuPtr->get_ID() == userID) {
				return stuPtr;
			}
		}
		else if (Teacher* teaPtr = dynamic_cast<Teacher*>(user)) {
			if (teaPtr->get_ID() == userID) {
				return teaPtr;
			}
		}
		else if (Guest* geuPtr = dynamic_cast<Guest*>(user)) {
			if (geuPtr->get_ID() == userID) {
				return geuPtr;
			}
		}
	}
	return nullptr;
}

void UserManager::removeUser(const int& userID) {
	User* temp = new User();
	temp->set_ID(userID);
	auto it = ListUser.find(temp);
	User* user = *it;
	ListUser.erase(user);
	delete user;
	delete temp;
}
void UserManager::displayUserBorrowOverDueBooks(const string& daySystem) {
	for (int i = 0; i < TransactionList.size(); i++) {
		for (int j = 0; j < TransactionList[i]->getSizeBorrow(); j++) {
			CalculateOverDue calculator;
			int days = calculator.calculateOverDueDay(daySystem, TransactionList[i]->getBorrowBook(j).getBorrowDay());
			if (days > 30) {
				cout << setw(65) << "                                                                                                               " << endl;
				cout << setw(65) << "============================================================================================================================================" << endl;
				cout << setw(5) << "No" 
					<< setw(10) << "ID User"
					<< setw(20) << "User Name"
					<< setw(15) << "Birthday"
					<< setw(25) << "Email"
					<< setw(15) << "Field";
				if (Student* stuPtr = dynamic_cast<Student*>(TransactionList[i])) {
					cout << setw(25) << "Major" << endl;
					cout << setw(5) << i + 1;
					stuPtr->outputInfo();
				}
				if (Teacher* teaPtr = dynamic_cast<Teacher*>(TransactionList[i])) {
					cout << setw(25) << "Department" << endl;
					cout << setw(5) << i + 1;
					teaPtr->outputInfo();
				}
				if (Guest* geuPtr = dynamic_cast<Guest*> (TransactionList[i])) {
					cout << setw(25) << "Current Occupation" << endl;
					cout << setw(5) << i + 1;
					geuPtr->outputInfo();
				}
				cout << setw(65) << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << setw(20) << "Borrow Day"
					<< setw(10) << "ID Book"
					<< setw(30) << "Title"
					<< setw(30) << "Author"
					<< setw(25) << "Catergory"
					<< setw(15) << "Publish Year"
					<< setw(10) << "Quantity"
					<< setw(10) << "Overdue Day" << endl;
				cout << setw(20) << TransactionList[i]->getBorrowBook(j).getBorrowDay()
					<< setw(10) << TransactionList[i]->getBorrowBook(j).getBook().get_ID()
					<< setw(30) << TransactionList[i]->getBorrowBook(j).getBook().get_Title()
					<< setw(30) << TransactionList[i]->getBorrowBook(j).getBook().get_Author()
					<< setw(25) << TransactionList[i]->getBorrowBook(j).getBook().get_CategoryBook()
					<< setw(15) << TransactionList[i]->getBorrowBook(j).getBook().get_Year()
					<< setw(10) << TransactionList[i]->getBorrowBook(j).getBook().get_Quantity()
					<< setw(10) << days << endl;
			}
		}
	}
}
bool UserManager::updateUser(User* user) {
	auto it = ListUser.find(user);
	User* temp = *it;
	if (Student* stuPtr = dynamic_cast<Student*>(user)) {
		if (Student* stuManager = dynamic_cast<Student*>(temp)) {
			stuManager->set_Name(stuPtr->get_Name());
			stuManager->set_BirthDay(stuPtr->get_BirthDay());
			stuManager->set_Email(stuPtr->get_Email());
			stuManager->setMajor(stuPtr->getMajor());
			return true;
		}
		else {
			return false;
		}
	}
	else if (Teacher* teaPtr = dynamic_cast<Teacher*>(user)) {
		if (Teacher* teaManager = dynamic_cast<Teacher*>(temp)) {
			teaManager->set_Name(teaPtr->get_Name());
			teaManager->set_BirthDay(teaPtr->get_BirthDay());
			teaManager->set_Email(teaPtr->get_Email());
			teaManager->setDepartment(teaPtr->getDepartment());
			return true;
		}
		else {
			return false;
		}
	}
	else if (Guest* guePtr = dynamic_cast<Guest*>(user)) {
		if (Guest* gueManager = dynamic_cast<Guest*>(temp)) {
			gueManager->set_Name(guePtr->get_Name());
			gueManager->set_BirthDay(guePtr->get_BirthDay());
			gueManager->set_Email(guePtr->get_Email());
			gueManager->setCurrentOccupation(guePtr->getCurrentOccupation());
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

set<User*, CompareByID>& UserManager::getListUser() {
	return ListUser;
}


vector<User*>& UserManager::getTransactionList() {
	return TransactionList;
}