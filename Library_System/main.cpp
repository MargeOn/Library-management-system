#include"ThuVien.h"
#include"QuanLiSach.h"

using namespace std;

// Khai báo hệ thống quản lí thư viện
ThuVien LibSystem;
QuanliSach BookSystem;
// Khai báo hàm hiển thị các lựa chọn tìm kiếm, nhập xuất thông tin trong hệ thống quản lí thư viện. 
void Menu();
// 1. Khai báo hàm hiển thị chức năng để người dùng mượn sách và cập nhật các thông tin sách đã mượn và người dùng là ai.
void Menu_borrowedBook();
// 2. Khai báo hàm hiển thị chức năng để người dùng trả sách và cập nhật các thông tin sách đã mượn và người dùng là ai.
void Menu_returnBook();
// 3. Khai báo hàm hiển thị chức năng tìm kiếm sách theo các yêu cầu: tên sách, tác giả và thể loại.
void Menu_search();
// 4. Khai báo hàm hiển thị chức năng xuất thông tin người dùng và sách được lưu trữ trong hệ thống quản lí thư viện.
void Menu_outPut();
// Hàm người dùng mượn sách trong thư viện
void BorrowedBook();
// Hàm mà người dùng sẽ trả sách cho thư viện
void ReturnBook();
// Hàm xuất thông tin các sách theo tên sách
void Search_Namebook();
// Hàm xuất thông tin các sách theo tên tác giả
void Search_Author();
// Hàm xuất thông tin các sách với các thể loại sách khác nhau
void Search_Genre(string data);
// Menu lựa chọn xuất thông tin các sách theo thể loại
void Menu_Genre();

void Output_User();

void show_Listbook();
// Hàm xuất thông tin các sách đã được mượn nhiều nhất
void reportMostBorrowedBooks();
// Hàm xuất thông tin các sách đã được quá 30 ngày 
void MenuOverdueBooks();

