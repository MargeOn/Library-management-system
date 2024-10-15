#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stdexcept>
#include"Book.h"
#include"ValidData.h"

using namespace std;

class BookSystem
{
public:
	// Hàm khởi tạo hệ thống quản lí User
	BookSystem();
	// Hàm hủy hệ thống quản lí User
	~BookSystem();
	// Phương thức lấy vị trí index của một phần tử trong mảng
	Book getBook(int pos);
	// Phương thức lấy kích thước sách được lưu trữ trong danh sách quản lí sách
	int size();
	// Phương thức cộng thêm 1 quyển sách của đầu sách ở vị trí pos được lưu trong mảng NumBooks
	void addNum(int pos);
	// Phương thức trừ đi 1 quyển sách của đầu sách ở vị trí pos được lưu trong mảng NumBooks
	void lessNum(int pos);
	// Phương thức lấy số lượng của mỗi đầu sách được lưu trong mảng NumBooks
	int sizeNum(int pos);
	// Sắp xếp danh sách quản lí sách
	void sortListbook(Type type);
	// Hàm chuyển chuỗi chữ hoa sang chữ thường
	string lowerString(string data);
	// Trả về vị trí index khi tìm kiếm nhị phân theo tác giả, tên sách
	int BinSearch(Type type, string str);
	// Hàm ghi và đọc dữ liệu từ file "Booksetting.txt" lên
	void writeBookFile();
	void readBookFile();
private:
	// Hệ thống quản lí sách
	vector<Book> ListBooks;
	int NumBooks[17];
};

