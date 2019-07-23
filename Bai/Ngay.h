#ifndef _NGAY_H_
#define _NGAY_H_

#include <iostream>
using namespace std;
#include "ThoiGian.h"

class Ngay
{
private:
	int ngay;
	int thang;
	int nam;
public:
	Ngay(void);
	Ngay(int year);
	Ngay(int year, int month);
	Ngay(int year, int month, int day);
	Ngay(const Ngay &date);
	Ngay& operator=(const Ngay &date);
	int KiemTraNam();
	int KiemTraThang();
	int KiemTraNgay();
	void NhapNgay();
	void XuatNgay();
	void DoiNgay(int);
	void DoiThang(int);
	void DoiNam(int);
	~Ngay(void);
};
#endif