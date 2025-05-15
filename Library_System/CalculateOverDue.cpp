#include "CalculateOverDue.h"
#include <ctime>
#include "ValidData.h"
	
CalculateOverDue::CalculateOverDue(){
}

CalculateOverDue::~CalculateOverDue() {

}

int CalculateOverDue::calculateOverDueDay(const string& currentDay, const string& borrowDay) {
    std::tm borrow = {}, current = {};

    // Đọc ngày dạng "dd/mm/yyyy" và lưu vào struct tm
    sscanf_s(borrowDay.c_str(), "%d/%d/%d", &borrow.tm_mday, &borrow.tm_mon, &borrow.tm_year);
    sscanf_s(currentDay.c_str(), "%d/%d/%d", &current.tm_mday, &current.tm_mon, &current.tm_year);

    // Điều chỉnh vì struct tm yêu cầu:
    // - tm_year là số năm tính từ 1900
    // - tm_mon là số tháng từ 0 đến 11
    borrow.tm_year -= 1900;
    borrow.tm_mon -= 1;

    current.tm_year -= 1900;
    current.tm_mon -= 1;

    // Chuyển struct tm thành time_t (số giây từ 1/1/1970)
    time_t t_borrow = std::mktime(&borrow);
    time_t t_current = std::mktime(&current);

    // Tính số ngày chênh lệch
    double seconds = std::difftime(t_current, t_borrow);
    int days = seconds / (60 * 60 * 24); // chuyển giây thành ngày

    return days;

}

