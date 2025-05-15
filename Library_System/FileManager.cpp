#include "FileManager.h"
#include "BookManager.h"
#include "UserManager.h"
#include "Student.h"
#include "Teacher.h"
#include "Guest.h"
#include "User.h"
#include "BorrowBook.h"
#include "Book.h"
#include "ValidData.h"
#include<fstream>
#include<stdexcept>
#include<string>
#include <vector>

FileManager::FileManager(){}

void FileManager::saveBookManagerToFile(BookManager* bookManager) {
	try {
		// Khởi tại đối tượng File tên f
		ofstream f;
		// Mở file
		f.open("Booksetting.txt", ios::out);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string line = "";
			if (bookManager->getListBook().size() > 0) {
				// Đọc thông tin của tất cả các người dùng trong danh sách mượn sách để ghi vào file
				// ID của người dùng
				for (int i = 0; i < bookManager->getListBook().size(); i++) {
					string line = "ID:";
					line.append(to_string(bookManager->getBook(i).get_ID()));
					// Tên người dùng
					line.append(",Title:");
					line.append(bookManager->getBook(i).get_Title());
					// Ngày sinh
					line.append(",Author:");
					line.append(bookManager->getBook(i).get_Author());
					// Email người dùng
					line.append(",Catergory:");
					line.append(bookManager->getBook(i).get_CategoryBook());
					// Vai trò, chức vụ
					line.append(",Year of Publication:");
					line.append(to_string(bookManager->getBook(i).get_Year()));
					line.append(",Number:");
					line.append(to_string(bookManager->getBook(i).get_Quantity()));
					f << line;
					// Khi đưa thông tin người dùng vào mỗi dòng thì đều ghi vào cuối dòng trong file kí tự endl để xuống dòng
					// ngoại trừ dòng cuối cuối cùng(hay cũng là người dùng cuối cùng) thì không ghi endl.
					if (i != bookManager->getListBook().size() - 1) {
						f << endl;
					}
				}
			}
		}
		// Đóng file
		f.close();
	}
	catch (exception e) {
		cout << "Error: " << e.what();
	}
	catch (...) {
		cout << "Khong the ghi file";
	}
}

