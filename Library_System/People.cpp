#include"People.h"

// Hàm khởi tạo đối tượng Book
People::People() {
	id = 0;
	name = "";
	email = "";
	phoneNumber = 0;
}
// Hàm hủy đối tượng Book
People::~People() {

}
// Hàm nhập thông tin của người dùng khi yêu cầu nhập 
void People::Nhap_thongtinPeople() {
	string id;
	string phonenumber;
	do
	{
		cout << "ID: ";
		getline(cin, id);
		if (!Regrex(Key, id))
		{
			cout << "\nID cua nguoi dung phai la so co du 8 chu so! " << endl;
			system("pause");
		}
		else {
			this->id = stoi(id);
		}
	} while (!Regrex(Key, id));
	do
	{
		cout << "Ten nguoi dung: ";
		getline(cin, this->name);
		if (!Regrex(Name, this->name))
		{
			cout << "\nTen nguoi dung khong phu hop hoac phai day du ho va ten! " << endl;
			system("pause");
		}
	} while (!Regrex(Name, this->name));
	do
	{
		cout << "Email: ";
		getline(cin, this->email);
		if (!Regrex(Email, this->email))
		{
			cout << "\nTen email phai la dinh dang email@abc.xyz ! " << endl;
			system("pause");
		}
	} while (!Regrex(Email, this->email));
	do
	{
		cout << "Phone number: ";
		getline(cin, phonenumber);
		if (!Regrex(Phone, phonenumber))
		{
			cout << "\nMa so ca nhan phai la 1 so co du 8 chu so! " << endl;
			system("pause");
		}
		else {
			this->phoneNumber = stoi(phonenumber);
		}
	} while (!Regrex(Phone, phonenumber));
}
// Hàm xuất thông tin mỗi người dùng
void People::Xuat_thongtinPeople() {
	cout << setw(20) << this->name
		<< setw(10) << this->id
		<< setw(25) << this->email
		<< setw(10) << this->phoneNumber;
}