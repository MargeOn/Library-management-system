#include"Book.h"

// Hàm khởi tạo đối tượng Book
Book::Book() {
	id = 0;
	name = "";
	author = "";
	genre = "";
	year = 0;
	isAvailable = 1;
	day = "";
}
// Hàm hủy đối tượng Book
Book::~Book() {

}
// Định nghĩa phương thức lấy các biến thành viên của đối tượng Book
int Book::get_ID() {
	return this->id;
}
string Book::get_Name() {
	return this->name;
}
string Book::get_Author() {
	return this->author;
}
string Book::get_Genre() {
	return this->genre;
}
int Book::get_Year() {
	return this->year;
}
bool Book::get_isAvailable() {
	return this->isAvailable;
}
string Book::get_Day() {
	return this->day;
}
// Định nghĩa phương thức cài đặt giá trị cho các biến thành viên của đối tượng Book
void Book::set_ID(int id) {
	this->id = id;
}
void Book::set_Name(string name) {
	this->name = name;
}
void Book::set_Author(string author) {
	this->author = author;
}
void Book::set_Genre(string genre) {
	this->genre = genre;
}
void Book::set_Year(int year) {
	this->year = year;
}
void Book::set_isAvailable(bool isAvailable) {
	this->isAvailable = isAvailable;
}
void Book::set_Day(string day) {
	this->day = day;
}