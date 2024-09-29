#pragma once
#include<iostream>
#include<string>
#include<regex>
#include<sstream>
using namespace std;

// Hàm trả về số ngày theo tháng tương ứng
int returndaysPerMonth(int month);

// Định nghĩa kiểu dữ liệu mang các tên thông tin trong xe để kiểm tra các thông tin mà người dùng nhập vào có hợp lệ hay không?
enum Type {
	// Lựa chọn Menu các lựa chọn nhập xuất và tìm kiếm
	MenuSelect1,
	MenuBorrowed,
	MenuReturn,
	MenuSearch,
	MenuOut,
	// User
	Name,
	Email,
	Key,
	Phone, 
	// Sách
	BOOK,
	IDbook,
	Namebook,
	Author,
	Sgenre,
	Ngaythangnam
};
// Khai báo hàm kiểm tra nhập kí tự hợp lệ khi lựa chọn có tiếp tục nhập thêm xe hay không
bool isValidCharacter(string);
// Khai báo hàm tách chuỗi ở giữa kí tự đuợc chọn
const vector<string> explode(const string&, const char&);
// Khai báo hàm kiểm tra nhập hợp lệ của các lựa chọn trong các MenuIO, MenuIn, MenuOut và thông 
// tin chung và chức năng của xe
bool Regrex(Type, string);

