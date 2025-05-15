#pragma once
#include <vector>

class BookManager;
class UserManager;
class User;

using namespace std;

class FileManager
{
public:
	FileManager();
	void saveBookManagerToFile(BookManager* bookManager);
	void saveUserManagerToFile(UserManager* userManager);
	BookManager* readBookFile();
	UserManager* readUserFile();
	void saveUserTransactionManagerToFile(const vector<User*>& transaction);
	void readUserTransactionFile(vector<User*>& transaction);
};

