#pragma once
#include <iostream>	
#include <string>

using namespace std;

class CalculateOverDue
{
public:
	CalculateOverDue();
	~CalculateOverDue();
	int calculateOverDueDay(const string& currentDay, const string& borrowDay);
};

