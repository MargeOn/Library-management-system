#include "Library.h"
#include "UserManager.h"
#include "BookManager.h"
#include "FileManager.h"
#include "BorrowBook.h"
#include "Student.h"
#include "Teacher.h"
#include "Guest.h"
#include "User.h"
#include "Book.h"

Library::Library() {
	daySystem = "";
	userManager = nullptr;
	bookManager = nullptr;
	fileManager = new FileManager();
	bookManager = fileManager->readBookFile();
	userManager = fileManager->readUserFile();
	if (userManager == nullptr) {
		userManager = new UserManager();
	}
	if (bookManager == nullptr) {
		bookManager = new BookManager();
	}
	fileManager->readUserTransactionFile(userManager->getTransactionList());
	string tempDay;
	cout << "Vui long nhap ngay hien tai trong he thong:";
	getline(cin, tempDay);
	daySystem = tempDay;
}

void Library::makeTransaction(User* people) {
	bookManager->showBooks();
	cout << "Vui long lua chon ID sach ma ban muon muon:";
	int id;
	cin >> id;
	int indexBook = bookManager->findBook(id);
	if (indexBook != -1) {
		cin.ignore();
		BorrowBook borrowBook;
		borrowBook.setBorrowDay(daySystem);
		cout << "So luong cua sach hien tai ban muon muon: ";
		int count;
		cin >> count;
		// Trừ đi lượng sách mà người dùng mượn trong thư viện
		bookManager->removeBook(indexBook, count);
		bookManager->setIndexMostBorrowedBooks(indexBook);
		// Lấy thông tin sách ra trong thư viện
		Book temp = bookManager->getBook(indexBook);
		// Set số lượng sách mượn
		temp.set_Quantity(count);
		// Set thông tin sách
		borrowBook.setBook(temp);
		User* user = nullptr;
		if(userManager->getListUser().size() > 0)
			user = userManager->findUser(people->get_ID());
		if (user != nullptr) {
			if (userManager->updateUser(people)) {
				cout << "--> Nguoi dung nay da muon sach trong thu vien roi!" << endl;
				cout << "--> Cap nhat sach!" << endl;
				system("pause");
				cout << "--> Cap nhat thong tin nguoi dung!" << endl;
				system("pause");
				system("cls");
				user->addBorrowBook(borrowBook);
				delete people;
			}
			else {
				cout << "Kieu user khong tuong thich!!!" << endl;
				system("pause");
			}
		}
		else {
			cout << "--> Nguoi dung nay chua tung muon sach trong thu vien!" << endl;
			cout << "--> Cap nhat sach va nguoi dung moi!" << endl;
			system("pause");
			system("cls");
			people->addBorrowBook(borrowBook);
			userManager->addUser(people);
		}
		bookManager->setIndexMostBorrowedBooks(indexBook);
	}
	else {
		cout << "Sach ban muon tim khong co trong thu vien!!!" << endl;
		cout << "Vui long lua chon ID sach co trong danh sach!" << endl;
	}
}

// Hàm mà người dùng sẽ mượn sách trong thư viện
void Library::borrowedBook() {
	system("cls");
	string continues = "n";
	do {
		// Nhập thông tin một đối tượng người dùng mới
		cout << "Vui long nhap thong tin nguoi dung de muon sach: " << endl;
		cout << "1. Sinh vien" << endl;
		cout << "2. Giao vien" << endl;
		cout << "3. Khach" << endl;
		int select;
		cin >> select;
		User* people = nullptr;
		if (select == 1) {
			people = new Student();
			people->setRole("student");
		}
		else if (select == 2) {
			people = new Teacher();
			people->setRole("teacher");
		}
		else if (select == 3) {
			people = new Guest();
			people->setRole("guest");
		}
		else {
			cout << "Lua chon khong hop le!" << endl;
			return;
		}
		people->inputInfo();
		makeTransaction(people);
		cin.ignore();
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

void Library::returnBook() {
	string continues = "n";
	do {
		// Yêu cầu nhập tên người dùng muốn trả sách
		string key;
		int idUser;
		do
		{
			cout << "Vui long nhap ID cua nguoi dung muon tra sach: ";
			getline(cin, key);
			if (!Regrex(Key, key))
			{
				cout << "\nID nguoi dung phai la mot so cua du 8 chu so." << endl;
				system("pause");
			}
			else {
				idUser = stoi(key);
			}
		} while (!Regrex(Key, key));
		// Kiểm tra index của ID người dùng có trong danh sách không
		User* user = userManager->findUser(idUser);
		// Nếu người dùng chưa từng mượn sách thì thông báo và thoát.
		if (user == nullptr) {
			cout << "--> Nguoi dung nay chua tung muon sach" << endl;
			system("pause");
		}
		// Nếu người dùng đã từng mượn sách thì cho phép họ trả sách
		else {
			cout << "-->Co ID nguoi dung trong danh sach muon sach" << endl;
			system("pause");
			// Yêu cầu nhập ID sách muốn trả 
			string id;
			int idBook;
			do
			{
				cout << "Vui long nhap ID cua sach muon tra: ";
				getline(cin, id);
				if (!Regrex(Key, id))
				{
					cout << "\nID cua sach phai la mot so co 8 chu so" << endl;
					system("pause");
				}
				else {
					idBook = stoi(id);
				}
			} while (!Regrex(Key, id));
			// Trả về vị trí của sách trong số sách mà người dùng mượn
			int indexBook = user->findBook(idBook);
			if (indexBook != -1) {
				// Lấy số lượng sách của sách đó của người mượn
				int quantityBorrow = user->getBorrowBook(indexBook).getBook().get_Quantity();
				// Sau khi lấy được sách thì xóa sách đó khỏi thông tin người dùng và trả lại cho thư viện
				user->removeBorrowBook(indexBook);
				// Tăng số lượng của sách được trả vào thư viện
				int indexBookInManager = bookManager->findBook(idBook);
				bookManager->getBook(indexBookInManager).set_Quantity(bookManager->getBook(indexBookInManager).get_Quantity() + quantityBorrow);
				// Nếu người dùng trả hết sách thì xóa thông tin người dùng trong thư viện
				if (user->getSizeBorrow() == 0) {
					userManager->removeUser(idUser);
				}
				cout << "Ban da tra sach thanh cong!!!" << endl;
			}
			else {
				cout << "Sach ban muon tim khong co trong thu vien!!!" << endl;
				cout << "Vui long lua chon ID sach co trong danh sach!" << endl;
			}
		}
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
		// Nếu nhập 'y', quay lại vòng lặp và tiếp tục nhập thông tin để trả sách
	} while (continues == "y");
}

void Library::saveBookToFile() {
	fileManager->saveBookManagerToFile(bookManager);
}

void Library::saveUserToFile() {
	fileManager->saveUserManagerToFile(userManager);
}

void Library::saveTransactionListToFile() {
	fileManager->saveUserTransactionManagerToFile(userManager->getTransactionList());
}

void Library::showTransactionList() {
	userManager->displayUserBorrowOverDueBooks(daySystem);
}
BookManager* Library::getBookManager() {
	return this->bookManager;
}
UserManager* Library::getUserManager() {
	return this->userManager;
}
