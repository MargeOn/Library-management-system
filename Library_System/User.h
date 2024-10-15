#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Book.h"
#include"People.h"
#include"ValidData.h"

using namespace std;

class User : public People
{
public:
	// Hàm khởi tạo đối tượng Book
	User();
	// Hàm hủy đối tượng Book
	~User();
	// Phương thức lấy các biến thành viên của đối tượng User của thư viện
	int get_ID() const;
	string get_Name() const;
	string get_Email() const;
	int get_PhoneNumber() const;
	// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng User của trong thư viện
	void set_ID(int id);
	void set_Name(string name);
	void set_Email(string email);
	void set_PhoneNumber(int phoneNumber);
	// Hiển thị thông tin sách
	void XuatThongtinSach();
	// Hàm thêm một sách vào người dùng đã mượn sách
	void Insert_Book(Book data);
	// Hàm trả về một trong các sách mà người dùng đã mượn
	Book getBorrowedBook(int pos) const;
	// Hàm trả về ngày mượn sách của sách tương ứng mà người dùng mượn
	string getBorrowedDay(string day);
	// Hàm xóa sách khi người dùng trả sách
	void eraseBook(int index);
	// Hàm trả về số lượng sách mà người dùng đã mượn 
	int sizeBorrowedBook() const;
	// Hàm sắp xếp sách mượn theo ID sách
	void sortBorrowedbook();
private:
	vector<Book> Borrowed_books;
};