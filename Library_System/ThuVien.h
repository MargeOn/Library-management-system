#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<cctype> 
#include"UserSystem.h"
#include"BookSystem.h"
#include"Ngay.h"

using namespace std;

class ThuVien
{
public:
	// Hàm khởi tạo đối tượng Book
	ThuVien();
	// Hàm hủy đối tượng Book
	~ThuVien();
	Ngay& getNgay();
	UserSystem& getUserSystem();
	BookSystem& getBookSystem();
	// Hàm nhập ngày tháng hiện tại trong thư viện 
	void InputDayLib();
	// Hàm kiểm tra số ngày mượn của sách hiện tại có vượt quá 30 ngày hay không
	bool checkOverDay(const string& str);
	// Hàm kiểm tra số ngày mượn của sách hiện tại có vượt quá 30 ngày hay không
	int calculateDay(const string&);
	// Hàm hiển thị các sách mượn chưa trả quá 30 ngày
	void reportOverdueBooks();
	void writeNgayFile();
	void readNgayFile();
private:
	UserSystem Usersystem;
	BookSystem Booksystem;
	Ngay presentDay;
};