#include"Library.h"
#include"BookManager.h"
#include"UserManager.h"
#include"FileManager.h"

using namespace std;

Library lib;

// Khai báo hàm hiển thị các lựa chọn tìm kiếm, nhập xuất thông tin trong hệ thống quản lí thư viện. 
void Menu();
void Menu_outPut();
// 1. Khai báo hàm hiển thị chức năng để người dùng mượn sách và cập nhật các thông tin sách đã mượn và người dùng là ai.
void Menu_borrowedBook();
void Menu_returnBook();
void Menu_search();
void Menu_displayMostBorrowBook();

int main() {
	Menu();
	return 0;
}

// Màn hình hiển thị các lựa chọn tìm kiếm, nhập xuất thông tin trong hệ thống quản lí thư viện
void Menu()
{
	while (true)
	{
		// Biến input để kiểm tra regrex
		string input;
		// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
		int select;
		// Màn hình lựa chọn chức năng nhập xuất thông tin cho xe.
		do
		{
			system("cls");
			cout << "===========================================" << endl;
			cout << "=         HE THONG QUAN LI THU VIEN       =" << endl;
			cout << "===========================================";
			cout << "\n1. Muon sach";
			cout << "\n2. Tra sach";
			cout << "\n3. Tim kiem sach trong thu vien";
			cout << "\n4. Liet ke cac nguoi dung da muon sach trong thu vien";
			cout << "\n5. Cac cuon sach dang duoc muon nhieu nhat";
			cout << "\n6. Cac cuon sach da muon nhung chua tra qua 30 ngay";
			cout << "\n7. Exit";
			cout << "\nYour select: ";
			getline(cin, input);
			// Kiểm tra điều kiện nhập Menu nhập xuất
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(MenuSelect1, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 5" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(MenuSelect1, input));
		switch (select)
		{
		case 1:
		{
			// Màn hình hiển thị chức năng để người dùng mượn sách và cập nhật các thông tin sách đã mượn và người dùng là ai.
			Menu_borrowedBook();
			break;
		}
		case 2:
		{
			// Màn hình hiển thị chức năng để người dùng trả sách và cập nhật các thông tin sách đã mượn và người dùng là ai.
			Menu_returnBook();
			break;
		}
		case 3:
		{
			// Màn hình hiển thị chức năng tìm kiếm sách theo các yêu cầu: tên sách, tác giả và thể loại.
			Menu_search();
			break;
		}
		case 4:
		{
			// Màn hình hiển thị chức năng xuất thông tin người dùng và sách được lưu trữ trong hệ thống quản lí thư viện.
			Menu_outPut();
			break;
		}
		case 5:
		{
			// Màn hình hiển thị các sách đang được mượn nhieu nhat 
			Menu_displayMostBorrowBook();
			break;
		}
		case 6:
		{
			// Màn hình hiển thị chức năng xuất thông tin người dùng và sách được lưu trữ trong hệ thống quản lí thư viện.
			lib.showTransactionList();
			system("pause");
			break;
		}
		case 7:
		{
			lib.saveBookToFile();
			lib.saveUserToFile();
			lib.saveTransactionListToFile();
			cout << "\nHe thong da tat. Hen gap lai. " << endl;
			system("pause");
			exit(0);
		}
		}
	}
}
void Menu_outPut() {
	while (true) {
		// Biến input để kiểm tra regrex
		string input;
		// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
		int select;
		// Biến break dùng để thoát khỏi Menu_outPut để tới Menu
		int Brk = 0;
		// Màn hình lựa chọn chức năng xuất thông tin.
		do
		{
			system("cls");
			cout << "-------- LIET KE THONG TIN THEO YEU CAU --------";
			cout << "\n1. Liet ke tat ca cac sach co trong thu vien";
			cout << "\n2. Liet ke tat ca cac nguoi dung va sach ma ho muon";
			cout << "\n3. Exit";
			cout << "\nYour select: ";
			getline(cin, input);
			// Kiểm tra điều kiện Menu xuất 
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(MenuOut, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 3" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(MenuOut, input));
		switch (select)
		{
		case 1:
		{
			lib.getBookManager()->showBooks();
			system("pause");
			break;
		}
		case 2:
		{
			lib.getUserManager()->showUsersBorrowBook();
			system("pause");
			break;
		}
		case 3:
		{
			Brk = 3;
			break;
		}
		}
		if (Brk == 3) {
			break;
		}
	}
}

// 1. Màn hình hàm hiển thị chức năng để người dùng mượn sách và cập nhật các thông tin sách đã mượn và người dùng là ai.
void Menu_borrowedBook()
{
	// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
	int select;
	// Biến input để kiểm tra regrex
	string input = "";
	// Biến break dùng để thoát khỏi Menu_borrowedBook để tới Menu
	int Brk = 0;
	// Màn hình lựa chọn chức năng nhập thông tin cho xe.
	do
	{
		system("cls");
		cout << "Ban muon nhap thong tin nguoi dung de muon sach trong thu vien?:";
		cout << "\n1.Yes";
		cout << "\n2.No";
		cout << "\nYour select: ";
		getline(cin, input);
		// Kiểm tra nhập thông tin có hợp lệ hay không
		if (!Regrex(MenuBorrowed, input))
		{
			cout << "Vui long nhap lua chon phai la mot so trong 2 lua chon tren" << endl;
			system("pause");
		}
		// Nếu trả về true thì đổi giá trị input thành số nguyên 
		else {
			select = stoi(input);
		}
		// Nếu trả về false thì thông báo và yêu cầu nhập lại
	} while (!Regrex(MenuBorrowed, input));
	switch (select)
	{
	case 1:
	{
		lib.borrowedBook();
		break;
	}
	case 2:
	{
		break;
	}
	}
}

// 2. Màn hình hiển thị chức năng để người dùng trả sách và cập nhật các thông tin sách đã mượn và người dùng là ai.
void Menu_returnBook(){
	// Biến input để kiểm tra regrex
	string input;
	// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
	int select;
	// Biến break dùng để thoát khỏi Menu3 để tới Menu
	int Brk = 0;
	// Màn hình lựa chọn chức năng xuất thông tin cho xe.
	do
	{
		system("cls");
		cout << "Ban muon nhap thong tin nguoi dung de tra sach cho thu vien?:";
		cout << "\n1.Yes";
		cout << "\n2.No";
		cout << "\nYour select: ";
		getline(cin, input);
		// Kiểm tra điều kiện nhập Menu xuất 
		// Nếu trả về false thì thông báo nhập lại
		if (!Regrex(MenuReturn, input))
		{
			cout << "Vui long nhap lua chon phai la mot so trong 2 lua chon tren" << endl;
			system("pause");
		}
		// Nếu trả về true thì đổi giá trị input thành số nguyên 
		else {
			select = stoi(input);
		}
		// Nếu trả về false thì thông báo và yêu cầu nhập lại
	} while (!Regrex(MenuReturn, input));
	switch (select)
	{
	case 1:
	{
		lib.returnBook();
		break;
	}
	case 2:
	{
		break;
	}
	}
}

// 3. Khai báo hàm hiển thị chức năng tìm kiếm sách theo các yêu cầu: tên sách, tác giả và thể loại.
void Menu_search() {
	while (true) {
		// Biến input để kiểm tra regrex
		string input;
		// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
		int select;
		// Biến break dùng để thoát khỏi Menu_search để tới Menu
		int Brk = 0;
		// Màn hình lựa chọn chức năng tìm kiếm thông tin theo yêu cầu.
		do
		{
			system("cls");
			cout << "-------- TIM KIEM SACH THEO YEU CAU --------";
			cout << "\n1. Theo ten sach";
			cout << "\n2. Theo tac gia";
			cout << "\n3. Theo the loai";
			cout << "\n4. Exit";
			cout << "\nYour select: ";
			getline(cin, input);
			// Kiểm tra điều kiện Menu tìm kiếm
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(MenuSearch, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 4" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(MenuSearch, input));
		switch (select)
		{
		case 1:
		{
			lib.getBookManager()->showBooks();
			lib.getBookManager()->searchBooks(BookManager::Title);
			system("pause");
			break;
		}
		case 2:
		{
			lib.getBookManager()->showBooks();
			lib.getBookManager()->searchBooks(BookManager::Author);
			system("pause");
			break;
		}
		case 3:
		{
			lib.getBookManager()->showBooks();
			lib.getBookManager()->searchBooks(BookManager::Catergory);
			system("pause");
			break;
		}
		case 4:
		{
			Brk = 4;
			break;
		}
		}
		if (Brk == 4) {
			break;
		}
	}
}
void Menu_displayMostBorrowBook() {
	lib.getBookManager()->showMostBorrowedBooks();
	system("pause");
}



