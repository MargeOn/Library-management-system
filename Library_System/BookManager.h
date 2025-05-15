#pragma once
#include <vector>
#include <string>

using namespace std;

class Book;

class BookManager
{
public:
	BookManager();
	enum Type {
		Title,
		Author,
		Catergory
	};
	void addBook(const Book& book);
	void removeBook(const int& index, const int& count);
	void showBooks();
	void showMostBorrowedBooks();
	void searchBooks(Type type);
	int findBook(const int& bookID);
	void setIndexMostBorrowedBooks(const int& index);
	Book& getBook(const int& index);
	vector<Book>& getListBook();
	vector<int>& getIndexList();
private:
	vector<Book> ListBook;
	vector<int> indexList;
};

