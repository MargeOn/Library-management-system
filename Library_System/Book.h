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
	string get_Name();
	string get_Author();
	string get_Genre();
	int get_Year();
	bool get_isAvailable();
	string get_Day();
	// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng User của trong thư viện
	void set_ID(int id);
	void set_Name(string name);
	void set_Author(string author);
	void set_Genre(string genre);
	void set_Year(int year);
	void set_isAvailable(bool isAvailable);
	void set_Day(string day);
private:
	int id;
	string name;
	string author;
	string genre;
	// Năm xuất bản sách
	int year;
	bool isAvailable;
	// Ngày tháng mà sách được cho mượn
	string day;
};