int main() {
	BookSystem.readBookFile();
	BookSystem.sortListbook(IDbook);
	system("cls");
	LibSystem.readUserFile();
	LibSystem.InputDayLib();
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
			cout << "HOM NAY LA NGAY:" << LibSystem.getNgay().getpresentDay() << endl;
			cout << "===========================================" << endl;
			cout << "=         HE THONG QUAN LI THU VIEN       =" << endl;
			cout << "===========================================";
			cout << "\n1. Muon sach";
			cout << "\n2. Tra sach";
			cout << "\n3. Tim kiem sach trong thu vien";
			cout << "\n4. Liet ke thong tin duoc luu tru";
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
			reportMostBorrowedBooks();
			break;
		}
		case 6:
		{
			// Màn hình hiển thị chức năng xuất thông tin người dùng và sách được lưu trữ trong hệ thống quản lí thư viện.
			MenuOverdueBooks();
			break;
		}
		case 7:
		{
			cout << "\nHe thong da tat. Hen gap lai. " << endl;
			system("pause");
			exit(0);
		}
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
		BorrowedBook();
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
		ReturnBook();
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
			Search_Namebook();
			system("pause");
			break;
		}
		case 2:
		{
			Search_Author();
			system("pause");
			break;
		}
		case 3:
		{
			BookSystem.sortListbook(IDbook);
			Menu_Genre();
			system("pause");
			break;
		}
		case 4:
		{
			BookSystem.sortListbook(IDbook);
			Brk = 4;
			break;
		}
		}
		if (Brk == 4) {
			break;
		}
	}
}
// 4. Khai báo hàm hiển thị chức năng xuất thông tin người dùng và sách được lưu trữ trong hệ thống quản lí thư viện.
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
			show_Listbook();
			system("pause");
			break;
		}
		case 2:
		{
			Output_User();
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

// Hàm mà người dùng sẽ mượn sách trong thư viện
void BorrowedBook() {
	system("cls");
	// Nhập thông tin một đối tượng người dùng mới
	cout << "Vui long nhap thong tin nguoi dung de muon sach " << endl;
	User people;
	people.Nhap_thongtinPeople();
	string continues = "n";
	do {
		// Trả về index của ID của người dùng có từng mượn sách trong thư viện hay chưa.
		int FoundIdx = LibSystem.check_UserID(people);
		// Nếu không trùng ID User trong danh sách thì người đó chưa từng mượn sách
		if (FoundIdx == -1) {
			cout << "--> Nguoi dung nay chua tung muon sach trong thu vien!" << endl;
			system("pause");
			system("cls");
			// Hiển thị danh sách các sách mà người dùng muốn mượn 
			show_Listbook();
			// Yêu cầu lựa chọn danh sách 
			string book;
			int select;
			do
			{
				cout << "\nVui long lua chon sach ma ban muon muon:";
				getline(cin, book);
				if (!Regrex(BOOK, book))
				{
					cout << "\nVui long lua chon chu so tuong ung voi cac sach co trong danh sach! " << endl;
					system("pause");
				}
				// Nếu trả về true thì đổi giá trị input thành số nguyên 
				else {
					select = stoi(book);
				}
			} while (!Regrex(BOOK, book));
			Book temp = BookSystem.getBook(select - 1);
			// Nếu số lượng quyển sách ấy còn trong thư viện thì cho người dùng mượn 
			if (BookSystem.sizeNum(select - 1) > 0) {
				// Thêm thông tin ngày mượn sách của người dùng khi họ mượn sách
				temp.set_Day(LibSystem.getNgay().getpresentDay());
				// Cho người dùng mới mượn sách 
				people.Insert_Book(temp);
				// Và lưu thông tin người dùng mới vào thư viện
				LibSystem.Insert_User(people);
				cout << "Muon sach thanh cong! Da luu thong tin nguoi dung vao trong thu vien." << endl;
				system("pause");
				// Trừ đi 1 quyển sách đã cho mượn
				BookSystem.lessNum(select - 1);
				// Nếu số lượng sách mà người dùng đã chọn đã hết thì đặt trạng thái sách đó là Borrowed
				if (BookSystem.sizeNum(select - 1) == 0) {
					BookSystem.getBook(select - 1).set_isAvailable(0);
				}
				BookSystem.writeBookFile();
				LibSystem.writeUserFile();
			}
			else {
				cout << "So luong quyen sach nay da het! Vui long chon quyen sach khac." << endl;
				system("pause");
			}
		}
		// Nếu người dùng trước đây đã mượn sách
		else {
			cout << "--> Nguoi dung nay da muon sach trong thu vien roi!" << endl;
			system("pause");
			system("cls");
			// Hiển thị danh sách các sách mà người dùng muốn mượn 
			show_Listbook();
			// Yêu cầu lựa chọn danh sách 
			string book;
			int select;
			do
			{
				cout << "\nVui long lua chon sach ma ban muon muon:";
				getline(cin, book);
				if (!Regrex(BOOK, book))
				{
					cout << "\nVui long lua chon chu so tuong ung voi cac sach co trong danh sach! " << endl;
					system("pause");
				}
				// Nếu trả về true thì đổi giá trị input thành số nguyên 
				else {
					select = stoi(book);
				}
			} while (!Regrex(BOOK, book));
			Book temp = BookSystem.getBook(select - 1);
			// Nếu số lượng quyển sách ấy còn trong thư viện thì cho người dùng mượn 
			if (BookSystem.sizeNum(select - 1) > 0) {
				// Khi có được index của người dùng đã mượn trước đây thì tìm kiếm sách mà người dùng đó muốn mượn
				// có trùng với sách trước đây đã từng mượn chưa
				int SearchID = LibSystem.search_ListBookID(LibSystem.getUser(FoundIdx), temp.get_ID());
				// Nếu là mượn sách khác thì cập nhật thông tin người dùng (trừ ID User của người ấy) và cho mượn sách
				if (SearchID == -1) {
					// Cập nhật thông tin người dùng
					LibSystem.updateInfoUser(FoundIdx, people);
					// Thêm thông tin ngày mượn sách của người dùng khi họ mượn sách
					temp.set_Day(LibSystem.getNgay().getpresentDay());
					// Cho người đó mượn
					LibSystem.borrowedBook(FoundIdx, temp);
					cout << "Da cap nhat thong tin nguoi dung muon sach va cho ho muon sach." << endl;
					system("pause");
					// Trừ đi 1 quyển sách đã cho mượn
					BookSystem.lessNum(select - 1);
					// Nếu số lượng sách mà người dùng đã chọn đã hết thì đặt trạng thái sách đó là Borrowed
					if (BookSystem.sizeNum(select - 1) == 0) {
						BookSystem.getBook(select - 1).set_isAvailable(0);
					}
					BookSystem.writeBookFile();
					LibSystem.writeUserFile();
				}
				// Nếu sách đó đã được người dùng mượn từ trước đây không cho mượn nữa
				else {
					cout << "Ban da muon quyen sach nay roi! Vui long chon quyen sach khac." << endl;
					system("pause");
				}
			}
			else {
				cout << "So luong quyen sach nay da het! Vui long chon quyen sach khac." << endl;
				system("pause");
			}
		}
		// Vòng lặp khi nhập không hợp lệ lựa chọn yêu cầu
		do
		{
			// Có muốn người dùng mượn thêm sách hay không
			cout << "--> Ban co muon muon sach trong thu vien nua khong? (y/n): ";
			getline(cin, continues);
			// Kiểm tra nhập thông tin có hợp lệ hay không
			if (!isValidCharacter(continues))
			{
				cout << "\nLua chon phai la 'y' hoac 'n'! " << endl;
				system("pause");
			}
			// Nếu nhập không hợp lệ, cho phép nhập lại lần nữa
		} while (!isValidCharacter(continues));
		// Nếu nhập 'y', quay lại vòng lặp và tiếp tục nhập thông tin để  mượn sách
	} while (continues == "y");
}

// Hàm mà người dùng sẽ trả sách cho thư viện
void ReturnBook() {
	// Yêu cầu nhập tên người dùng muốn trả sách
	string idUser;
	int key;
	do
	{
		cout << "Vui long nhap ID cua nguoi dung muon tra sach: ";
		getline(cin, idUser);
		if (!Regrex(Key, idUser))
		{
			cout << "\nID nguoi dung phai la mot so cua du 8 chu so." << endl;
			system("pause");
		}
		else {
			key = stoi(idUser);
		}
	} while (!Regrex(Key, idUser));
	// Kiểm tra index của ID người dùng có trong danh sách không
	int FoundIdx = LibSystem.check_UserID(key);
	// Nếu người dùng chưa từng mượn sách thì thông báo và thoát.
	if (FoundIdx == -1) {
		cout << "--> Nguoi dung nay chua tung muon sach" << endl;
		system("pause");
	}
	// Nếu người dùng đã từng mượn sách thì cho phép họ trả sách
	else{
		cout << "-->Co ID nguoi dung trong danh sach muon sach" << endl;
		system("pause");
		string continues = "n";
		do {
			system("cls");
			// Yêu cầu nhập ID sách muốn trả 
			string idBook;
			int ID;
			do
			{
				cout << "Vui long nhap ID cua sach muon tra: ";
				getline(cin, idBook);
				if (!Regrex(Key, idBook))
				{
					cout << "\nID cua sach phai la mot so co 8 chu so" << endl;
					system("pause");
				}
				else {
					ID = stoi(idBook);
				}
			} while (!Regrex(Key, idBook));
			// Tìm ID sách của người dùng đã tìm thấy trong danh sách trước đó
			int FoundID = LibSystem.search_ListBookID(LibSystem.getUser(FoundIdx), ID);
			int isreturnAll = LibSystem.getUser(FoundIdx).sizeBorrowedBook();
			// Nếu không có thì thông báo và không thực hiện trả được sách
			if (FoundID == -1) {
				cout << "ID cua sach nay khong co trong thu vien hoac nguoi dung khong co muon sach nay!" << endl;
			}
			// Nếu sách mà người dùng muốn trả có trong hệ thống người dùng đã mượn sách thì thực hiện trả sách
			else {
				LibSystem.returnBook(LibSystem.getUser(FoundIdx), FoundID);
				// Duyệt hệ thống thông tin các sách có trong thư viện. Cập nhật trạng thái của sách có trong danh sách và file 
				for (int i = 0; i < BookSystem.size(); i++) {
					if (FoundID == BookSystem.getBook(i).get_ID()) {
						BookSystem.addNum(i);
						BookSystem.getBook(i).set_isAvailable(1);
					}
				}
				if (LibSystem.getUser(FoundIdx).sizeBorrowedBook() == 0) {
					LibSystem.eraseUser(FoundIdx);
					cout << "Nguoi dung nay da tra sach het cho thu vien roi! Cam on ban rat nhieu!" << endl;
					system("pause");
					isreturnAll = 0;
				}
				else {
					cout << "Nguoi dung nay da tra sach cho thu vien. Cam on ban rat nhieu!" << endl;
					system("pause");
				}
				BookSystem.writeBookFile();
				LibSystem.writeUserFile();
			}
			// Nếu người dùng hiện tại đã trả hết sách mà mình mượn
			if (isreturnAll > 0) {
				// Vòng lặp khi nhập không hợp lệ lựa chọn yêu cầu
				do
				{
					// Có muốn người dùng trả thêm sách hay không
					cout << "--> Ban co muon tra sach nua khong? (y/n): ";
					getline(cin, continues);
					// Kiểm tra nhập thông tin có hợp lệ hay không
					if (!isValidCharacter(continues))
					{
						cout << "\nLua chon phai la 'y' hoac 'n'! " << endl;
						system("pause");
					}
					// Nếu nhập không hợp lệ, cho phép nhập lại lần nữa
				} while (!isValidCharacter(continues));
			}
			else {
				continues = "n";
			}
			// Nếu nhập 'y', quay lại vòng lặp và tiếp tục nhập thông tin để trả sách
		} while (continues == "y");
	}
}

// Hàm xuất thông tin các sách theo tên sách
void Search_Namebook() {
	string name;
	do
	{
		system("cls");
		cout << "Ban muon tim kiem ten sach gi: ";
		getline(cin, name);
		if (!Regrex(Namebook, name))
		{
			// Tên sách có thể là một số(không phải là các số) hoặc là chữ cái có 2 từ trở lên
			cout << "\nTen sach co the la mot so, chu cai co 2 tu tro len hoac dang bi thua khoang trang o dau hoac cuoi chuoi! " << endl;
			system("pause");
		}
	} while (!Regrex(Namebook, name));
	BookSystem.sortListbook(Namebook);
	int FoundIdx = BookSystem.BinSearch(Namebook, name);
	if (FoundIdx == -1) {
		cout << "\nKhong tim kiem thay ten sach trong thu vien!" << endl;
	}
	else {
		cout << setw(35) << "Name book"
			<< setw(10) << "ID code"
			<< setw(30) << "Author"
			<< setw(20) << "Genre"
			<< setw(30) << "Year of Publication" << endl;
		cout << setw(35) << BookSystem.getBook(FoundIdx).get_Name()
			<< setw(10) << BookSystem.getBook(FoundIdx).get_ID()
			<< setw(30) << BookSystem.getBook(FoundIdx).get_Author()
			<< setw(20) << BookSystem.getBook(FoundIdx).get_Genre()
			<< setw(30) << BookSystem.getBook(FoundIdx).get_Year() << endl;
	}
}

// Hàm xuất thông tin các sách theo tên tác giả
void Search_Author() {
	string name;
	do
	{
		system("cls");
		cout << "Ban muon tim kiem ten tac gia nao: ";
		getline(cin, name);
		if (!Regrex(Namebook, name))
		{
			cout << "\nTen tac gia co the la mot so, chu cai co 2 tu tro len hoac dang bi thua khoang trang o dau hoac cuoi chuoi! " << endl;
			system("pause");
		}
	} while (!Regrex(Namebook, name));
	BookSystem.sortListbook(Author);
	int FoundIdx = BookSystem.BinSearch(Author, name);
	if (FoundIdx == -1) {
		cout << "\nKhong tim kiem thay ten tac gia trong thu vien!" << endl;
	}
	else {
		cout << setw(35) << "Name book"
			<< setw(10) << "ID code"
			<< setw(30) << "Author"
			<< setw(20) << "Genre"
			<< setw(30) << "Year of Publication" << endl;
		// Khi nhập tên tác giả là chữ cái hoa hoặc thường thì đều có thể tìm kiếm được 
			cout << setw(35) << BookSystem.getBook(FoundIdx).get_Name()
				<< setw(10) << BookSystem.getBook(FoundIdx).get_ID()
				<< setw(30) << BookSystem.getBook(FoundIdx).get_Author()
				<< setw(20) << BookSystem.getBook(FoundIdx).get_Genre()
				<< setw(30) << BookSystem.getBook(FoundIdx).get_Year() << endl;
			
	}
}
// Hàm xuất thông tin các sách với các thể loại sách khác nhau
void Search_Genre(string data) {
	cout << setw(35) << "Name book"
		<< setw(10) << "ID code"
		<< setw(30) << "Author"
		<< setw(20) << "Genre"
		<< setw(30) << "Year of Publication" << endl;
	for (int i = 0; i < BookSystem.size(); i++) {
		if (BookSystem.getBook(i).get_Genre() == data) {
			cout << setw(35) << BookSystem.getBook(i).get_Name()
				<< setw(10) << BookSystem.getBook(i).get_ID()
				<< setw(30) << BookSystem.getBook(i).get_Author()
				<< setw(20) << BookSystem.getBook(i).get_Genre()
				<< setw(30) << BookSystem.getBook(i).get_Year() << endl;
		}
	}
}

void Menu_Genre() {
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
			cout << "Ban muon tim kiem the loai sach nao?";
			cout << "\n1. Fiction";
			cout << "\n2. Adventure";
			cout << "\n3. Novel";
			cout << "\n4. Romance";
			cout << "\n5. Mystery";
			cout << "\n6. Exit";
			cout << "\nYour select: ";
			getline(cin, input);
			// Kiểm tra điều kiện Menu xuất 
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(Sgenre, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 6" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(Sgenre, input));
		switch (select)
		{
		case 1:
		{
			Search_Genre("Fiction");
			system("pause");
			break;
		}
		case 2:
		{
			Search_Genre("Adventure");
			system("pause");
			break;
		}
		case 3:
		{
			Search_Genre("Novel");
			system("pause");
			break;
		}
		case 4: {
			Search_Genre("Romance");
			system("pause");
			break;
		}
		case 5: {
			Search_Genre("Mystery");
			system("pause");
			break;
		}
		case 6: {
			Brk = 6;
			break;
		}
		}
		if (Brk == 6) {
			break;
		}
	}
}

void Output_User() {
	cout << setw(20) << "Name"
		<< setw(10) << "ID"
		<< setw(25) << "Email"
		<< setw(15) << "Phone number" << endl;
	LibSystem.show_listUser();
}

void show_Listbook() {
	cout << setw(7) << "STT"  << setw(10) << "ID code"
		<< setw(35) << "Name book" << setw(30) << "Author"
		<< setw(20) << "Genre" << setw(30) << "Year of Publication" << setw(15) << endl;
	for (int i = 0; i < BookSystem.size(); i++) {
		cout << setw(5)  << i + 1 << ". " << setw(10) << BookSystem.getBook(i).get_ID()
			<< setw(35) << BookSystem.getBook(i).get_Name()
			<< setw(30) << BookSystem.getBook(i).get_Author()
			<< setw(20) << BookSystem.getBook(i).get_Genre()
			<< setw(30) << BookSystem.getBook(i).get_Year() << setw(15);
		if (BookSystem.getBook(i).get_isAvailable() == 1) {
			cout << "Available" << endl;
		}
		else {
			cout << "Borrowed" << endl;
		}
	}
}

// Hàm xuất thông tin các sách đã được mượn nhiều nhất
void reportMostBorrowedBooks() {
	int min = BookSystem.sizeNum(0);
	for (int i = 1; i < 17; i++) {
		if (min > BookSystem.sizeNum(i)) {
			min = BookSystem.sizeNum(i);
		}
	}
	if (min == 5) {
		system("cls");
		cout << "============================================" << endl;
		cout << "=  KHONG CO QUYEN SACH NAO DUOC MUON HET!  =" << endl;
		cout << "============================================" << endl;
		system("pause");
	}
	else {
		system("cls");
		cout << "--------- CAC SACH DUOC MUON NHIEU NHAT ---------" << endl;
		cout << setw(35) << "Name book"
			<< setw(10) << "ID code"
			<< setw(30) << "Author"
			<< setw(20) << "Genre"
			<< setw(30) << "Year of Publication" << endl;
		for (int i = 0; i < 17; i++) {
			if (min == BookSystem.sizeNum(i)) {
				cout << setw(35) << BookSystem.getBook(i).get_Name()
					<< setw(10) << BookSystem.getBook(i).get_ID()
					<< setw(30) << BookSystem.getBook(i).get_Author()
					<< setw(20) << BookSystem.getBook(i).get_Genre()
					<< setw(30) << BookSystem.getBook(i).get_Year() << endl;
			}
		}
		system("pause");
	}
}

// Hàm xuất thông tin các sách đã được quá 30 ngày 
void MenuOverdueBooks() {
	system("cls");
	cout << "--------- CAC CUON SACH MA CAC NGUOI DUNG DA MUON NHUNG CHUA TRA QUA 30 NGAY---------" << endl;
	cout << endl;
	cout << setw(35) << "Name book"
		<< setw(10) << "ID code"
		<< setw(30) << "Author"
		<< setw(20) << "Genre"
		<< setw(30) << "Year of Publication" << endl;
	LibSystem.reportOverdueBooks();
	system("pause");
}


