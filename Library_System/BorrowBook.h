#pragma once
#include <string>
#include "Book.h"

using namespace std;

class BorrowBook
{
public:
	BorrowBook();
	void setBook(const Book& book);
	void setBorrowDay(const string& day);
	Book& getBook();
	string getBorrowDay();
private:
	Book borrowBook;
	string borrowDay;
};

