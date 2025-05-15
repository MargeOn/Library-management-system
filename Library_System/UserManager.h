#pragma once
#include <vector>
#include <set>

using namespace std;

class User;

class CompareByID {
public:
	bool operator()(const User* a, const User* b) const;
};

class UserManager
{
public:
	UserManager();
	void showUsersBorrowBook();
	void addUser(User* user);
	User* findUser(const int& userID);
	void removeUser(const int& userID);
	void displayUserBorrowOverDueBooks(const string& daySystem);
	bool updateUser(User* user);
	set<User*, CompareByID>& getListUser();
	vector<User*>& getTransactionList();
	/*void showUsersBorrowBook();
	void addUser(User* user);
	int findUser(const int& userID);
	User* getUser(const int& index);
	void removeUser(const int& userID);
	void displayUserBorrowOverDueBooks();
	bool updateUser(User* user, const int& index);
	vector<User*>& getListUser();*/
private:
	//vector<User*> ListUser;
	set<User*, CompareByID> ListUser;
	vector<User*> TransactionList;
};