void FileManager::saveUserManagerToFile(UserManager* userManager) {
	try {
		// Khởi tại đối tượng File tên f
		ofstream f;
		// Mở file
		f.open("Usersetting.txt", ios::out);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string line = "";
			if (userManager->getListUser().size() > 0) {
				// Đọc thông tin của tất cả các người dùng trong danh sách mượn sách để ghi vào file
				// ID của người dùng
				for (User* user : userManager->getListUser()) {
					string line = "ID:";
					line.append(to_string(user->get_ID()));
					// Tên người dùng
					line.append(",Name:");
					line.append(user->get_Name());
					// Ngày sinh
					line.append(",Birthday:");
					line.append(user->get_BirthDay());
					// Email người dùng
					line.append(",Email:");
					line.append(user->get_Email());
					// Vai trò, chức vụ
					line.append(",Role:");
					line.append(user->getRole());
					if (Student* stuPtr = dynamic_cast<Student*>(user)) {
						line.append(",Major:");
						line.append(stuPtr->getMajor());
					}
					else if (Teacher* teaPtr = dynamic_cast<Teacher*>(user)) {
						line.append(",Department:");
						line.append(teaPtr->getDepartment());
					}
					else if (Guest* guePtr = dynamic_cast<Guest*>(user)) {
						line.append(",Occupation:");
						line.append(guePtr->getCurrentOccupation());
					}
					for (int j = 0; j < user->getSizeBorrow(); j++) {
						// ID Book
						line.append(";ID:");
						line.append(to_string(user->getBorrowBook(j).getBook().get_ID()));
						// Tên sách
						line.append(",Name:");
						line.append(user->getBorrowBook(j).getBook().get_Title());
						// Tác giả sách
						line.append(",Author:");
						line.append(user->getBorrowBook(j).getBook().get_Author());
						// Thể loại sách
						line.append(",Catergory:");
						line.append(user->getBorrowBook(j).getBook().get_CategoryBook());
						// Năm xuất bản
						line.append(",Year of Publication:");
						line.append(to_string(user->getBorrowBook(j).getBook().get_Year()));
						// Ngày mượn sách
						line.append(",BorrowedDay:");
						line.append(user->getBorrowBook(j).getBorrowDay());
						// Số lượng sách
						line.append(",Number:");
						line.append(to_string(user->getBorrowBook(j).getBook().get_Quantity()));
					}
					f << line;
					// Khi đưa thông tin người dùng vào mỗi dòng thì đều ghi vào cuối dòng trong file kí tự endl để xuống dòng
					// ngoại trừ dòng cuối cuối cùng(hay cũng là người dùng cuối cùng) thì không ghi endl.
					auto it = userManager->getListUser().end();
					--it;
					User* temp = *it;
					if (user != temp) {
						f << endl;
					}					
				}
			}
		}
		// Đóng file
		f.close();
	}
	catch (exception e) {
		cout << "Error: " << e.what();
	}
	catch (...) {
		cout << "Khong the ghi file";
	}
}
BookManager* FileManager::readBookFile() {
	BookManager* bookManager = new BookManager();
	try {
		// Khởi tại đối tượng File tên f
		ifstream f;
		// Mở file
		f.open("Booksetting.txt", ios::in);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string lineInfo = "";
			while (!f.eof()) {
				Book booktemp;
				int Number = 0;
				getline(f, lineInfo);
				vector<string> dataLine = explode(lineInfo, ',');
				// Kiểm tra nếu mảng vector dataLine có chứa 6 chuỗi đã được tách thì thực hiện câu lệnh if.
				if (dataLine.size() < 6) {
					throw "Thong tin cua sach bi loi nen khong the cap nhat vao thu vien!";
				}
				else if (dataLine.size() >= 6) {
					for (int i = 0; i < 6; i++) {
						// Lấy lần lượt 6 chuỗi thông tin ID, tên người dùng, ngày sinh, email, role và chức vụ
						string userStr = dataLine[i];
						// Chia chuỗi (trong mỗi 6 chuỗi) thành 2 chuỗi nữa
						vector<string> infoStr = explode(userStr, ':');
						if (infoStr.size() < 2) {
							switch (i)
							{
							case 0: {
								throw "So lieu cua ID khong day du";
								break;
							}
							case 1: {
								throw "So lieu cua Namebook khong day du";
								break;
							}
							case 2: {
								throw "So lieu cua Author khong day du";
								break;
							}
							case 3: {
								throw "So lieu cua Genre khong day du";
								break;
							}
							case 4: {
								throw "So lieu cua Year of Publication khong day du";
								break;
							}
							case 5: {
								throw "So lieu cua StateBook khong day du";
								break;
							}
							case 6: {
								throw "So lieu cua So luong dau sach khong day du";
								break;
							}
							}
						}
						else if (infoStr.size() >= 2) {
							// Gán data của mỗi thông tin của sách vào class Book
							string dataStr = infoStr[1];
							switch (i)
							{
							case 0: {
								booktemp.set_ID(stoi(dataStr));
								break;
							}
							case 1: {
								booktemp.set_Title(dataStr);
								break;
							}
							case 2: {
								booktemp.set_Author(dataStr);
								break;
							}
							case 3: {
								booktemp.set_CategoryBook(dataStr);
								break;
							}
							case 4: {
								booktemp.set_Year(stoi(dataStr));
								break;
							}
							case 5: {
								booktemp.set_Quantity(stoi(dataStr));
								break;
							}
							}
						}
					}
				}
				// Đưa đối tượng sách mới được khởi tạo vào danh sách quản lí sách
				bookManager->addBook(booktemp);
			}
		}
		// Đóng file
		f.close();
		cout << "========================== DA TAI THANH CONG DANH SACH QUAN LI SACH TRONG FILE BOOKKSETTING ==========================" << endl;
	}
	catch (exception e) {
		cout << "Khong the mo file hoac file khong ton tai" << endl;
		delete bookManager;
		return nullptr;
	}
	catch (const char* str) {
		cout << str << endl;
		delete bookManager;
		return nullptr;
	}
	catch (...) {
		cout << "Khong the doc file" << endl;
		delete bookManager;
		return nullptr;
	}
	system("pause");
	return bookManager;
}
UserManager* FileManager::readUserFile() {
	UserManager* userManager = new UserManager();
	try {
		// Khởi tại đối tượng File tên f
		ifstream f;
		// Mở file
		f.open("Usersetting.txt", ios::in);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string lineInfo = "";
			while (!f.eof()) {
				User* user = nullptr;
				Student* stuPtr = nullptr;
				Teacher* teaPtr = nullptr;
				Guest* guePtr = nullptr;
				User* usertemp = new User();
				BorrowBook borrowBook;
				getline(f, lineInfo);
				if (!lineInfo.empty()) {
					// Khởi tạo một vector tên dataLine để đọc dữ liệu của một hàng trong file và sẽ chia thành các chuỗi bởi kí 
				// tự ';' và đưa vào vector.
					vector<string> dataLine = explode(lineInfo, ';');
					// Duyệt một dòng line tương ứng với một người dùng
					for (int i = 0; i < dataLine.size(); i++) {
						// Lấy lần lượt các chuỗi chứa thông tin thông tin của người dùng và sách mà họ mượn
						string tempStr = dataLine[i];
						// Nếu chuỗi hiện tại là thông tin người dùng 
						if (i == 0) {
							// Chia chuỗi đã lấy thành các chuỗi: Thông tin người dùng và các thông tin sách mà họ mượn
							vector<string> infoStr = explode(tempStr, ',');
							if (infoStr.size() >= 6) {
								for (int j = 0; j < infoStr.size(); j++) {
									// Chia chuỗi để lấy dữ liệu tương ứng
									vector<string> subData = explode(infoStr[j], ':');
									string temp = subData[1];
									if (subData.size() >= 2) {
										switch (j)
										{
										case 0: {
											usertemp->set_ID(stoi(temp));
											break;
										}
										case 1: {
											usertemp->set_Name(temp);
											break;
										}
										case 2: {
											usertemp->set_BirthDay(temp);
											break;
										}
										case 3: {
											usertemp->set_Email(temp);
											break;
										}
										case 4: {
											usertemp->setRole(temp);
											break;
										}
										case 5: {
											if (usertemp->getRole() == "student") {
												user = new Student();
												if (stuPtr = dynamic_cast<Student*>(user)) {
													stuPtr->setMajor(temp);
												}
											}
											else if (usertemp->getRole() == "teacher") {
												user = new Teacher();
												if (teaPtr = dynamic_cast<Teacher*>(user)) {
													teaPtr->setDepartment(temp);
												}
											}
											else if (usertemp->getRole() == "guest") {
												user = new Guest();
												if (guePtr = dynamic_cast<Guest*>(user)) {
													guePtr->setCurrentOccupation(temp);
												}
											}
											user->set_ID(usertemp->get_ID());
											user->set_Name(usertemp->get_Name());
											user->set_BirthDay(usertemp->get_BirthDay());
											user->set_Email(usertemp->get_Email());
											user->setRole(usertemp->getRole());
											delete usertemp;
											break;
										}
										}
									}
									else {
										throw "Thong tin cua nguoi dung bi loi nen khong the them nua";
									}
								}
							}
							else {
								throw "Thong tin cua nguoi dung bi loi nen khong the them nua";
							}
						}
						else {
							Book bookTemp;
							// Chia chuỗi đã lấy thành các chuỗi: các thông tin sách mà họ mượn
							vector<string> infoStr = explode(tempStr, ',');
							if (infoStr.size() >= 7) {
								for (int j = 0; j < infoStr.size(); j++) {
									// Chia chuỗi để lấy dữ liệu tương ứng
									vector<string> subData = explode(infoStr[j], ':');
									string temp = subData[1];
									if (subData.size() >= 2) {
										switch (j)
										{
										case 0: {
											bookTemp.set_ID(stoi(temp));
											break;
										}
										case 1: {
											bookTemp.set_Title(temp);
											break;
										}
										case 2: {
											bookTemp.set_Author(temp);
											break;
										}
										case 3: {
											bookTemp.set_CategoryBook(temp);
											break;
										}
										case 4: {
											bookTemp.set_Year(stoi(temp));
											break;
										}
										case 5: {
											borrowBook.setBorrowDay(temp);
											break;
										}
										case 6: {
											bookTemp.set_Quantity(stoi(temp));
											break;
										}
										}
									}
									else {
										throw "Thong tin cua sach ma nguoi dung da muon bi loi nen khong the them nua";
									}
								}
								borrowBook.setBook(bookTemp);
								user->addBorrowBook(borrowBook);
							}
							else {
								throw "Thong tin cua nguoi dung bi loi nen khong the them nua";
							}
						}
					}
					// Thêm thông tin người dùng mới đọc từ file vào ListUser
					userManager->getListUser().insert(user);
				}
			}
			// Đóng file
			f.close();
			cout << "========================== DA TAI THANH CONG DANH SACH NGUOI DUNG MUON SACH TRONG FILE USERSETTING ==========================" << endl;
		}
	}
	catch (exception e) {
		cout << "Khong the mo file hoac file khong ton tai" << endl;
		delete userManager;
		return nullptr;
	}
	catch (const char* str) {
		cout << str << endl;
		delete userManager;
		return nullptr;
	}
	catch (...) {
		cout << "Khong the doc file" << endl;
		delete userManager;
		return nullptr;
	}
	system("pause");
	return userManager;
}

