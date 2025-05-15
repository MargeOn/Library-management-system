#pragma once
#include"ValidData.h"

class UserManager;
class BookManager;
class FileManager;

class User;

class Library
{
public:
	Library();
	void makeTransaction(User* people);
	void borrowedBook();
	void returnBook();
	void saveBookToFile();
	void saveUserToFile();
	void saveTransactionListToFile();
	void showTransactionList();
	BookManager* getBookManager();
	UserManager* getUserManager();
private:
	UserManager* userManager;
	BookManager* bookManager;
	FileManager* fileManager;
	string daySystem;
};

