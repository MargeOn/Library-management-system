#include "ThuVien.h"

// Hàm khởi tạo đối tượng Book
ThuVien::ThuVien() {

}
// Hàm hủy đối tượng Book
ThuVien::~ThuVien() {

}
Ngay& ThuVien::getNgay() {
	return this->presentDay;
}
// Hàm nhập ngày tháng hiện tại trong thư viện 
void ThuVien::InputDayLib() {
	string ngaythangnam = "";
	do
	{
		system("cls");
		// Hiển thị ngày trước đây đã vào thư viện
		if (this->presentDay.getpresentDay() != "0/0/2024") {
			cout << "BAN DA DANG NHAP VAO THU VIEN VAO NGAY:" << this->presentDay.getpresentDay() << endl;
		}
		cout << "============================================================================" << endl;
		cout << "=      DE CAP NHAT VA QUAN LI THONG TIN CUA NGUOI DUNG TRONG THU VIEN      =" << endl;
		cout << "=             BAN PHAI NHAP NGAY THANG NAM CUA NGAY HOM NAY!!!             =" << endl;
		cout << "============================================================================" << endl;
		cout << "Vui long nhap thong tin ngay thang theo dinh dang xx/xx/2024:" << endl;
		getline(cin, ngaythangnam);
		if (!Regrex(Ngaythangnam, ngaythangnam) || (!this->presentDay.checkvalidDay(ngaythangnam)) || (!this->presentDay.isPastDay(ngaythangnam))){
			cout << "-----------------------------------------------------------------" << endl;
			cout << "Thong tin cua ban chua dung!!!Ban phai nhap theo cac yeu cau sau:" << endl;
			cout << "1. Ngay thang nam theo dung dinh dang." << endl;
			cout << "2. Ngay thang phai la ngay hien tai de cap nhat thu vien" << endl;
			cout << "3. Ngay thang nhap khong phai la ngay truoc luc cap nhat thu vien" << endl;
			cout << "Vui long nhap lai!!!" << endl;
			system("pause");
		}
	} while ((!Regrex(Ngaythangnam, ngaythangnam)) || (!this->presentDay.checkvalidDay(ngaythangnam)) || (!this->presentDay.isPastDay(ngaythangnam)));
	system("cls");
	cout << "=====CAP NHAT NGAY THANG NAM THANH CONG!!!=====" << endl;
	presentDay.setpresentDay(ngaythangnam);
	writeUserFile();
	system("pause");
}
// Hàm trả về một người dùng trong mảng quản lí người dùng
User& ThuVien::getUser(int pos) {
	return ListUser[pos];
}
// Hàm thêm một người dùng khi họ mượn sách
void ThuVien::Insert_User(User data) {
	ListUser.push_back(data);
	sortListUser();
}
// Hàm cập nhật ID của người dùng khi người dùng đã mượn sách từ trước và giờ lại mượn thêm sách khác
void ThuVien::updateInfoUser(int index, User data) {
	// Cập nhật lại các thông tin 
	ListUser[index].set_Name(data.get_Name());
	ListUser[index].set_Email(data.get_Email());
	ListUser[index].set_PhoneNumber(data.get_PhoneNumber());	
}

// Hàm để người dùng mượn sách
void ThuVien::borrowedBook(int index, Book data) {
	for (int i = 0; i < ListUser.size(); i++) {
		if (i == index) {
			ListUser[i].Insert_Book(data);
		}
	}
}

// Hàm người dùng trả sách 
void ThuVien::returnBook(User& user, int id) {
	// Duyệt mảng lưu trữ các người dùng đã mượn sách
	for (int i = 0; i < user.sizeBorrowedBook(); i++) {
		// Nếu tìm thấy ID sách mà người đó mượn thì
		if (id == user.getBorrowedBook(i).get_ID()) {
			// Ta sẽ xóa sách mà họ đã trả
			user.eraseBook(i);
		}
	}
}

// Hàm trả về index của người dùng khi tìm kiếm cuốn sách họ đang trả
void ThuVien::eraseUser(int index) {
	ListUser.erase(ListUser.begin() + index);
}


// Hàm hiển thị thông tin người dùng và sách mà họ mượn
void ThuVien::show_listUser() {
	for (int i = 0; i < ListUser.size(); i++) {
		cout << setw(65) << "===============================================================================================================" << endl;
		cout << setw(20) << ListUser[i].get_Name()
			<< setw(10) << ListUser[i].get_ID()
			<< setw(25) << ListUser[i].get_Email()
			<< setw(15) << ListUser[i].get_PhoneNumber() << endl;
		ListUser[i].XuatThongtinSach();
	}
}

