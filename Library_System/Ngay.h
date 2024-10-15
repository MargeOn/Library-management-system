#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"ValidData.h"

using namespace std;

class Ngay
{
public:
	// Hàm khởi tạo đối tượng Book
	Ngay();
	// Hàm lấy ngày tháng hiện tại của thư viện
	string getpresentDay();
	// Hàm gán ngày tháng hiện tại của thư viện
	void setpresentDay(string presentDay);
	// Hàm kiểm tra quá trình nhập ngày hiện tại có phải là quá khứ của ngày trước đó mà thư viện lưu ở file không
	bool isPastDay(const string& ngaythangnam);
	// Hàm kiểm tra nhập ngày hiện tại có đúng với ngày tháng năm thực tế hay không
	bool checkvalidDay(const string& ngaythangnam);
private:
	string day;
};