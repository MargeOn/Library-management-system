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
UserSystem& ThuVien::getUserSystem() {
	return this->Usersystem;
}

BookSystem& ThuVien::getBookSystem() {
	return this->Booksystem;
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
	writeNgayFile();
	Usersystem.writeUserFile();
	system("pause");
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
	for (int i = 0; i < Usersystem.getSizeUser(); i++) {
		for (int j = 0; j < Usersystem.getUser(i).sizeBorrowedBook(); j++) {
			overDue = checkOverDay(Usersystem.getUser(i).getBorrowedBook(j).get_Day());
			if (overDue == true) {
				cout << setw(110) << "=============================================================================================================================" << endl;
				cout << setw(35) << Usersystem.getUser(i).getBorrowedBook(j).get_Name()
					<< setw(10) << Usersystem.getUser(i).getBorrowedBook(j).get_ID()
					<< setw(30) << Usersystem.getUser(i).getBorrowedBook(j).get_Author()
					<< setw(20) << Usersystem.getUser(i).getBorrowedBook(j).get_Genre()
					<< setw(30) << Usersystem.getUser(i).getBorrowedBook(j).get_Year() << endl;
				cout << setw(25) << "Nguoi dung chua tra sach" 
					<< setw(10) << "ID" 
					<< setw(25) << "Ngay muon sach" << endl
					<< setw(25) << Usersystem.getUser(i).get_Name() << setw(10) << Usersystem.getUser(i).get_ID()
					<< setw(25) << Usersystem.getUser(i).getBorrowedBook(j).get_Day() << endl;
			}
		}
	}
}

// Hàm ghi từ file "Day.txt" lên
void ThuVien::writeNgayFile() {
	try {
		// Khởi tại đối tượng File tên f
		ofstream f;
		// Mở file
		f.open("Daysetting.txt", ios::out);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string line = "";
			line.append(presentDay.getpresentDay());
			f << line;
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
void ThuVien::readNgayFile() {
	try {
		// Khởi tại đối tượng File tên f
		ifstream f;
		// Mở file
		f.open("Daysetting.txt", ios::in);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string lineInfo = "";
			while (!f.eof()) {
				Ngay Daytemp;
				getline(f, lineInfo);
				Daytemp.setpresentDay(lineInfo);
			}
		}
		// Đóng file
		f.close();
		cout << "========================== CHAO MUNG BAN DANG NHAP VAO THU VIEN ==========================" << endl;
	}
	catch (exception e) {
		cout << "==== CHAO MUNG NGAY DAU TIEN VAO THU VIEN ====" << endl;
	}
	catch (...) {
		cout << "==== CHAO MUNG NGAY DAU TIEN VAO THU VIEN ====" << endl;
	}
	system("pause");
}
