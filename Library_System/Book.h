#pragma once
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Book 
{
public:
	// Hàm khởi tạo đối tượng Book
	Book();
	// Hàm hủy đối tượng Book
	~Book();
	// Phương thức lấy các biến thành viên của đối tượng User của thư viện
	int get_ID();
	string get_Title();
	string get_Author();
	int get_Year();
	string get_CategoryBook();
	int get_Quantity();

	// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng User của trong thư viện
	void set_ID(int id);
	void set_Title(string title);
	void set_Author(string author);
	void set_Year(int year);
	void set_CategoryBook(string categoryBook);
	void set_Quantity(int quantity);
private:
	int bookID;
	string title;
	string author;
	int year;
	string categoryBook;
	int quantity;
};