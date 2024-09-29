#include"ValidData.h"

int returndaysPerMonth(int month) {
	switch (month) {
	case 1:
		return 31;
		// Năm 2024 là năm nhuận, nên tháng 2 có 29 ngày
	case 2:
		return 29;
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		return 31;
	default:
		return -1;
	}
}

// Kiểm tra hợp lệ lựa chọn có tiếp tục nhập xe hay không.
bool isValidCharacter(string c) {
	// Lựa chọn phải là 'y' hoặc 'n'
	regex pattern("^[yn]$");
	// Chuyển đổi ký tự thành chuỗi và kiểm tra xem chuỗi có khớp với mẫu regex hay không
	return regex_match(c, pattern);
}

// Tách chuỗi thông tin FILE.txt
const vector<string> explode(const string& s, const char& c)
{
	// Khởi tạo một chuỗi trống tên là buff 
	string buff = "";
	// Khai báo một vector v kiểu string
	vector<string> v;
	// Duyệt  lần lượt các kí tự trong mảng tên s kiểu string
	for (auto n : s)
	{
		// Nếu kí tự n đó không phải là kí tự mà người dùng định nghĩa để cắt chuỗi
		// Khi duyệt qua chuỗi thứ nhất và kí tự cắt
		if (n != c)
			// Thì kí tự n duyệt qua trong mảng s sẽ được đưa vào mảng buff, ngầm hiểu là chuỗi thứ nhất
			// Thì kí tự n duyệt qua trong mảng s sẽ được đưa vào mảng buff, ngầm hiểu là chuỗi thứ hai
			buff += n;
		// Nếu kí tự n là kí tự mà người dùng định nghĩa để cắt chuỗi và buff không là một chuỗi trống
		// Khi duyệt qua chuỗi thứ nhất và kí tự cắt, nó sẽ không gặp kí tự cắt nữa nên bỏ qua câu else if này
		else if (n == c && buff != "")
		{
			// Thì đưa phần tử buff vào vector v. Lúc này, vector v chứa chuỗi đầu tiên mà ta cần lấy
			v.push_back(buff);
			// Và gán mảng kí tự buff là chuỗi trống. 
			buff = "";
		}
	}
	// Khi chuỗi buff không là một chuỗi trống và hiện tại đang chứa chuỗi thứ hai của file
	if (buff != "")
		// Thì thêm chuỗi thứ hai vào vector v
		v.push_back(buff);
	// Trả về vector v
	return v;
}

// Định nghĩa hàm kiểm tra nhập hợp lệ  của các lựa chọn 
bool Regrex(Type type, string input) {
	switch (type)
	{
		// Kiểm tra nhập lựa chọn Menu chính có hợp lệ không
	case MenuSelect1:
	{
		// Số hợp lệ là số từ 1 đến 7
		regex pattern("^[1-7]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn Menu mượn sách có hợp lệ không
	case MenuBorrowed:
	{
		// Số hợp lệ là số từ 1 đến 2
		regex pattern("^[1-2]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn Menu trả sách có hợp lệ không
	case MenuReturn:
	{
		// Số hợp lệ là số từ 1 đến 2
		regex pattern("^[1-2]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn Menu tìm kiếm có hợp lệ không
	case MenuSearch:
	{
		// Số hợp lệ là số từ 1 đến 4
		regex pattern("^[1-4]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn Menu xuất có hợp lệ không
	case MenuOut:
	{
		// Số hợp lệ là số từ 1 đến 3
		regex pattern("^[1-3]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập tên người dùng, kiểm tra rằng tên người dùng có hợp lệ chưa.
	case Name:
	{
		// Tên hợp lệ là tên có 2 từ trở lên và các từ phải có 2 chữ cái trở lên
		regex pattern("^[A-Za-z]{2,}(\\s[A-Za-z]{2,})+$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập tài khoản gmail của người dùng, kiểm tra rằng thông tin có hợp lệ chưa.
	case Email:
	{
		// Email hợp lệ là email có định dạng "abc@xyz.def"
		regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu ID code của người dùng, kiểm tra rằng thông tin có hợp lệ chưa.
	case Key:
	{
		// Mã số cá nhân hợp lệ là mã số cá nhân có số có đủ chữ số
		regex pattern("^[0-9][0-9]{7}$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập số phone number của người dùng, kiểm tra rằng thông tin có hợp lệ chưa.
	case Phone:
	{
		regex pattern("^[0-9][0-9]{7}$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn sách trong danh sách lưu trữ sách
	case BOOK:
	{
		// Số hợp lệ là số từ 1 đến 17
		regex pattern("^(1[0-7]|[1-9])$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn xuất theo tên sách
	case Namebook:
	{
		// Tên sách có thể là một số(không phải là các số) hoặc là chữ cái có 2 từ trở lên
		regex pattern("^(?:[a-zA-Z0-9]+(?: [a-zA-Z0-9]+)*|\d+)$");
		//regex pattern("^\d+$|^([A-Za-z]+\s+){1,}[A-Za-z]+$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn xuất thể loại sách
	case Sgenre:
	{
		// Số hợp lệ là số từ 1 đến 6
		regex pattern("^[1-6]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn ngày tháng năm hiện tại trong thư viện
	case Ngaythangnam:
	{
		// Số hợp lệ là số từ 1 đến 6
		regex pattern("^(0?[0-9]|[1-9][0-9])/(0?[1-9]|[1-9][0-9])/2024$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu không kiểm tra các trường hợp trên thì thông báo chưa kiểm tra regrex và trả về false
	default:
		cout << "He thong chua kiem tra hop le";
		system("pause");
		return false;
	}
}

