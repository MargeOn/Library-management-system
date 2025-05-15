#include "BookManager.h"
#include "Book.h"

BookManager::BookManager() {

}

void BookManager::addBook(const Book& book) {
	ListBook.push_back(book);
}

void BookManager::removeBook(const int& index, const int& count) {
	int quantity = ListBook[index].get_Quantity();
	ListBook[index].set_Quantity(quantity - count);
}

void BookManager::showBooks() {
	cout << setw(5) << "No" << setw(10) << "ID Book"
		<< setw(35) << "Title"
		<< setw(30) << "Author"
		<< setw(20) << "Caterogy"
		<< setw(30) << "Year of Publication"
		<< setw(15) << "Quantity" << endl;
	for (int i = 0; i < ListBook.size(); i++) {
		cout << setw(5) << i + 1 << ". " << setw(10) << ListBook[i].get_ID()
			<< setw(35) << ListBook[i].get_Title()
			<< setw(30) << ListBook[i].get_Author()
			<< setw(20) << ListBook[i].get_CategoryBook()
			<< setw(30) << ListBook[i].get_Year()
			<< setw(15) << ListBook[i].get_Quantity() << endl;
	}
}
void BookManager::showMostBorrowedBooks() {
	if (indexList.size() > 0) {
		cout << setw(5) << "No" << setw(10) << "ID Book"
			<< setw(35) << "Title"
			<< setw(30) << "Author"
			<< setw(20) << "Caterogy"
			<< setw(30) << "Year of Publication"
			<< setw(15) << "Quantity" << endl;
		for (int i = 0; i < indexList.size(); i++) {
			// Khi nhập tên tác giả là chữ cái hoa hoặc thường thì đều có thể tìm kiếm được 
			cout << setw(5) << i + 1 << setw(10) << ListBook[indexList[i]].get_ID()
				<< setw(35) << ListBook[indexList[i]].get_Title()
				<< setw(30) << ListBook[indexList[i]].get_Author()
				<< setw(20) << ListBook[indexList[i]].get_CategoryBook()
				<< setw(30) << ListBook[indexList[i]].get_Year()
				<< setw(15) << ListBook[indexList[i]].get_Quantity() << endl;
		}
	}
	else {
		cout << "Khong co quyen sach nao duoc muon" << endl;
	}
}

// Hàm chuyển chuỗi chữ hoa sang chữ thường
string lowerString(string data) {
	for (int i = 0; i < data.size(); i++) {
		data[i] = tolower(data[i]);
	}
	return data;
}

void BookManager::searchBooks(Type type) {
	string title, author, catergory;
	switch (type)
	{
	case BookManager::Title:
		cout << "Tim kiem sach theo ten sach: ";
		getline(cin, title);
		cout << setw(5) << "No" << setw(10) << "ID Book"
			<< setw(35) << "Title"
			<< setw(30) << "Author"
			<< setw(20) << "Caterogy"
			<< setw(30) << "Year of Publication"
			<< setw(15) << "Quantity" << endl;
		for (int i = 0; i < ListBook.size(); i++) {
			if (lowerString(title) == lowerString(ListBook[i].get_Title())) {
				// Khi nhập tên tác giả là chữ cái hoa hoặc thường thì đều có thể tìm kiếm được 
				cout << setw(5) << i + 1 << setw(10) << ListBook[i].get_ID()
					<< setw(35) << ListBook[i].get_Title()
					<< setw(30) << ListBook[i].get_Author()
					<< setw(20) << ListBook[i].get_CategoryBook()
					<< setw(30) << ListBook[i].get_Year()
					<< setw(15) << ListBook[i].get_Quantity() << endl;
			}
		}
		break;
	case BookManager::Author:
		cout << "Tim kiem sach theo ten tac gia: ";
		getline(cin, author);
		cout << setw(5) << "No" << setw(10) << "ID Book"
			<< setw(35) << "Title"
			<< setw(30) << "Author"
			<< setw(20) << "Caterogy"
			<< setw(30) << "Year of Publication"
			<< setw(15) << "Quantity" << endl;
		for (int i = 0; i < ListBook.size(); i++) {
			if (lowerString(author) == lowerString(ListBook[i].get_Author())) {
				// Khi nhập tên tác giả là chữ cái hoa hoặc thường thì đều có thể tìm kiếm được 
				cout << setw(5) << i + 1 << setw(10) << ListBook[i].get_ID()
					<< setw(35) << ListBook[i].get_Title()
					<< setw(30) << ListBook[i].get_Author()
					<< setw(20) << ListBook[i].get_CategoryBook()
					<< setw(30) << ListBook[i].get_Year()
					<< setw(15) << ListBook[i].get_Quantity() << endl;
			}
		}
		break;
	case BookManager::Catergory:
		cout << "Tim kiem sach theo ten the loai: ";
		getline(cin, catergory);
		cout << setw(5) << "No" << setw(10) << "ID Book"
			<< setw(35) << "Title"
			<< setw(30) << "Author"
			<< setw(20) << "Caterogy"
			<< setw(30) << "Year of Publication"
			<< setw(15) << "Quantity" << endl;
		for (int i = 0; i < ListBook.size(); i++) {
			if (lowerString(catergory) == lowerString(ListBook[i].get_CategoryBook())) {
				// Khi nhập tên tác giả là chữ cái hoa hoặc thường thì đều có thể tìm kiếm được 
				cout << setw(5) << i + 1 << setw(10) << ListBook[i].get_ID()
					<< setw(35) << ListBook[i].get_Title()
					<< setw(30) << ListBook[i].get_Author()
					<< setw(20) << ListBook[i].get_CategoryBook()
					<< setw(30) << ListBook[i].get_Year()
					<< setw(15) << ListBook[i].get_Quantity() << endl;
			}
		}
		break;
	default:
		break;
	}
}

int BookManager::findBook(const int& bookID) {
	for (int i = 0; i < ListBook.size(); i++) {
		if (ListBook[i].get_ID() == bookID) {
			return i;
		}
	}
	return -1;
}

void BookManager::setIndexMostBorrowedBooks(const int& index) {
	if (indexList.size() > 0) {
		if (ListBook[indexList[0]].get_Quantity() == ListBook[index].get_Quantity()) {
			indexList.push_back(index);
		}
		else if(ListBook[indexList[0]].get_Quantity() > ListBook[index].get_Quantity()){
			indexList.clear();
			indexList.push_back(index);
		}
		else {
			return;
		}
	}
	else {
		indexList.push_back(index);
	}
}

Book& BookManager::getBook(const int &index) {
	return ListBook[index];
}

vector<Book>& BookManager::getListBook() {
	return ListBook;
}

vector<int>& BookManager::getIndexList() {
	return indexList;
}