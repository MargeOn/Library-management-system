#include"User.h"

// Hàm khởi tạo đối tượng Book
User::User() {
}
// Hàm hủy đối tượng Book
User::~User() {

}
// Phương thức lấy các biến thành viên của đối tượng User của thư viện
int User::get_ID() const{
	return id;
}
string User::get_Name() const{
	return name;
}
string User::get_Email() const{
	return email;
}

int User::get_PhoneNumber() const{
	return phoneNumber;
}
// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng User của trong thư viện
void User::set_ID(int id) {
	this->id = id;
}
void User::set_Name(string name) {
	this->name = name;
}
void User::set_Email(string email) {
	this->email = email;
}
void User::set_PhoneNumber(int phoneNumber) {
	this->phoneNumber = phoneNumber;
}

// Xuất thông tin sách mà người dùng đang mượn
void User::XuatThongtinSach() {
	cout << setw(40) << "Name Book"
		<< setw(10) << "ID Book"
		<< setw(30) << "Author"
		<< setw(20) << "Genre"
		<< setw(10) << "Year" << endl;
	for (int i = 0; i < Borrowed_books.size(); i++) {
		cout << setw(40) << Borrowed_books[i].get_Name()
			<< setw(10) << Borrowed_books[i].get_ID()
			<< setw(30) << Borrowed_books[i].get_Author()
			<< setw(20) << Borrowed_books[i].get_Genre()
			<< setw(10) << Borrowed_books[i].get_Year() << endl;
	}
}
// Định nghĩa phương thức cập nhật thông tin danh sách các sách mà người dùng đã mượn
void User::Insert_Book(Book data) {
	Borrowed_books.push_back(data);
	sortBorrowedbook();
}
// Hàm trả về vị trí index của một sách mà người dùng mượn
Book User::getBorrowedBook(int pos) const{
	return Borrowed_books[pos];
}
// Hàm xóa các người dùng đã không còn mượn sách 
void User::eraseBook(int index) {
	Borrowed_books.erase(Borrowed_books.begin() + index);
}
// Hàm trả về số lượng sách mà người dùng đã mượn
int User::sizeBorrowedBook() const {
	return Borrowed_books.size();
}
// Hàm sắp xếp sách mượn theo ID sách
void User::sortBorrowedbook() {
	for (int i = 0; i < Borrowed_books.size(); ++i) {
		bool swapped = false;
		for (int j = 0; j < Borrowed_books.size() - i - 1; ++j) {
			if (Borrowed_books[j].get_ID() > Borrowed_books[j + 1].get_ID()) {
				swap(Borrowed_books[j], Borrowed_books[j + 1]);
				swapped = true;
			}
		}
		// Nếu không có sự hoán đổi nào xảy ra trong một vòng lặp, mảng đã được sắp xếp
		if (!swapped) {
			break;
		}
	}
}
