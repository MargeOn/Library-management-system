#include"Book.h"

// Hàm khởi tạo đối tượng Book
Book::Book(){
}
// Hàm hủy đối tượng Book
Book::~Book() {

}
// Định nghĩa phương thức lấy các biến thành viên của đối tượng Book
int Book::get_ID() {
	return this->bookID;
}
string Book::get_Title() {
	return this->title;
}
string Book::get_Author() {
	return this->author;
}
int Book::get_Year() {
	return this->year;
}
string Book::get_CategoryBook() {
	return this->categoryBook;
}
int Book::get_Quantity() {
	return this->quantity;
}
// Định nghĩa phương thức cài đặt giá trị cho các biến thành viên của đối tượng Book
void Book::set_ID(int id) {
	this->bookID = id;
}
void Book::set_Title(string title) {
	this->title = title;
}
void Book::set_Author(string author) {
	this->author = author;
}
void Book::set_Year(int year) {
	this->year = year;
}
void Book::set_CategoryBook(string categoryBook) {
	this->categoryBook = categoryBook;
}
void Book::set_Quantity(int quantity) {
	this->quantity = quantity;
}