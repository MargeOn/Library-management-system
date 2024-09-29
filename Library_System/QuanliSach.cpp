#include"QuanLiSach.h"
// Hàm khởi tạo hệ thống quản lí Sách
QuanliSach::QuanliSach() {
	fill(NumBooks, NumBooks + 17, 5);
}
// Hàm hủy hệ thống quản lí Sách
QuanliSach::~QuanliSach() {

}
// Phương thức lấy vị trí index của một phần tử trong mảng
Book QuanliSach::getBook(int pos) {
	return ListBooks[pos];
}
// Phương thức lấy kích thước sách trong mảng
int QuanliSach::size() {
	return ListBooks.size();
}
// Phương thức cộng thêm 1 quyển sách của đầu sách ở vị trí pos được lưu trong mảng NumBooks
void QuanliSach::addNum(int pos) {
	NumBooks[pos]++;
}
// Phương thức trừ đi 1 quyển sách của đầu sách ở vị trí pos được lưu trong mảng NumBooks
void QuanliSach::lessNum(int pos) {
	NumBooks[pos]--;
}
// Phương thức lấy kích thước trong mảng
int QuanliSach::sizeNum(int pos) {
	return NumBooks[pos];
}

void QuanliSach::writeBookFile() {
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
			// Đọc thông tin của tất cả các sách trong danh sách để ghi vào file
			for (int i = 0; i < ListBooks.size(); i++) {
				// ID Book
				string line = "ID:";
				line.append(to_string(ListBooks[i].get_ID()));
				// Tên sách
				line.append(",Name:");
				line.append(ListBooks[i].get_Name());
				// Tác giả sách
				line.append(",Author:");
				line.append(ListBooks[i].get_Author());
				// Thể loại sách
				line.append(",Genre:");
				line.append(ListBooks[i].get_Genre());
				line.append(",Year of Publication:");
				line.append(to_string(ListBooks[i].get_Year()));
				line.append(",State:");
				if (ListBooks[i].get_isAvailable() == 1) {
					line.append("Available");
				}
				else {
					line.append("Borrowed");
				}
				line.append(",Number:");
				line.append(to_string(NumBooks[i]));
				f << line;
				// Khi đưa thông tin người dùng vào mỗi dòng thì đều ghi vào cuối dòng trong file kí tự endl để xuống dòng
				// ngoại trừ dòng cuối cuối cùng(hay cũng là người dùng cuối cùng) thì không ghi endl.
				if (i != ListBooks.size() - 1) {
					f << endl;
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

void QuanliSach::readBookFile() {
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
				// Khởi tạo một vector tên dataLine để đọc dữ liệu của một hàng trong file và sẽ chia thành các chuỗi bởi kí 
				// tự ',' và đưa vào vector. Ta có được 6 chuỗi chứa 6 thông tin về ID, tên sách, tác giả, thể loại sách, năm xuất bản và trạng thái 
				vector<string> dataLine = explode(lineInfo, ',');
				// Kiểm tra nếu mảng vector dataLine có chứa 6 chuỗi đã được tách thì thực hiện câu lệnh if.
				if (dataLine.size() < 7) {
					throw "Thong tin cua sach bi loi nen khong the cap nhat vao thu vien!";
				}
				else if (dataLine.size() >= 7) {
					for (int i = 0; i < 7; i++) {
						// Lấy lần lượt 7 chuỗi thông tin ID, tên sách, tác giả, thể loại sách, năm xuất bản, trạng thái sách và số lượng mỗi đầu sách
						string bookStr = dataLine[i];
						// Chia chuỗi (trong mỗi 7 chuỗi) thành 2 chuỗi nữa
						vector<string> infoStr = explode(bookStr, ':');
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
								booktemp.set_Name(dataStr);
								break;
							}
							case 2: {
								booktemp.set_Author(dataStr);
								break;
							}
							case 3: {
								booktemp.set_Genre(dataStr);
								break;
							}
							case 4: {
								booktemp.set_Year(stoi(dataStr));
								break;
							}
							case 5: {
								if (dataStr == "Available") {
									booktemp.set_isAvailable(1);
								}
								else if (dataStr == "Borrowed") {
									booktemp.set_isAvailable(0);
								}
								break;
							}
							case 6: {
								Number = stoi(dataStr);
								break;
							}
							}
						}
					}
				}
				// Đưa đối tượng sách mới được khởi tạo vào danh sách quản lí sách
				ListBooks.push_back(booktemp);
				// Thêm số lượng đầu sách vào mảng
				for (int i = 0; i < ListBooks.size(); i++) {
					if (booktemp.get_ID() == ListBooks[i].get_ID()) {
						NumBooks[i] = Number;
					}
				}
			}
		}
		// Đóng file
		f.close();
		cout << "========================== DA TAI THANH CONG DANH SACH QUAN LI SACH TRONG FILE BOOKKSETTING ==========================" << endl;
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

