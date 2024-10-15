#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<cctype> 
#include<fstream>
#include"User.h"

using namespace std;

class UserSystem
{
public:
	// Hàm trả về một người dùng trong mảng quản lí người dùng
	User& getUser(int pos);
	// Hàm thêm một người dùng khi họ mượn sách
	void Insert_User(User data);
	// Hàm cập nhật ID của người dùng khi người dùng đã mượn sách từ trước và giờ lại mượn thêm sách khác
	void updateInfoUser(int index, const User &data);
	// Hàm để người dùng mượn sách
	void borrowedBook(int index, Book data);
	// Hàm người dùng trả sách 
	void returnBook(User& user, int id);
	// Hàm trả về index của người dùng khi tìm kiếm cuốn sách họ đang trả
	void eraseUser(int index);
	// Hàm hiển thị thông tin người dùng và sách mà họ mượn
	void show_listUser();
	// Hàm trả về index của ID người dùng khi mượn sách
	int check_UserID(const User& data);
	// Hàm trả về index của ID người dùng khi trả sách
	int check_UserID(int data);
	// Hàm trả về số lượng người dùng mượn sách
	int getSizeUser();
	// Hàm trả về ID sách của mỗi người dùng liệu có trong danh sách người dùng mượn trong thư viện hay không
	int search_ListBookID(const User& user, int IDbook);
	// Hàm sắp xếp ID người dùng
	void sortListUser();
	// Hàm ghi và đọc dữ liệu từ file "User.txt" lên
	void writeUserFile();
	void readUserFile();
private:
	vector<User> ListUser;
};