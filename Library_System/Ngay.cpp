#include"Ngay.h"
// Hàm khởi tạo đối tượng Book
Ngay::Ngay() {
	this->day = "0/0/2024";
}
// Hàm lấy ngày tháng hiện tại của thư viện
string Ngay::getpresentDay() {
	return this->day;
}
// Hàm gán ngày tháng hiện tại của thư viện
void Ngay::setpresentDay(string presentDay) {
	int dayPresent = 0, monthPresent = 0;
	// Tách chuỗi và lấy được ngày tháng hiện tại của thư viện
	vector<string> temp1 = explode(presentDay, '/');
	dayPresent = stoi(temp1[0]);
	monthPresent = stoi(temp1[1]);
	presentDay = to_string(dayPresent) + "/" + to_string(monthPresent) + "/2024";
	this->day = presentDay;
}
// Hàm kiểm tra quá trình nhập ngày hiện tại có phải là quá khứ của ngày trước đó mà thư viện lưu ở file không
bool Ngay::isPastDay(const string& ngaythangnam) {
	int dayPast = 0, monthPast = 0, dayPresent = 0, monthPresent = 0;
	// Tách chuỗi và lấy được ngày tháng hiện tại của thư viện
	vector<string> temp1 = explode(ngaythangnam, '/');
	dayPresent = stoi(temp1[0]);
	monthPresent = stoi(temp1[1]);
	// Tách chuỗi và lấy được ngày tháng quá khứ của thư viện
	vector<string> temp2 = explode(this->day, '/');
	dayPast = stoi(temp2[0]);
	monthPast = stoi(temp2[1]);
	if (monthPresent > monthPast) {
		this->day = ngaythangnam;
		return true;
	}
	else if (monthPresent == monthPast) {
		if (dayPresent >= dayPast) {
			this->day = ngaythangnam;
			return true;
		}
	}
	return false;
}
// Hàm kiểm tra nhập ngày hiện tại có đúng với ngày tháng năm thực tế hay không
bool Ngay::checkvalidDay(const string& ngaythangnam) {
	int dayPast = 0, monthPast = 0, dayPresent = 0, monthPresent = 0;
	// Tách chuỗi và lấy được ngày tháng hiện tại của thư viện
	vector<string> temp = explode(ngaythangnam, '/');
	dayPresent = stoi(temp[0]);
	monthPresent = stoi(temp[1]);
	if (monthPresent >= 1 && monthPresent <= 12) {
		if (dayPresent >= 1 && dayPresent <= returndaysPerMonth(monthPresent)) {
			return true;
		}
	}
	return false;
}