#include "BorrowBook.h"

BorrowBook::BorrowBook() {
	this->borrowDay = "";
}
void BorrowBook::setBook(const Book& book) {
	this->borrowBook = book;
}

void BorrowBook::setBorrowDay(const string& day) {
	this->borrowDay = day;
}

Book& BorrowBook::getBook() {
	return this->borrowBook;
}

string BorrowBook::getBorrowDay() {
	return this->borrowDay;
}