void FileManager::saveUserTransactionManagerToFile(const vector<User*>& transaction) {
	try {
		// Khởi tại đối tượng File tên f
		ofstream f;
		// Mở file
		f.open("TransactionSetting.txt", ios::out);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string line = "";
			if (transaction.size() > 0) {
				// Đọc thông tin của tất cả các người dùng trong danh sách mượn sách để ghi vào file
				// ID của người dùng
				for (int i = 0; i < transaction.size(); i++) {
					string line = "ID:";
					line.append(to_string(transaction[i]->get_ID()));
					// Tên người dùng
					line.append(",Name:");
					line.append(transaction[i]->get_Name());
					// Ngày sinh
					line.append(",Birthday:");
					line.append(transaction[i]->get_BirthDay());
					// Email người dùng
					line.append(",Email:");
					line.append(transaction[i]->get_Email());
					// Vai trò, chức vụ
					line.append(",Role:");
					line.append(transaction[i]->getRole());
					if (Student* stuPtr = dynamic_cast<Student*>(transaction[i])) {
						line.append(",Major:");
						line.append(stuPtr->getMajor());
					}
					else if (Teacher* teaPtr = dynamic_cast<Teacher*>(transaction[i])) {
						line.append(",Department:");
						line.append(teaPtr->getDepartment());
					}
					else if (Guest* guePtr = dynamic_cast<Guest*>(transaction[i])) {
						line.append(",Occupation:");
						line.append(guePtr->getCurrentOccupation());
					}
					for (int j = 0; j < transaction[i]->getSizeBorrow(); j++) {
						// ID Book
						line.append(";ID:");
						line.append(to_string(transaction[i]->getBorrowBook(j).getBook().get_ID()));
						// Tên sách
						line.append(",Name:");
						line.append(transaction[i]->getBorrowBook(j).getBook().get_Title());
						// Tác giả sách
						line.append(",Author:");
						line.append(transaction[i]->getBorrowBook(j).getBook().get_Author());
						// Thể loại sách
						line.append(",Catergory:");
						line.append(transaction[i]->getBorrowBook(j).getBook().get_CategoryBook());
						// Năm xuất bản
						line.append(",Year of Publication:");
						line.append(to_string(transaction[i]->getBorrowBook(j).getBook().get_Year()));
						// Ngày mượn sách
						line.append(",BorrowedDay:");
						line.append(transaction[i]->getBorrowBook(j).getBorrowDay());
						// Số lượng sách
						line.append(",Number:");
						line.append(to_string(transaction[i]->getBorrowBook(j).getBook().get_Quantity()));
					}
					f << line;
					// Khi đưa thông tin người dùng vào mỗi dòng thì đều ghi vào cuối dòng trong file kí tự endl để xuống dòng
					// ngoại trừ dòng cuối cuối cùng(hay cũng là người dùng cuối cùng) thì không ghi endl.
					if (i != transaction.size() - 1) {
						f << endl;
					}
				}
			}
		}
		// Đóng file
		f.close();
	}
	catch (exception e) {
		cout << "Error: " << e.what();
	}
	catch (...) {
		cout << "Khong the ghi file";
	}
}