// Sắp xếp danh sách quản lí sách
void QuanliSach::sortListbook(Type type) {
	switch (type)
	{
	case IDbook: {
		for (int i = 0; i < ListBooks.size(); ++i) {
			bool swapped = false;
			for (int j = 0; j < ListBooks.size() - i - 1; ++j) {
				if (ListBooks[j].get_ID() > ListBooks[j + 1].get_ID()) {
					swap(ListBooks[j], ListBooks[j + 1]);
					swapped = true;
				}
			}
			// Nếu không có sự hoán đổi nào xảy ra trong một vòng lặp, mảng đã được sắp xếp
			if (!swapped) {
				break;
			}
		}
		break; 
	}
	case Namebook: {
		for (int i = 0; i < ListBooks.size(); ++i) {
			bool swapped = false;
			for (int j = 0; j < ListBooks.size() - i - 1; ++j) {
				if (ListBooks[j].get_Name() > ListBooks[j + 1].get_Name()) {
					swap(ListBooks[j], ListBooks[j + 1]);
					swapped = true;
				}
			}
			// Nếu không có sự hoán đổi nào xảy ra trong một vòng lặp, mảng đã được sắp xếp
			if (!swapped) {
				break;
			}
		}
		break;
	}
	case Author: {
		for (int i = 0; i < ListBooks.size(); ++i) {
			bool swapped = false;
			for (int j = 0; j < ListBooks.size() - i - 1; ++j) {
				if (ListBooks[j].get_Author() > ListBooks[j + 1].get_Author()) {
					swap(ListBooks[j], ListBooks[j + 1]);
					swapped = true;
				}
			}
			// Nếu không có sự hoán đổi nào xảy ra trong một vòng lặp, mảng đã được sắp xếp
			if (!swapped) {
				break;
			}
		}
		break;
	}
	}
	
}

// Hàm chuyển chuỗi chữ hoa sang chữ thường
string QuanliSach::lowerString(string data) {
	for (int i = 0; i < data.size(); i++) {
		data[i] = tolower(data[i]);
	}
	return data;
}

// Tìm kiếm nhị phân theo tác giả, tên sách
int QuanliSach::BinSearch(Type type, string str) {
	// Khi nhập tên sách, tác giả là chữ cái hoa hoặc thường thì đều có thể tìm kiếm được 
	switch (type)
	{
	case Namebook:
	{
		int l = 0, r = ListBooks.size() - 1;
		// Đặt điều kiện l < r để khi l = r là lúc tìm đến phần tử x cần tìm đầu tiên
		while (l < r) {
			// Nếu l < r thì tìm phần tử ở giữa 
			int m = (l + r) / 2;
			// Nếu giá trị phần tử ở giữa nhỏ hơn giá trị cần tìm là x thì gán biến l cho đoạn nửa cuối là m + 1 (không xét m) 
			if (lowerString(ListBooks[m].get_Name()) < lowerString(str)) {
				l = m + 1;
			}
			// Nếu giá trị phần tử ở giữa lớn hơn hoặc bằng giá trị cần tìm là x thì gán biến r = m cho đoạn nửa đầu(xét m)
			else {
				r = m;
			}
		}
		// Khi l = r là lúc ta có thể so sánh giá trị a[l] có bằng x hay không. Nếu có thì trả về vị trí l
		if (lowerString(ListBooks[l].get_Name()) == lowerString(str)) {
			return l;
		}
		// Nếu sai thì trả về -1
		return -1;
	}
	case Author: {
		int l = 0, r = ListBooks.size() - 1;
		// Đặt điều kiện l < r để khi l = r là lúc tìm đến phần tử x cần tìm đầu tiên
		while (l < r) {
			// Nếu l < r thì tìm phần tử ở giữa 
			int m = (l + r) / 2;
			// Nếu giá trị phần tử ở giữa nhỏ hơn giá trị cần tìm là x thì gán biến l cho đoạn nửa cuối là m + 1 (không xét m) 
			if (lowerString(ListBooks[m].get_Author()) < lowerString(str)) {
				l = m + 1;
			}
			// Nếu giá trị phần tử ở giữa lớn hơn hoặc bằng giá trị cần tìm là x thì gán biến r = m cho đoạn nửa đầu(xét m)
			else {
				r = m;
			}
		}
		// Khi l = r là lúc ta có thể so sánh giá trị a[l] có bằng x hay không. Nếu có thì trả về vị trí l
		if (lowerString(ListBooks[l].get_Author()) == lowerString(str)) {
			return l;
		}
		// Nếu sai thì trả về -1
		return -1; 
	}
	default:
		break;
	}
}