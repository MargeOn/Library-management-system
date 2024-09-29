#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<cctype> 
#include"User.h"
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
	// Hàm nhập ngày tháng hiện tại trong thư viện 
	void InputDayLib();
	// Hàm trả về một người dùng trong mảng quản lí người dùng
	User& getUser(int pos);
	// Hàm thêm một người dùng khi họ mượn sách
	void Insert_User(User data);
	// Hàm cập nhật ID của người dùng khi người dùng đã mượn sách từ trước và giờ lại mượn thêm sách khác
	void updateInfoUser(int index, User data);
	// Hàm để người dùng mượn sách
	void borrowedBook(int index, Book data);
	// Hàm người dùng trả sách 
	void returnBook(User& user, int id);
	// Hàm trả về index của người dùng khi tìm kiếm cuốn sách họ đang trả
	void eraseUser(int index);
	// Hàm hiển thị thông tin người dùng và sách mà họ mượn
	void show_listUser();
	// Hàm trả về index của ID người dùng khi mượn sách
	int check_UserID(User data);
	// Hàm trả về index của ID người dùng khi trả sách
	int check_UserID(int data);
	// Hàm trả về ID sách của mỗi người dùng liệu có trong danh sách người dùng mượn trong thư viện hay không
	int search_ListBookID(User user, int IDbook);
	// Hàm kiểm tra số ngày mượn của sách hiện tại có vượt quá 30 ngày hay không
	bool checkOverDay(const string& str);
	// Hàm kiểm tra số ngày mượn của sách hiện tại có vượt quá 30 ngày hay không
	int calculateDay(const string&);
	// Hàm hiển thị các sách mượn chưa trả quá 30 ngày
	void reportOverdueBooks();
	// Hàm sắp xếp ID người dùng
	void sortListUser();
	// Hàm ghi và đọc dữ liệu từ file "User.txt" lên
	void writeUserFile();
	void readUserFile();
private:
	vector<User> ListUser;
	Ngay presentDay;
};