// Hàm trả về index của ID người dùng khi mượn sách
int ThuVien::check_UserID(User data) {
	for (int i = 0; i < ListUser.size(); i++) {
		// Nếu data(là ID của người dùng) trùng với danh sách người dùng thì sẽ trả về index của nó trong danh sách người dùng
		// và được cập nhật lại thông tin của người dùng đó(trừ ID code)
		if (data.get_ID() == ListUser[i].get_ID()) {
			return i;
		}
	}
	return -1;
}

// Hàm trả về index của ID người dùng khi trả sách
int ThuVien::check_UserID(int data) {
	for (int i = 0; i < ListUser.size(); i++) {
		// Nếu data(là ID của người dùng) trùng với danh sách người dùng thì mới hỏi người dùng đó trả sách gì.
		if (data == ListUser[i].get_ID()) {
			return i;
		}
	}
	return -1;
}

// Hàm trả về ID sách của mỗi người dùng liệu có trong danh sách người dùng mượn hay không. 
int ThuVien::search_ListBookID(User user, int IDbook) {
	for (int i = 0; i < user.sizeBorrowedBook(); i++) {
		// Tìm kiếm ID của sách trong mỗi người dùng. Nếu tìm thấy thì trả về index trong danh sách Borrowed book
		if (IDbook == user.getBorrowedBook(i).get_ID()) {
			return IDbook;
		}
	}
	return -1;
}

// Hàm tính toán số ngày mượn của sách hiện tại có vượt quá 30 ngày hay không
int ThuVien::calculateDay(const string& str) {
	int dayPast = 0, monthPast = 0, dayPresent = 0, monthPresent = 0;
	// Tách chuỗi và lấy được ngày tháng hiện tại của thư viện
	vector<string> temp1 = explode(this->presentDay.getpresentDay(), '/');
	dayPresent = stoi(temp1[0]);
	monthPresent = stoi(temp1[1]);
	// Tách chuỗi và lấy được ngày tháng quá khứ của thư viện
	vector<string> temp2 = explode(str, '/');
	dayPast = stoi(temp2[0]);
	monthPast = stoi(temp2[1]);
	int tongngaymuon = 0;
	if (monthPresent < monthPast) {
		return 0;
	}
	if (monthPresent == monthPast) {
		tongngaymuon = dayPresent - dayPast + 1;
		return tongngaymuon;
	}
	else if ((monthPresent - monthPast) == 1) {
		// Tìm xem tháng monthPast có bao nhiêu ngày
		int tempPast = returndaysPerMonth(monthPast);
		tongngaymuon = (tempPast - dayPast + 1) + dayPresent;
		return tongngaymuon;
	}
	else {
		return 31;
	}
}
// Hàm kiểm tra số ngày mượn của sách hiện tại có vượt quá 30 ngày hay không
bool ThuVien::checkOverDay(const string& str){
	if (calculateDay(str) > 30) {
		return true;
	}
	return false;
}

