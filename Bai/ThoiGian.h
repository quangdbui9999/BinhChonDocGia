#ifndef _THOI_GIAN_H_
#define _THOI_GIAN_H_

#include <iostream>
using namespace std;

class ThoiGian
{
private:
	int gio;
	int phut;
	int giay;
public:
	ThoiGian(void);
	void DoiGio(int x);
	void DoiPhut(int x);
	void DoiGiay(int x);
	void NhapThoiGian();
	void XuatThoiGian();
	~ThoiGian(void);
};
#endif