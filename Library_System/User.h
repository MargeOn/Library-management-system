#pragma once
#include<string>
#include <vector>

using namespace std;

class BorrowBook;

class User 
{
public:
	// Hàm khởi tạo đối tượng Book
	User();
	// Hàm hủy đối tượng Book
	virtual ~User();
	// Phương thức lấy các biến thành viên của đối tượng User của thư viện
	string getRole();
	int get_ID() const;
	string get_Name() const;
	string get_Email() const;
	string get_BirthDay() const;
	// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng User của trong thư viện
	void setRole(string role);
	void set_ID(int id);
	void set_Name(const string& name);
	void set_Email(const string& email);
	void set_BirthDay(const string& birthDay);

	virtual void inputInfo();
	virtual void outputInfo();

	void showBorrowBooks();
	void showOverDueBooks();
	void addBorrowBook(const BorrowBook& borrowBook);
	void removeBorrowBook(const int& index);
	int findBook(const int& bookID);
	int getSizeBorrow();
	BorrowBook& getBorrowBook(const int& index);
private:
	string role;
	int userID;
	string name;
	string birthDay;
	string email;
	vector<BorrowBook> borrowBooks;
};