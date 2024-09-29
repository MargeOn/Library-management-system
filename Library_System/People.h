#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"ValidData.h"

using namespace std;

class People
{
public:
	// Hàm khởi tạo đối tượng People
	People();
	// Hàm hủy đối tượng People
	~People();
	// Hàm nhập và xuất thông tin của People
	void Nhap_thongtinPeople();
	void Xuat_thongtinPeople();
protected:
	int id;
	string name;
	string email;
	int phoneNumber;
};