void FileManager::readUserTransactionFile(vector<User*>& transaction) {
	try {
		// Khởi tại đối tượng File tên f
		ifstream f;
		// Mở file
		f.open("TransactionSetting.txt", ios::in);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string lineInfo = "";
			while (!f.eof()) {
				User* user = nullptr;
				Student* stuPtr = nullptr;
				Teacher* teaPtr = nullptr;
				Guest* guePtr = nullptr;
				User* usertemp = new User();
				BorrowBook borrowBook;
				getline(f, lineInfo);
				if (!lineInfo.empty()) {
					// Khởi tạo một vector tên dataLine để đọc dữ liệu của một hàng trong file và sẽ chia thành các chuỗi bởi kí 
				// tự ';' và đưa vào vector.
					vector<string> dataLine = explode(lineInfo, ';');
					// Duyệt một dòng line tương ứng với một người dùng
					for (int i = 0; i < dataLine.size(); i++) {
						// Lấy lần lượt các chuỗi chứa thông tin thông tin của người dùng và sách mà họ mượn
						string tempStr = dataLine[i];
						// Nếu chuỗi hiện tại là thông tin người dùng 
						if (i == 0) {
							// Chia chuỗi đã lấy thành các chuỗi: Thông tin người dùng và các thông tin sách mà họ mượn
							vector<string> infoStr = explode(tempStr, ',');
							if (infoStr.size() >= 6) {
								for (int j = 0; j < infoStr.size(); j++) {
									// Chia chuỗi để lấy dữ liệu tương ứng
									vector<string> subData = explode(infoStr[j], ':');
									string temp = subData[1];
									if (subData.size() >= 2) {
										switch (j)
										{
										case 0: {
											usertemp->set_ID(stoi(temp));
											break;
										}
										case 1: {
											usertemp->set_Name(temp);
											break;
										}
										case 2: {
											usertemp->set_BirthDay(temp);
											break;
										}
										case 3: {
											usertemp->set_Email(temp);
											break;
										}
										case 4: {
											usertemp->setRole(temp);
											break;
										}
										case 5: {
											if (usertemp->getRole() == "student") {
												user = new Student();
												if (stuPtr = dynamic_cast<Student*>(user)) {
													stuPtr->setMajor(temp);
												}
											}
											else if (usertemp->getRole() == "teacher") {
												user = new Teacher();
												if (teaPtr = dynamic_cast<Teacher*>(user)) {
													teaPtr->setDepartment(temp);
												}
											}
											else if (usertemp->getRole() == "guest") {
												user = new Guest();
												if (guePtr = dynamic_cast<Guest*>(user)) {
													guePtr->setCurrentOccupation(temp);
												}
											}
											user->set_ID(usertemp->get_ID());
											user->set_Name(usertemp->get_Name());
											user->set_BirthDay(usertemp->get_BirthDay());
											user->set_Email(usertemp->get_Email());
											user->setRole(usertemp->getRole());
											delete usertemp;
											break;
										}
										}
									}
									else {
										throw "Thong tin cua nguoi dung bi loi nen khong the them nua";
									}
								}
							}
							else {
								throw "Thong tin cua nguoi dung bi loi nen khong the them nua";
							}
						}
						else {
							Book bookTemp;
							// Chia chuỗi đã lấy thành các chuỗi: các thông tin sách mà họ mượn
							vector<string> infoStr = explode(tempStr, ',');
							if (infoStr.size() >= 7) {
								for (int j = 0; j < infoStr.size(); j++) {
									// Chia chuỗi để lấy dữ liệu tương ứng
									vector<string> subData = explode(infoStr[j], ':');
									string temp = subData[1];
									if (subData.size() >= 2) {
										switch (j)
										{
										case 0: {
											bookTemp.set_ID(stoi(temp));
											break;
										}
										case 1: {
											bookTemp.set_Title(temp);
											break;
										}
										case 2: {
											bookTemp.set_Author(temp);
											break;
										}
										case 3: {
											bookTemp.set_CategoryBook(temp);
											break;
										}
										case 4: {
											bookTemp.set_Year(stoi(temp));
											break;
										}
										case 5: {
											borrowBook.setBorrowDay(temp);
											break;
										}
										case 6: {
											bookTemp.set_Quantity(stoi(temp));
											break;
										}
										}
									}
									else {
										throw "Thong tin cua sach ma nguoi dung da muon bi loi nen khong the them nua";
									}
								}
								borrowBook.setBook(bookTemp);
								user->addBorrowBook(borrowBook);
							}
							else {
								throw "Thong tin cua nguoi dung bi loi nen khong the them nua";
							}
						}
					}
					// Thêm thông tin người dùng mới đọc từ file vào ListUser
					transaction.push_back(user);
				}
			}
			// Đóng file
			f.close();
			cout << "========================== DA TAI THANH CONG DANH SACH NGUOI DUNG MUON SACH TRONG FILE Transaction ==========================" << endl;
		}
	}
	catch (exception e) {
		cout << "Khong the mo file hoac file khong ton tai" << endl;
	}
	catch (const char* str) {
		cout << str << endl;
	}
	catch (...) {
		cout << "Khong the doc file" << endl;
	}
	system("pause");
}