// Hàm hiển thị các sách mượn chưa trả quá 30 ngày
void ThuVien::reportOverdueBooks() {
	bool overDue = false;
	for (int i = 0; i < ListUser.size(); i++) {
		for (int j = 0; j < ListUser[i].sizeBorrowedBook(); j++) {
			overDue = checkOverDay(ListUser[i].getBorrowedBook(j).get_Day());
			if (overDue == true) {
				cout << setw(110) << "=============================================================================================================================" << endl;
				cout << setw(35) << ListUser[i].getBorrowedBook(j).get_Name()
					<< setw(10) << ListUser[i].getBorrowedBook(j).get_ID()
					<< setw(30) << ListUser[i].getBorrowedBook(j).get_Author()
					<< setw(20) << ListUser[i].getBorrowedBook(j).get_Genre()
					<< setw(30) << ListUser[i].getBorrowedBook(j).get_Year() << endl;
				cout << setw(25) << "Nguoi dung chua tra sach" 
					<< setw(10) << "ID" 
					<< setw(25) << "Ngay muon sach" << endl
					<< setw(25) << ListUser[i].get_Name() << setw(10) << ListUser[i].get_ID() 
					<< setw(25) << ListUser[i].getBorrowedBook(j).get_Day() << endl;
			}
		}
	}
}
// Hàm sắp xếp theo ID người dùng
void ThuVien::sortListUser() {
	for (int i = 0; i < ListUser.size(); ++i) {
		bool swapped = false;
		for (int j = 0; j < ListUser.size() - i - 1; ++j) {
			if (ListUser[j].get_ID() > ListUser[j + 1].get_ID()) {
				swap(ListUser[j], ListUser[j + 1]);
				swapped = true;
			}
		}
		// Nếu không có sự hoán đổi nào xảy ra trong một vòng lặp, mảng đã được sắp xếp
		if (!swapped) {
			break;
		}
	}
}
// Hàm ghi từ file "User.txt" lên
void ThuVien::writeUserFile() {
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
			line.append(this->presentDay.getpresentDay());
			f << line;
			f << endl;
			if (ListUser.size() > 0) {
				// Đọc thông tin của tất cả các người dùng trong danh sách mượn sách để ghi vào file
				for (int i = 0; i < ListUser.size(); i++) {
					// ID của người dùng
					string line = "ID:";
					line.append(to_string(ListUser[i].get_ID()));
					// Tên người dùng
					line.append(",Name:");
					line.append(ListUser[i].get_Name());
					// Email người dùng
					line.append(",Email:");
					line.append(ListUser[i].get_Email());
					// Số điện thoại người dùng
					line.append(",PhoneNumber:");
					line.append(to_string(ListUser[i].get_PhoneNumber()));
					//
					for (int j = 0; j < ListUser[i].sizeBorrowedBook(); j++) {
						// ID Book
						line.append(";ID:");
						line.append(to_string(ListUser[i].getBorrowedBook(j).get_ID()));
						// Tên sách
						line.append(",Name:");
						line.append(ListUser[i].getBorrowedBook(j).get_Name());
						// Tác giả sách
						line.append(",Author:");
						line.append(ListUser[i].getBorrowedBook(j).get_Author());
						// Thể loại sách
						line.append(",Genre:");
						line.append(ListUser[i].getBorrowedBook(j).get_Genre());
						line.append(",Year of Publication:");
						line.append(to_string(ListUser[i].getBorrowedBook(j).get_Year()));
						line.append(",BorrowedDay:");
						line.append(ListUser[i].getBorrowedBook(j).get_Day());
					}
					f << line;
					// Khi đưa thông tin người dùng vào mỗi dòng thì đều ghi vào cuối dòng trong file kí tự endl để xuống dòng
					// ngoại trừ dòng cuối cuối cùng(hay cũng là người dùng cuối cùng) thì không ghi endl.
					if (i != ListUser.size() - 1) {
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

// Hàm ghi từ file "User.txt" lên
void ThuVien::readUserFile() {
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
			bool lineFisrt = true;
			while (!f.eof()) {
				if (lineFisrt) {
					getline(f, lineInfo);
					this->presentDay.setpresentDay(lineInfo);
					lineInfo = "";
					lineFisrt = false;
				}
				else {
					User usertemp;
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
								if (infoStr.size() >= 4) {
									for (int j = 0; j < infoStr.size(); j++) {
										// Chia chuỗi để lấy dữ liệu tương ứng
										vector<string> subData = explode(infoStr[j], ':');
										string temp = subData[1];
										if (subData.size() >= 2) {
											switch (j)
											{
											case 0: {
												usertemp.set_ID(stoi(temp));
												break;
											}
											case 1: {
												usertemp.set_Name(temp);
												break;
											}
											case 2: {
												usertemp.set_Email(temp);
												break;
											}
											case 3: {
												usertemp.set_PhoneNumber(stoi(temp));
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
								if (infoStr.size() >= 6) {
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
												bookTemp.set_Name(temp);
												break;
											}
											case 2: {
												bookTemp.set_Author(temp);
												break;
											}
											case 3: {
												bookTemp.set_Genre(temp);
												break;
											}
											case 4: {
												bookTemp.set_Year(stoi(temp));
												break;
											}
											case 5: {
												bookTemp.set_Day(temp);
												break;
											}
											}
										}
										else {
											throw "Thong tin cua sach ma nguoi dung da muon bi loi nen khong the them nua";
										}
									}
								}
								else {
									throw "Thong tin cua nguoi dung bi loi nen khong the them nua";
								}
								usertemp.Insert_Book(bookTemp);
							}
						}
						// Thêm thông tin người dùng mới đọc từ file vào ListUser
						ListUser.push_back(usertemp);
					}
				}
			}
		}
		// Đóng file
		f.close();
		cout << "========================== DA TAI THANH CONG DANH SACH NGUOI DUNG MUON SACH TRONG FILE USERSETTING ==========================" << endl;
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

